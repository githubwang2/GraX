#ifndef __TowerWar_GameDate__
#define __TowerWar_GameDate__
#include "cocos2d.h"
#include "ConstUtil.h"
class GameState 
{
public:
	//static cocos2d::Scene* createScene();
	//virtual bool init();
	//CREATE_FUNC(GameState);

	static bool getStageDate(char *stageName);
	static bool getIsFirst();
	//返回值为0 未解锁		1 一颗星	 2 两颗星	3 三颗星		4 无星 
	static int getLevelDate(char *levelName);
private:
	
};


#endif 
