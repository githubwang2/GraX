#include "Layer/AboutLayer.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;


bool AboutLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	initAboutBG();

	return true;
}

void AboutLayer::initAboutBG(){
	aboutLayer = GUIReader::getInstance()->widgetFromJsonFile("MenuScene/AboutLayer.json");
	aboutLayer->setAnchorPoint(Point::ANCHOR_MIDDLE);
	aboutLayer->setPosition(visibleSize / 2);
	addChild(aboutLayer, 1);

	auto btn = dynamic_cast<Widget*>(aboutLayer->getChildByName("btnGameMenu"));
	btn->setOpacity(0);
	btn->runAction(FadeIn::create(1.0f));
	btn->addTouchEventListener(this, toucheventselector(MenuScene::touchButton));

	auto worldRead = dynamic_cast<ImageView*>(aboutLayer->getChildByName("BG")->getChildByName("world_read"));
	auto imgNepBG1 = dynamic_cast<ImageView*>(aboutLayer->getChildByName("BG")->getChildByName("nepBG1"));
	auto imgNepBG2 = dynamic_cast<ImageView*>(aboutLayer->getChildByName("BG")->getChildByName("nepBG2"));
	auto imgPlanep = dynamic_cast<ImageView*>(aboutLayer->getChildByName("BG")->getChildByName("Planeptune"));

	imgPlanep->setOpacity(0);
	auto planepAct1 = MoveTo::create(1.0f, Point(-615, -175));
	auto planepAct2 = FadeIn::create(1.0f);
	imgPlanep->runAction(planepAct1);
	imgPlanep->runAction(planepAct2);

	worldRead->setOpacity(0);
	worldRead->runAction(Sequence::create(DelayTime::create(1.0f), FadeIn::create(0.5f), nullptr));
	worldRead->setRotationY(10);

	imgNepBG1->setOpacity(0);
	auto bg1Act1 = FadeIn::create(1.0f);
	imgNepBG1->runAction(bg1Act1);
	imgNepBG1->setRotationY(10);
	//auto bg1Act1 = RotateBy::create(2.0f, Vec3(0, -360, 0));
	//imgNepBG1->runAction(bg1Act1);

	imgNepBG2->setOpacity(0);
	imgNepBG2->runAction(Sequence::create(DelayTime::create(1.0f), FadeIn::create(0.5f), nullptr));
}


void AboutLayer::touchButton(Ref *object, TouchEventType type){
	if (type == TOUCH_EVENT_ENDED)
	{
		GameLayerControl::changeScene(GameLayerControl::MenuLayerState);
	}
}



