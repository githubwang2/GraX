#include "MenuScene.h"
#include "AboutScene.h"
#include"MainScene.h"

Scene* MenuScene::createScene()
{
	auto scene = Scene::create();
	auto layer = MenuScene::create();
	scene->addChild(layer);
	return scene;
}

bool MenuScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	CCLOG("isMenuScene");
	initMenuBtn();

	return true;
}

void MenuScene::initMenuBtn(){
	auto menuScene = GUIReader::getInstance()->widgetFromJsonFile("MenuScene/MenuScene.json");
	menuScene->setAnchorPoint(Point::ANCHOR_MIDDLE);
	menuScene->setPosition(visibleSize / 2);
	addChild(menuScene, 1);

	auto btnGameStart = dynamic_cast<Widget*>(menuScene->getChildByName("btnGameStart"));
	auto btnGameSetting = dynamic_cast<Widget*>(menuScene->getChildByName("btnGameSetting"));
	auto btnGameAbout = dynamic_cast<Widget*>(menuScene->getChildByName("btnGameAbout"));
	auto btnGameEnd = dynamic_cast<Widget*>(menuScene->getChildByName("btnGameEnd"));
	
	btnGameStart->addTouchEventListener(this, toucheventselector(MenuScene::touchButton));
	btnGameSetting->addTouchEventListener(this, toucheventselector(MenuScene::touchButton));
	btnGameAbout->addTouchEventListener(this, toucheventselector(MenuScene::touchButton));
	btnGameEnd->addTouchEventListener(this, toucheventselector(MenuScene::touchButton));
}

void MenuScene::touchButton(Ref *object, TouchEventType type){
	if (type == TOUCH_EVENT_ENDED)
	{
		auto widget = dynamic_cast<Widget*>(object);
		auto name = widget->getName();
		if (name.compare("btnGameStart") == 0)
		{
			gameControl(MainState);
		}
		else if (name.compare("btnGameSetting") == 0)
		{
			gameControl(SetttingState);
		}
		else if (name.compare("btnGameAbout") == 0)
		{
			gameControl(AboutState);
		}
		if (name.compare("btnGameEnd") == 0)
		{
			gameControl(EndState);
		}
	}
}

//	场景控制
void MenuScene::gameControl(GameState gamestate){
	switch (gamestate)
	{
	case GameState::MenuState:{
								  CCLOG("btnGameMenu");
								  m_gameState = MenuState;
								  auto transScene = TransitionFade::create(1, MenuScene::createScene());
								  Director::getInstance()->replaceScene(transScene);
								  break;
	}
	case GameState::MainState:{
								  CCLOG("btnGameStart");
								  m_gameState = MainState;
								  auto transScene = TransitionFade::create(1, MainScene::createScene());
								  Director::getInstance()->replaceScene(transScene);
								  break;
	}
	case GameState::SetttingState:{
									  CCLOG("btnGameSetting");
									  m_gameState = SetttingState;
									  break;
	}
	case GameState::AboutState:{
								   CCLOG("btnGameAbout");
								   m_gameState = AboutState;
								   auto transScene = TransitionFade::create(1, AboutScene::createScene());
								   Director::getInstance()->replaceScene(transScene);
								   break;
	}
	case GameState::EndState:{
								 CCLOG("btnGameEnd");
								 Director::getInstance()->end();
								 break;
	}
	default: break;
	}
}
	