//
//	GameSceneControl.h
//
//	TowerWar
//
//	Create by wang2 on	17-2-4
//
#ifndef __TowerWar_GameSceneControl__
#define __TowerWar_GameSceneControl__
#include "cocos2d.h"



class GameSceneControl:cocos2d::Object
{
public:
	enum GameState
	{
		MenuSceneState = 0,
		MainSceneState,
		SetttingSceneState,
		AboutSceneState,
		EndState
	};
	//void gameControl(GameState gamestate);
	//static GameSceneControl* changeScene();		

	static void changeScene(GameState gamestate);
private:
	static  GameState m_gameState;
	
	~GameSceneControl();
};

#endif 
