#ifndef __TowerWar_Tower__
#define __TowerWar_Tower__
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include"GameMap.h"
#include"FireManager.h"

class Tower : public cocos2d::Layer
{
public:
	Tower();

	virtual bool init();
	CREATE_FUNC(Tower);

	cocos2d::Layer* createTower(cocos2d::Point pos, GameMap *gameMap);

	FireManager*m_fireManager;
protected:
};

#endif