#ifndef __TowerWar_Monster__
#define __TowerWar_Monster__
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"


class Monster : public cocos2d::Layer
{
public:
	Monster(int id);
	
	cocos2d::Sprite*createMonster();

	void changeDirection(float dt);

protected:
	void initAnimation(int id);

	cocos2d::Animation*ani_up;
	cocos2d::Animation*ani_down;
	cocos2d::Animation*ani_left;
	cocos2d::Animation*ani_right;

	int m_id;
	int m_hp;
};

#endif 
