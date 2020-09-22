#include "mainscene.h"
#include "ui_mainscene.h"
#include "config.h"
#include <QIcon>
#include <QPainter>
#include <QMouseEvent>
#include <ctime>
#include <QPushButton>
#include <QPixmap>

MainScene::MainScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //设置界面大小
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置界面标题
    setWindowTitle(GAME_TITLE);

    //设置界面小飞机
    //注意加上#include<QIcon>
    setWindowIcon(QIcon(GAME_ICON));

    //设置按钮
    QPushButton *btn = new QPushButton;
    QPushButton *btn2 = new QPushButton;
    QPushButton *rbutton = new QPushButton;
    rbutton->setText("返回");
    rbutton->move(500,600);

    btn->setParent(this);
    btn2->setParent(this);
    btn->setText("quit");
    btn2->setText("start");
    btn2->move(900,530);
    connect(btn,&QPushButton::clicked,this,&MainScene::close);
    connect(rbutton,&QPushButton::clicked,this,&MainScene::sendslot);
    connect(btn2,&QPushButton::clicked,this,&MainScene::initScene);
}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::sendslot()
{
    emit Mysignal();//发送信号
}

void MainScene::initScene()
{
    //初始化界面标题
    setWindowTitle(GAME_TITLE);

    //设置小飞机
    setWindowIcon(QIcon(GAME_ICON));

    //设置定时器间隔
    m_Timer.setInterval(GAME_RATE);

    //调用启动游戏的接口，实现地图滚动
    playGame();
    //敌机出场纪录初始化
    m_recorder=0;
    //随机数种子
    srand((unsigned int)time(NULL));
}

void MainScene::start()
{
    QPainter painter(this);
     painter.drawPixmap(0,0,1000,562,QPixmap(MAP_PATH));

}


void MainScene::playGame()
{
    //玩游戏，启动定时器
    m_Timer.start();

    //每隔10毫秒发送一个信号
    //监听这个信号，利用信号槽
    //用[=](){表达式捕获这个信号
    connect(&m_Timer,&QTimer::timeout,[=](){

    //更新游戏中所有元素的坐标
    updatePosition();
    //游戏中的元素绘制到屏幕中
    //用update函数调用paintEvent函数
    update();
    //敌机显示
    enemytoscene();
    //调用碰撞检测函数
    collisionDetection();

    });
}

void MainScene::updatePosition()
{
    //更新地图坐标
    m_map.mapPosition();
    m_hero.shoot();
    //计算子弹坐标
    for(int i=0;i<BULLET_NUM;i++)
    {
        //如果子弹状态为非空闲，计算发射位置
        if(m_hero.m_bullets[i].m_free==false)
        {
          m_hero.m_bullets[i].updatePosition();
        }
    }
    for(int i = 0 ; i< ENEMY_NUM;i++)
    {
        //非空闲敌机,更新坐标
        if(m_enemys[i].m_free == false)
        {
            m_enemys[i].updatePosition();
        }
     }
    //计算爆炸播放的图片
    for(int i=0 ; i<BOMB_NUM;i++)
    {
        if(m_bombs[i].m_Free==false)
        {
            m_bombs[i].updateInfo();
        }
    }

}

void MainScene::paintEvent(QPaintEvent * event)
{
    //利用画家画图片
    QPainter painter(this);

    //绘制地图(x,y,对象)
    painter.drawPixmap(0,m_map.m_map1_posY,m_map.m_map1);
    painter.drawPixmap(0,m_map.m_map2_posY,m_map.m_map2);


    //绘制飞机(x,y,对象)
    painter.drawPixmap(m_hero.m_X,m_hero.m_Y,m_hero.m_Plane);
    //绘制子弹
    for(int i=0;i<BULLET_NUM;i++)
    {
        //如果子弹状态为非空闲，绘制图片
        if(m_hero.m_bullets[i].m_free==false)
          painter.drawPixmap(m_hero.m_bullets[i].m_X,m_hero.m_bullets[i].m_Y,m_hero.m_bullets[i].m_bullet);
    }
    //绘制敌机
    for(int i = 0 ; i< ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_free == false)
        {
          painter.drawPixmap(m_enemys[i].m_X,m_enemys[i].m_Y,m_enemys[i].m_enemy);
        }
    }
    for(int i = 0 ;i < BULLET_NUM;i++)
    {
        //如果子弹状态为非空闲，计算发射位置
        if(!m_hero.m_bullets[i].m_free)
        {
           painter.drawPixmap(m_hero.m_bullets[i].m_X,m_hero.m_bullets[i].m_Y,m_hero.m_bullets[i].m_bullet);
        }
    }
    //绘制爆炸图片
    for(int i=0 ; i<BOMB_NUM;i++)
    {
        if(m_bombs[i].m_Free==false)
        {
            painter.drawPixmap(m_bombs[i].m_X,m_bombs[i].m_Y,m_bombs[i].m_pixArr[m_bombs[i].m_index]);
        }
    }


}

//捕获的有关鼠标的信息都在event中可以找得到
void MainScene::mouseMoveEvent(QMouseEvent * event)
{
    int x = event->x()-m_hero.m_Rect.width()*0.5;
    int y = event->y()-m_hero.m_Rect.height()*0.5;

    //边界检测，防止飞机超出边界
    if(x<=0)
        x=0;
    if(x>=GAME_WIDTH - m_hero.m_Rect.width())
        x=GAME_WIDTH - m_hero.m_Rect.width();
    if(y<=0)
        y=0;
    if(y>=GAME_HEIGHT - m_hero.m_Rect.height())
        y=GAME_HEIGHT - m_hero.m_Rect.height();

    //将鼠标移动的坐标放进去，实现飞机拖拽
    m_hero.setPosition(x,y);
}
void MainScene::enemytoscene()
{
    //累加出场间隔
    m_recorder++;
    //没有到出场间隔就直接return，到了就归零
    if(m_recorder<ENEMY_INTERVAL)
        return;
    m_recorder=0;
    for(int i=0;i<ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_free)
        {
            //敌机空闲状态改为非空闲，发出去
            m_enemys[i].m_free = false;
            //设置坐标
            m_enemys[i].m_X = rand() % (GAME_WIDTH - m_enemys[i].m_Rect.width());
            m_enemys[i].m_Y = -m_enemys[i].m_Rect.height();
            break;
         }
        //播放爆炸效果
        for(int k=0 ; k<BOMB_NUM;k++)
        {
            if(m_bombs[k].m_Free)
            {
                //爆炸状态设置为非空闲
                m_bombs[k].m_Free=false;
                //更新坐标
                m_bombs[k].m_X=m_enemys[i].m_X;
                m_bombs[k].m_Y=m_enemys[i].m_Y;
                break;
            }
        }
    }

}

void MainScene::collisionDetection()
{
    //遍历所有非空闲的敌机
    for(int i=0 ;i<ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_free)
        {
                //空闲飞机跳转下一次循环
            continue;
        }
                //遍历所有非空闲的子弹
        for(int j=0 ; j<BULLET_NUM;j++)
        {
                if(m_hero.m_bullets[j].m_free)
            {
                //空闲子弹跳转下一次循环
                continue;
            }
                //如果子弹矩形框和敌机矩形框相交，发生碰撞，同时变为空闲状态即可，就不会显示在屏幕中
                //intersects相交函数
            if(m_enemys[i].m_Rect.intersects(m_hero.m_bullets[j].m_rect))
            {
                m_enemys[i].m_free=true;
                m_hero.m_bullets[j].m_free=true;
                //播放爆炸特效
                for(int k=0 ; k < BOMB_NUM;k++)
                {
                   if( m_bombs[k].m_Free)
                   {
                       m_bombs[k].m_Free=false;
                       //更新坐标
                       m_bombs[k].m_X=m_enemys[i].m_X;
                       m_bombs[k].m_Y=m_enemys[i].m_Y;
                       break;
                   }
                }
            }
        }
    }

}
