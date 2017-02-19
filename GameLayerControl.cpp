#include "GameLayerControl.h"
#include "Scene/MenuScene.h"
#include "Layer/MenuLayer.h"
#include "Layer/AboutLayer.h"
#include "Layer/SettingLayer.h"
#include "Layer/StageChooseLayer.h"

void GameLayerControl::changeScene(GameState gamestate){
	switch (gamestate)
	{
	case GameState::MenuLayerState:{
									   // CCLOG("btnGameMenu");
									   //m_gameState = MenuLayerState;
									   auto layer = MenuLayer::create();
									   auto transScene = cocos2d::TransitionFade::create(1.0f, MenuScene::createScene(layer));
									   cocos2d::Director::getInstance()->replaceScene(transScene);
									   break;
	}
	case GameState::SetttingLayerState:{
										   CCLOG("btnGameSetting");
										   //m_gameState = SetttingLayerState;
										   auto layer = SettingLayer::create();
										   auto transScene = cocos2d::TransitionFade::create(1.0f, MenuScene::createScene(layer));
										   cocos2d::Director::getInstance()->replaceScene(transScene);
										   break;
	}
	case GameState::AboutSLayerState:{
										 //CCLOG("btnGameAbout");
										 //m_gameState = AboutSLayerState;
										 auto layer = AboutLayer::create();
										 auto transScene = cocos2d::TransitionFade::create(1.0f, MenuScene::createScene(layer));
										 cocos2d::Director::getInstance()->replaceScene(transScene);
										 break;
	}
	case GameState::EndState:{
								 //CCLOG("btnGameEnd");
								 cocos2d::Director::getInstance()->end();
								 break;
	}
	case GameState::StageChooseLayerState:{
											  // CCLOG("btnGameStageChoose");
											  //  m_gameState = MainSceneState;
											  auto layer = StageChooseLayer::create();
											  auto transScene = cocos2d::TransitionFade::create(1.0f, MenuScene::createScene(layer));
											  cocos2d::Director::getInstance()->replaceScene(transScene);
											  break;
	}
	default: break;
	}
}