#include "bullet.h"

bullet::bullet()
{
   //加载子弹图片
   m_bullet.load(BULLET_PATH);
   m_X=GAME_WIDTH/2 - m_bullet.width()/2;
   m_Y=GAME_HEIGHT;
   //子弹状态
   m_free=true;
   //子弹速度
   m_speed=BULLET_SPEED;
   m_rect.setWidth(m_bullet.width());
   m_rect.setHeight(m_bullet.height());
   m_rect.moveTo(m_X,m_Y);
}
void bullet::updatePosition()
{
    if(m_free)
        return;
    m_Y=m_Y-m_speed;
    m_rect.moveTo(m_X,m_Y);
    if(m_Y<=-m_rect.height())
        m_free=true;

}//zxd
