
#ifndef __TowerWar_MainScene__
#define __TowerWar_MainScene__
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "HUDLayer/HUDLayer.h"

#include"GameMap.h"

class MainScene : public cocos2d::Layer
{
public:

	static cocos2d::Scene* createScene();
	virtual bool init();
	


	CREATE_FUNC(MainScene);

	void addMonster(float dt);

	void attachTowerBuild();
	//结束游戏（怪物被杀净或者游戏失败）
	void endGame(bool isWin);
	//移除怪物 
	void removeMonster(Node* monster);
private:

	void initBG();
	cocos2d::Size visibleSize;

	GameMap *gameMap;

	//HUDLayer*hud;
	int     m_beginHp;		//	开始时玩家生命值
	int		m_beginGold;	//	开始时玩家金钱
	int		m_level;		//	当前关卡数
	int     m_level_WavNum;  //	当前关卡怪物总波数
	bool	m_isWin;		//	
};

#endif 
