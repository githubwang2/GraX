#ifndef __TowerWar_MonsterBase__
#define __TowerWar_MonsterBase__
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"


class MonsterBase : public cocos2d::Layer
{
public:
	MonsterBase(int id);
	
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
