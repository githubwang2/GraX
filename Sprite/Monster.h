#ifndef __TowerWar_Monster__
#define __TowerWar_Monster__
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "Layer/GameMainLayer.h"

class Monster : public cocos2d::Layer
{
public:
	static Monster*create(int id);
private:
	Monster(int id);
	bool initMonster();
	int m_id;
	int m_hp;
	int m_speed;

	void setMonsterMessage(int id);
};

#endif 
