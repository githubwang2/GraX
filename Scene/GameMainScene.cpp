#include "Scene/GameMainScene.h"

USING_NS_CC;
using namespace cocostudio;
using namespace ui;

Scene* GameMainScene::createScene()
{
	GameMainScene*gameMainScene = new GameMainScene();
	if (gameMainScene && gameMainScene->init())
	{
		gameMainScene->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(gameMainScene);
	}
	auto layer = GameMainLayer::create();
	gameMainScene->addChild(layer);
	return gameMainScene;
}

bool GameMainScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	return true;
}

void GameMainScene::touchButton(Ref *object, cocos2d::ui::TouchEventType type)
{
	if (type == TOUCH_EVENT_ENDED)
	{

		GameLayerControl::changeScene(GameLayerControl::MenuLayerState);
	}
}