#ifndef __TowerWar_StartScene__
#define __TowerWar_StartScene__
#include "cocos2d.h"

#include"Layer/SplashLayer.h"
#include"Layer/LoadingLayer.h"
class StartScene : public cocos2d::Scene
{
public:
	CREATE_FUNC(StartScene);
	//��Ϸ��ʼ
	void gameStart();
	//��ϷԤ����
	void gameLoading();
private:
	
};

#endif 
