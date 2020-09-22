#ifndef HEROPLANE_H
#define HEROPLANE_H
#include<QPixmap>
#include"bullet.h"
#include"config.h"

class Heroplane
{
public:
    Heroplane();
    //发射子弹
    void shoot();
    //设置飞机位置,鼠标拖拽
    void setPosition(int x,int y);

    void getHp()const;

public:
    //飞机对象
    QPixmap m_Plane;
    //飞机坐标
    int m_X,m_Y;
    //飞机的矩形边框，用于碰撞检测
    QRect m_Rect;

    bullet m_bullets[BULLET_NUM];
    int m_recorder;
    int hp= HERO_HP;
};

#endif // HEROPLANE_H
