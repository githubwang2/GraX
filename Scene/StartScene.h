#ifndef __TowerWar_StartScene__
#define __TowerWar_StartScene__
#include "cocos2d.h"

#include"Layer/SplashLayer.h"

class StartScene : public cocos2d::Scene
{
public:

	void gameStart();
	//virtual bool init();
	CREATE_FUNC(StartScene);

private:
};

#endif 
