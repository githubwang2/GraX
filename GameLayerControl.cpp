#include "GameLayerControl.h"
#include "Scene/StartScene.h"
#include "Scene/MenuScene.h"
#include "Scene/LevelChooseScene.h"
#include "Layer/LoadingLayer.h"
#include "Layer/MenuLayer.h"
#include "Layer/AboutLayer.h"
#include "Layer/SettingLayer.h"
#include "Layer/StageChooseLayer.h"
#include "Layer/LevelChooseLayer.h"
#include "Layer/DexLayer.h"

void GameLayerControl::changeScene(GameState gamestate){
	SoundsControl::setSound(SoundsControl::SoundState::BtnSelect);
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
	case GameState::DexLayerState:{
										   CCLOG("btnGameDex");
										   //m_gameState =DexLayerState;
										   auto layer = DexLayer::create();
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
											  //  m_gameState = StageChooseLayerState;
											  auto layer = StageChooseLayer::create();
											  auto transScene = cocos2d::TransitionFade::create(1.0f, LevelChooseScene::createScene(layer));
											  cocos2d::Director::getInstance()->replaceScene(transScene);
											  break;
	}
	case GameState::LevelChooseLayerState:{
											  //  m_gameState = LevelChooseLayerState;
											  auto layer = LevelChooseLayer::createWithJsonFile();
											  auto transScene = cocos2d::TransitionFade::create(1.0f, LevelChooseScene::createScene(layer));
											  cocos2d::Director::getInstance()->replaceScene(transScene);
											  break;
	}
	case GameState::GameMainScene:{
									  auto transScene = cocos2d::TransitionFade::create(1.0f, GameMainScene::createScene());
									  cocos2d::Director::getInstance()->replaceScene(transScene);
									  break;
	}
	default: break;
	}
}