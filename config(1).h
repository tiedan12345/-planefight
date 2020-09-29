#ifndef CONFIG_H
#define CONFIG_H

#define GAME_WIDTH 1000 //宽度，根据背景图片的大小
#define GAME_HEIGHT 562 //长度
#define GAME_TITLE "飞机大战 v1.0" //标题


//注册二进制文件，加上资源路径
//":+前缀名+文件路径"
#define GAME_RES_PATH "./plane.rcc"
#define GAME_ICON ":/res/app.ico"
#define MAIN_ICON ":/res/app.ico"

//设置地图图片路径
#define MAP_PATH ":/res/img_bg_level_6.jpg"
//设置地图滚动速度
#define MAP_SCROLL_SPEED 1
//帧率，每10毫秒做一个滚动
#define GAME_RATE 10

//英雄飞机的图片资源
#define HERO_PATH ":/res/hero2.png"

#define BULLET_PATH ":/res/bullet_10.png"
#define BULLET_SPEED 5
#define BULLET_NUM 30 //子弹数目
#define BULLET_INTERVAL 20 //发射子弹的间隔，10*20毫秒发送一颗子弹


#define ENEMY_PATH ":/res/img-plane_6.png"
#define ENEMY_SPEED 2//敌机移动速度
#define ENEMY_NUM 20//敌机数量
#define ENEMY_INTERVAL 30//敌机出场间隔
#define ENEMY_HP 2 //敌机血量
#define BOSS_HP 20 //BOSS血量
#define ENEMY_BULLETS_NUM 2 //敌机弹匣中子弹数量
#define ENEMY_BULLET_TRIGGER_INTERVAL 160 //发射子弹的间隔


#define BOMB_PATH  ":/res/bomb-%1.png"   //爆炸资源图片1-7
#define BOMB_NUM  20     //爆炸数量
#define BOMB_MAX  7      //爆炸图片最大索引
#define BOMB_INTERVAL 20   //爆炸切图时间间隔
#define SOUND_BACKGROUND ":/res/bg.wav"
#define SOUND_BOMB ":/res/bomb.wav"

#define HERO_HP 15//血量
#define ENEMY_HP 2//敌机血量

#endif // CONFIG_H
