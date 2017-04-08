#ifndef __TowerWar_StartScene__
#define __TowerWar_StartScene__
#include "cocos2d.h"

#include"Layer/SplashLayer.h"
#include"Layer/LoadingLayer.h"
class StartScene : public cocos2d::Scene
{
public:
	CREATE_FUNC(StartScene);
	//游戏开始
	void gameStart();
	//游戏预加载
	void gameLoading();
private:
	
};

#endif 
