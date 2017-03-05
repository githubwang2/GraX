#ifndef  __CONSTANTS__
#define  __CONSTANTS__

#include "Sprite/Components/ComTower.h"
#include "Sprite/Components/ComMove.h"
#include "Sprite/Components/ComLife.h"
#include "Sprite/Components/ComBullet.h"


const int		bullet_damage = 5;				//子弹伤害
const int		bullet_speed = 10;				//子弹速度
const int       tower_range = 100;              //防御塔攻击范围
const float     tower_reloadTime = 0.3;		    //防御塔攻击间隔时间
//const int		monster_hp = 40;				//怪物Hp
//const int     monster_speed = 10;             //怪物行走速度

//无限模式下
const int		increase_monste = 1;			//每波怪物增加的数量
const float		interval_time = 1.0f;			//每个怪物产生间隔时间
const float     wave_inteval = 3.0f;   			//每波产生间隔时间         

#endif