#ifndef __TowerWar_Tower__
#define __TowerWar_Tower__
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "ConstUtil.h"
#include "GameMap.h"
#include "Layer/GameMainLayer.h"
#include "Sprite/Components/ComTower.h"
#include "FireManager.h"

class Tower : public cocos2d::Layer
{
public:
	static Tower* createTower(cocos2d::Point pos, GameMap *gameMap);
	virtual bool init(cocos2d::Point pos, GameMap *gameMap);

	//FireManager*m_fireManager;
protected:
};

#endif