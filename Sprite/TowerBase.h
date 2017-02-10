#ifndef __TowerWar_TowerBase__
#define __TowerWar_TowerBase__
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include"GameMap.h"

class TowerBase : public cocos2d::Layer
{
public:
	TowerBase();

	virtual bool init();
	CREATE_FUNC(TowerBase);

	cocos2d::Layer* createTower(cocos2d::Point pos, GameMap *gameMap);

protected:
};

#endif