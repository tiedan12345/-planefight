#include "mainscene.h"
#include "ui_mainscene.h"
#include "config.h"
#include <QIcon>

MainScene::MainScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);
    initScene();
}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::initScene()
{
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon(GAME_ICON));
}
