#include "Layer/MenuLayer.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;


bool MenuLayer::init()
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

void MenuLayer::initMenuBG(){
	menuLayer = GUIReader::getInstance()->widgetFromJsonFile("MenuLayer/MenuLayer.json");
	menuLayer->setAnchorPoint(Point::ANCHOR_MIDDLE);
	menuLayer->setPosition(visibleSize / 2);
	addChild(menuLayer, 1);

	auto imgCpu = dynamic_cast<ImageView*>(menuLayer->getChildByName("BG")->getChildByName("cpu"));
	auto imgNep = dynamic_cast<ImageView*>(menuLayer->getChildByName("BG")->getChildByName("nep"));
	auto imgNepBG1 = dynamic_cast<ImageView*>(menuLayer->getChildByName("BG")->getChildByName("nepBG1"));
	auto imgNepBG2 = dynamic_cast<ImageView*>(menuLayer->getChildByName("BG")->getChildByName("nepBG2"));
	auto imgTitle = dynamic_cast<ImageView*>(menuLayer->getChildByName("Title"));

	imgCpu->setOpacity(0);
	auto cpuAct1 = MoveTo::create(2.0f, Point(-286, 190));
	auto cpuAct2 = FadeIn::create(2.0f);
	imgCpu->runAction(cpuAct1);
	imgCpu->runAction(cpuAct2);

	imgNep->setOpacity(0);
	auto nepAct = Sequence::create(DelayTime::create(1.0f),
		Spawn::create(MoveTo::create(1.0f, Point(-127, -155)),
		FadeIn::create(1.0f), nullptr), nullptr);
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

void MenuLayer::initMenuBtn(char*btnName){

	auto btn = dynamic_cast<Widget*>(menuLayer->getChildByName(btnName));
	btn->setOpacity(0);
	btn->runAction(Sequence::create(DelayTime::create(3.0f), FadeIn::create(0.5f), nullptr));
	btn->addTouchEventListener(this, toucheventselector(MenuScene::touchButton));

}



