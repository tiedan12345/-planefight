#ifndef MAINSCENE_H
#define MAINSCENE_H
#include<QMainWindow>
#include <QWidget>
#include <QTimer> //<QTimer>类
#include "map.h"  //包含map头文件
#include "heroplane.h" //飞机的类先引用过来
#include "bullet.h"
#include "enemyplane.h"
#include "bomb.h"

namespace Ui {
class MainScene;
}

class MainScene : public QWidget
{
    Q_OBJECT

public:
    explicit MainScene(QWidget *parent = nullptr);
    ~MainScene();

    //初始化场景
    void initScene();

    //发送信号槽函数
    void sendslot();
    void start();

    //要让地图跑起来就要加一个定时器
    QTimer m_Timer;
    //启动游戏，就是让定时器跑起来
    void playGame();
    //更新坐标
    void updatePosition();
    //绘制图片（paintEvent事件）
    void paintEvent(QPaintEvent*event);
    //创建地图对象
    Map m_map;


    //重写鼠标移动事件
    void mouseMoveEvent(QMouseEvent *);

    //创建飞机对象
    Heroplane m_hero;
    //定时器对象
    QTimer m_timer;
    //敌机出场
    void enemytoscene();
    //敌机数组
    enemyplane m_enemys[ENEMY_NUM];
    //敌机出场纪录
    int m_recorder;
    //碰撞检测
    void collisionDetection();
    //爆炸数组
    bomb m_bombs[BOMB_NUM];

private slots:
    void on_pushButton_clicked();

signals:
    //信号必须有signals关键字来声明
    //信号无返回值，可以有参数
    void Mysignal();//返回信号

private:
    Ui::MainScene *ui;
};

#endif // MAINSCENE_H
