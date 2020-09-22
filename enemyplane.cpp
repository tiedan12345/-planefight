#include "enemyplane.h"
#include"config.h"

enemyplane::enemyplane()
{
    //敌机资源加载
   m_enemy.load(ENEMY_PATH);
   //敌机位置
    m_X=0;
    m_Y=0;
    //敌机状态（空闲）
    m_free=true;
    //敌机速度
    m_speed=ENEMY_SPEED;
    //敌机的检测范围
    //设置宽
    m_Rect.setWidth(m_enemy.width());
    //设置高
    m_Rect.setHeight(m_enemy.height());
    //移动矩形
    m_Rect.moveTo(m_X,m_Y);

}
void enemyplane::updatePosition()
{
    //敌机空闲，不计算坐标
    if(m_free)
        return;

    //敌机从上往下走，y轴上一直加
    //边框也随之移动
    m_Y=m_Y+m_speed;
    m_Rect.moveTo(m_X,m_Y);

    if(m_Y>=GAME_HEIGHT)
        m_free=true;
}
