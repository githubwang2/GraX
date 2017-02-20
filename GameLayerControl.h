#ifndef __TowerWar_GameLayerControl__
#define __TowerWar_GameLayerControl__
#include "cocos2d.h"

class GameLayerControl :cocos2d::Object
{
public:
	enum GameState
	{
		MenuLayerState = 0,
		SetttingLayerState,
		AboutSLayerState,
		EndState,
		StageChooseLayerState,
		LevelChooseLayerState
	};	

	static void changeScene(GameState gamestate);
private:

	GameState m_gameState;
};

#endif 