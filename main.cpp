#include "mainwindow.h"
#include <QApplication>
#include <QResource>
#include "config.h" //配置文件
#include <QSoundEffect>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //将qrc文件转成rcc文件，将内存缩小
    //注册外部的二进制资源文件
    QResource::registerResource(GAME_RES_PATH);
    //注意在工程文件中删除res.qrc的代码
    //启动背景音乐
    QSoundEffect effect;
    //导入背景音乐资源
    effect.setSource(QUrl::fromLocalFile(SOUND_BACKGROUND));
    //设置为循环播放
    effect.setLoopCount(QSoundEffect::Infinite);
    //播放音乐
    effect.play();

    MainWindow w;
    w.show();

    return a.exec();
}
