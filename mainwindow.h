#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QPushButton>
#include<mainscene.h> //子窗口头文件
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void dealmainscene();//处理子窗口（槽函数）

private:
    Ui::MainWindow *ui;

    //设置按钮
    QPushButton *button1;
    QPushButton *rbutton;

    //声明子窗口
    MainScene w2;

    //绘图函数，用来设置主界面背景
    void paintEvent(QPaintEvent *event);

private slots:
    void showMainscene();//显示子界面（槽函数）
};

#endif // MAINWINDOW_H
