//
//	MenuScene.h
//
//	TowerWar
//
//	Create by wang2 on	17-1-25
//
#ifndef __TowerWar_MenuScene__
#define __TowerWar_MenuScene__
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;

enum GameState
{
	MenuState = 0,
	MainState,
	SetttingState,
	AboutState,
	EndState
};


class MenuScene : public Layer
{
public:

	static Scene* createScene();
	virtual bool init();
	
	void initMenuBtn();

	void touchButton(Ref *object, TouchEventType type);

	CREATE_FUNC(MenuScene);
	//----gameState
	void gameControl(GameState gamestate);
	GameState m_gameState;

private:
	Size visibleSize;
};

#endif 
