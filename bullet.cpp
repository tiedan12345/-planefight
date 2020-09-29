#include "bullet.h"

bullet::bullet()
{
   //加载子弹图片
   m_bullet.load(BULLET_PATH);
   m_X=GAME_WIDTH/2 - m_bullet.width()/2;
   m_Y=GAME_HEIGHT;

   //子弹状态->空闲
   m_free=true;

   //子弹速度
   m_speed=BULLET_SPEED;

   //设置子弹矩形边框（用于碰撞检测）
   m_rect.setWidth(m_bullet.width());
   m_rect.setHeight(m_bullet.height());
   m_rect.moveTo(m_X,m_Y);
}

void bullet::updatePosition()
{
    //如果子弹是空闲状态，不需要计算坐标
    //可以直接return;
    if(m_free)
        return;

    //y轴上改变，子弹向上移动
    m_Y=m_Y-m_speed;
    m_rect.moveTo(m_X,m_Y);

    //当子弹超出界面，且超出距离小于等于子弹高度
    //子弹空闲
    if(m_Y<=-m_rect.height())
        m_free=true;

}
