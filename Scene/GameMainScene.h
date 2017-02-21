#ifndef __TowerWar_GameMainScene__
#define __TowerWar_GameMainScene__
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"


#include "Layer/GameMainLayer.h"

class GameMainScene : public cocos2d::Scene
{
public:

	static cocos2d::Scene* createScene();
	virtual bool init();

private:
	
};

#endif 
