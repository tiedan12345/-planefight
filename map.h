#ifndef MAP_H
#define MAP_H
#include <QPixmap>

class Map
{
public:

    //构造函数
    Map();

    //地图滚动坐标计算
    void mapPosition();

    //要让地图滚动起来，将两张地图叠加起来
    //插入地图图片对象
    QPixmap m_map1;
    QPixmap m_map2;

    //地图y轴坐标
    int m_map1_posY;
    int m_map2_posY;

    //地图滚动幅度
    int m_scroll_speed;
};

#endif // MAP_H
