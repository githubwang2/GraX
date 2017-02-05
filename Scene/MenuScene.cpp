#include "Scene/MenuScene.h"
#include"GameSceneControl.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;

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

	initMenuBG();

	initMenuBtn(BTN_START);
	initMenuBtn(BTN_SETTING);
	initMenuBtn(BTN_ABOUT);
	initMenuBtn(BTN_EXIT);

	return true;
}

void MenuScene::initMenuBG(){
	menuScene = GUIReader::getInstance()->widgetFromJsonFile("MenuScene/MenuScene.json");
	menuScene->setAnchorPoint(Point::ANCHOR_MIDDLE);
	menuScene->setPosition(visibleSize / 2);
	addChild(menuScene, 1);

	auto imgCpu = dynamic_cast<ImageView*>(menuScene->getChildByName("BG")->getChildByName("cpu"));
	auto imgNep = dynamic_cast<ImageView*>(menuScene->getChildByName("BG")->getChildByName("nep"));
	auto imgNepBG1 = dynamic_cast<ImageView*>(menuScene->getChildByName("BG")->getChildByName("nepBG1"));
	auto imgNepBG2 = dynamic_cast<ImageView*>(menuScene->getChildByName("BG")->getChildByName("nepBG2"));
	auto imgTitle = dynamic_cast<ImageView*>(menuScene->getChildByName("Title"));

	imgCpu->setOpacity(0);
	auto cpuAct1 = MoveTo::create(2.0f, Point(-286, 190));
	auto cpuAct2 = FadeIn::create(2.0f);
	imgCpu->runAction(cpuAct1);
	imgCpu->runAction(cpuAct2);

	imgNep->setOpacity(0);
	auto nepAct = Sequence::create(DelayTime::create(1.0f),
		Spawn::create(
		MoveTo::create(1.0f, Point(-127, -155)),
		FadeIn::create(1.0f)),
		nullptr);
	imgNep->runAction(nepAct);

	imgNepBG1->setOpacity(0);
	imgNepBG2->setOpacity(0);
	auto bg1Act = Sequence::create(DelayTime::create(1.5f),
		FadeIn::create(0.5f), nullptr);
	auto bg2Act = Sequence::create(DelayTime::create(1.5f),
		FadeIn::create(0.5f), nullptr);
	imgNepBG1->runAction(bg1Act);
	imgNepBG2->runAction(bg2Act);

	imgTitle->setOpacity(0);
	auto titleAct = Sequence::create(DelayTime::create(2.3f),
		FadeIn::create(0.5f), nullptr);
	imgTitle->runAction(titleAct);
}

void MenuScene::initMenuBtn(char*btnName){

	auto btn = dynamic_cast<Widget*>(menuScene->getChildByName(btnName));
	btn->setOpacity(0);
	btn->runAction(Sequence::create(DelayTime::create(3.0f), FadeIn::create(0.5f), nullptr));
	btn->addTouchEventListener(this, toucheventselector(MenuScene::touchButton));

}

void MenuScene::touchButton(Ref *object, TouchEventType type){
	if (type == TOUCH_EVENT_ENDED)
	{
		auto widget = dynamic_cast<Widget*>(object);
		auto name = widget->getName();
		if (name.compare(BTN_START) == 0)
		{
			GameSceneControl::changeScene(GameSceneControl::MainSceneState);
		}
		else if (name.compare(BTN_SETTING) == 0)
		{
			GameSceneControl::changeScene(GameSceneControl::SetttingSceneState);
		}
		else if (name.compare(BTN_ABOUT) == 0)
		{
			GameSceneControl::changeScene(GameSceneControl::AboutSceneState);
		}
		if (name.compare(BTN_EXIT) == 0)
		{
			GameSceneControl::changeScene(GameSceneControl::EndState);
		}
	}
}

	