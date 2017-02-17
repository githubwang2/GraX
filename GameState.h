#ifndef __TowerWar_GameDate__
#define __TowerWar_GameDate__
#include "cocos2d.h"

class GameState :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameState);


	static bool getStageDate(char *stageName);
private:
	
};


#endif 
