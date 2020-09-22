#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QPixmap>
#include<QLabel>
#include<QIcon>
#include<QPalette>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置界面标题
    setWindowTitle("飞机大战");
    //添加小飞机图标
    setWindowIcon(QIcon(MAIN_ICON));
    //设置主界面大小
    setFixedSize(500,650);

    //创建按钮
    button1=new QPushButton(this);
    button1->setText("一起开心玩耍 ❤");
    setAutoFillBackground(true);

    //设置按钮样式
    QPalette pe;
    //设置按钮上的字体颜色
    pe.setColor(QPalette::ButtonText,Qt::red);
    button1->setPalette(pe);
    //设置按钮填充颜色
    button1->setStyleSheet("background-color:black");
    //设置按钮大小
    button1->setGeometry(150,430,200,68);

    //建立联系，链接信号与槽函数
    connect(button1,SIGNAL(clicked()),this,SLOT(showMainscene()));

    //&MainScene::Mysignal 处理子窗口信号，发送者与槽函数
    //&MainWindow::dealmainscene 接受者与槽函数
    //处理子窗口的信号
    connect(&w2,&MainScene::Mysignal,this,&MainWindow::dealmainscene);
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::dealmainscene()
{
    w2.hide();//子窗口隐藏

}

void MainWindow::showMainscene()
{
    w2.show();//子窗口显示
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    //设置背景图片
    painter.drawPixmap(0,0,500,500,QPixmap(":/res/happy.jpg"));
    painter.drawPixmap(0,500,500,150,QPixmap(":/res/img_bg_level_6.jpg"));

    //防止图片变形
    painter.setRenderHint(QPainter::Antialiasing,true);


}
