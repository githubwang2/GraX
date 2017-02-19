#ifndef __TowerWar_LevelChooseScene__
#define __TowerWar_LevelChooseScene__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include"ConstUtil.h"

class LevelSelectScene:public cocos2d::Layer
{
public:
	static cocos2d::Scene*createScene();
	virtual bool init();
	CREATE_FUNC(LevelSelectScene);

	
private:
	
};

#endif