#include "map.h"
#include "config.h"

Map::Map()
{
    //在构造函数中将图片加载进去
    m_map1.load(MAP_PATH);
    m_map2.load(MAP_PATH);

    //设置地图其实y轴坐标
    //第一张图片的起始位置在界面的上面，所以y轴上是负数
    //第二张图片起始位置在界面的顶点->0
    m_map1_posY=-GAME_HEIGHT;
    m_map2_posY=0;

    //设置滚动速度
    m_scroll_speed=MAP_SCROLL_SPEED;

}

//实现图片的滚动
void Map::mapPosition()
{
    //处理第一张图片滚动
    m_map1_posY+=MAP_SCROLL_SPEED;

    //第一张图片一移动到界面的上侧边沿
    //就立马恢复到起始位置->-GAME_HEIGHT
    if(m_map1_posY>=0)
    {
        m_map1_posY=-GAME_HEIGHT;
    }


    //处理第二张图片滚动
    m_map2_posY+=MAP_SCROLL_SPEED;
    //第二张图片一移动到界面的底部
    //就立马恢复到起始位置->0
    if(m_map2_posY>=GAME_HEIGHT )
    {
        m_map2_posY=0;
    }

}
