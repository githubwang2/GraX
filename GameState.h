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
	//����ֵΪ0 δ����		1 һ����	 2 ������	3 ������		4 ���� 
	static int getLevelDate(char *levelName);
private:
	
};


#endif 
