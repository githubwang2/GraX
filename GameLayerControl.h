#ifndef __TowerWar_GameLayerControl__
#define __TowerWar_GameLayerControl__
#include "cocos2d.h"
#include "SoundsControl.h"
class GameLayerControl :cocos2d::Object
{
public:
	enum GameState
	{
		MenuLayerState = 0,
		DexLayerState,
		SetttingLayerState,
		AboutSLayerState,
		EndState,
		StageChooseLayerState,
		LevelChooseLayerState,
		GameMainScene
	};	

	static void changeScene(GameState gamestate);
private:

	GameState m_gameState;
};

#endif 
