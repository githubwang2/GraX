
#ifndef __TowerWar_MainScene__
#define __TowerWar_MainScene__
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "HUDLayer/HUDLayer.h"

#include"GameMap.h"

USING_NS_CC;
using namespace cocostudio;
using namespace ui;



class MainScene : public cocos2d::Layer
{
public:

	static cocos2d::Scene* createScene();
	virtual bool init();
	
	CREATE_FUNC(MainScene);

	void attachTowerBuild();
private:

	void initBG();
	cocos2d::Size visibleSize;

	GameMap *gameMap;
	HUDLayer*hud;
};

#endif 
