#ifndef __TowerWar_GameMainLayer__
#define __TowerWar_GameMainLayer__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include"GameMap.h"
#include "Layer/HUDLayer.h"
#include"Layer/PopupLayer.h"

class GameMainLayer : public cocos2d::Layer
{
public:
	virtual bool init();

	CREATE_FUNC(GameMainLayer);

	void addMonster(float dt);

	void attachTowerBuild();
	//结束游戏（怪物被杀完或者游戏失败）
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
