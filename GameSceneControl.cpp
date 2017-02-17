#include "GameSceneControl.h"
#include "Scene/MenuScene.h"
#include "Scene/StageChooseScene.h"

GameSceneControl::GameState GameSceneControl::m_gameState = MenuSceneState;
////初始化单例唯一实例对象m_gameState
//GameSceneControl* GameSceneControl::m_gameState = nullptr;
//
//GameSceneControl* GameSceneControl::changeScene()
//{
//	if (!m_gameState)
//	{
//		m_gameState = new GameSceneControl();
//	}
//	return m_gameState;
//}

GameSceneControl::~GameSceneControl(){
//	m_gameState = nullptr;
}

void GameSceneControl::changeScene(GameState gamestate){
	switch (gamestate)
	{
	case GameState::MenuSceneState:{
									   CCLOG("btnGameMenu");
									   m_gameState = MenuSceneState;
									   auto transScene = cocos2d::TransitionFade::create(1.0f, MenuScene::createScene());
									   cocos2d::Director::getInstance()->replaceScene(transScene);
									   break;
	}
	case GameState::MainSceneState:{
									   CCLOG("btnGameStart");
									   m_gameState = MainSceneState;
									   auto transScene = cocos2d::TransitionFade::create(1.0f, StageChooseScene::createScene());
									   cocos2d::Director::getInstance()->replaceScene(transScene);
									   break;
	}
	case GameState::SetttingSceneState:{
										   CCLOG("btnGameSetting");
										   m_gameState = SetttingSceneState;
										  // auto transScene = cocos2d::TransitionFade::create(1.0f, MainScene::createScene());
										   //cocos2d::Director::getInstance()->replaceScene(transScene);
										   break;
	}
	case GameState::AboutSceneState:{
										CCLOG("btnGameAbout");
										m_gameState = AboutSceneState;
										//auto transScene = cocos2d::TransitionFade::create(1.0f, AboutScene::createScene());
										//cocos2d::Director::getInstance()->replaceScene(transScene);
										break;
	}
	case GameState::EndState:{
								 CCLOG("btnGameEnd");
								 cocos2d::Director::getInstance()->end();
								 break;
	}
	default: break;
	}
}