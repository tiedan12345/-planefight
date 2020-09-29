#ifndef BULLET_H
#define BULLET_H
#include"config.h"
#include<QPixmap>

class bullet
{
public:
    bullet();
    //更新子弹坐标
    void updatePosition();

public:
    QPixmap m_bullet;
    //子弹坐标
    int m_X;int m_Y;
    //子弹发射速度
    int m_speed;

    //子弹状态
    bool m_free;

    //划定矩形范围
    QRect m_rect;

};

#endif // BULLET_H
