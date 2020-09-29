#include "heroplane.h"
#include"config.h"

Heroplane::Heroplane()
{
   //加载飞机图片
   m_Plane.load(HERO_PATH);

   //初始化坐标（屏幕-飞机）
   //m_Y中的-20->图片效果好
   m_X=GAME_WIDTH/2 - m_Plane.width()/2;
   m_Y=GAME_HEIGHT - m_Plane.height()-20;

   //划定矩形框范围，碰撞检测
   m_Rect.setWidth(m_Plane.width());
   m_Rect.setHeight(m_Plane.height());
   //小框框移动位置
   m_Rect.moveTo(m_X,m_Y);

   //初始化间隔记录变量
   m_recorder=0;
}

void Heroplane::shoot()
{
    //累加时间间隔记录
    m_recorder++;
    //时间记录没达到发射间隔->return
    if(m_recorder<BULLET_INTERVAL)
        return;//不发射，return掉

    //之后的子弹可以发射
    for(int i=0;i<BULLET_NUM;i++)
    {
        //找出空闲的子弹，先上膛
        if(m_bullets[i].m_free)
        {
           m_bullets[i].m_free =false;
           //数据10,30经过多次调试而来，画面最美观
           m_bullets[i].m_X=m_X+m_Rect.width()*0.5-10;
           m_bullets[i].m_Y=m_Y-30;
           break;//保证每次就发一颗子
        }
     }
    m_recorder=0;//重置，下次还要数数
}

void Heroplane::setPosition(int x, int y)
{
    m_X = x;
    m_Y = y;
    m_Rect.moveTo(m_X,m_Y);
}
