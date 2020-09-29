#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H
#include <QPixmap>

class enemyplane
{
public:
    enemyplane();
    //更新坐标
    void updatePosition();
public:
    //敌机资源对象
    QPixmap m_enemy;
    //位置
    int m_X;
    int m_Y;
    //敌机的矩形边框，用于检测碰撞
    QRect m_Rect;
    //敌机状态（出场为非空闲，若被打死或飞出屏幕，则变为空闲状态）
    bool m_free;
    //敌机飞行速度
    int m_speed;
};

#endif // ENEMYPLANE_H
