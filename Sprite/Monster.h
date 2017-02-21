#ifndef __TowerWar_Monster__
#define __TowerWar_Monster__
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "Layer/GameMainLayer.h"

class Monster : public cocos2d::Layer
{
public :
	static Monster*create(int id);

	Monster(int id);
	bool initMonster();
	void changeDirection(float dt);

protected:

	int m_id;
	int m_hp;
	int m_speed;
};

#endif 
