#include "AboutScene.h"

#include "MenuScene.h"

Scene* AboutScene::createScene()
{
	auto scene = Scene::create();
	auto layer = AboutScene::create();
	scene->addChild(layer);
	return scene;
}

bool AboutScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	CCLOG("isAboutScene");
	initAboutScene();
	return true;
}

void AboutScene::initAboutScene(){
	auto aboutScene = GUIReader::getInstance()->widgetFromJsonFile("AboutScene/AboutScene.json");
	aboutScene->setAnchorPoint(Point::ANCHOR_MIDDLE);
	aboutScene->setPosition(visibleSize / 2);
	addChild(aboutScene, 1);

	auto btnReturnMenu = dynamic_cast<Widget*>(aboutScene->getChildByName("btnReturnMenu"));
	btnReturnMenu->addTouchEventListener(this, toucheventselector(AboutScene::touchButton));
}

void AboutScene::touchButton(Ref *object, TouchEventType type){
	if (type == TOUCH_EVENT_ENDED)
	{
		auto transScene = TransitionFade::create(1, MenuScene::createScene());
		Director::getInstance()->replaceScene(transScene);
	}
}