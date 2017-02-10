#include "PopupLayer/PopupLayer.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;


bool PopupLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	return true;
}

Layer* PopupLayer::initResultLayer(){
	auto layer = Layer::create();
	popupLayer = dynamic_cast<Widget*>(GUIReader::getInstance()
		->widgetFromJsonFile("PopupLayer/PopupLayer.json"));
	popupLayer->setPosition(Point::ZERO);
	layer->addChild(popupLayer, 3);

	start1 = dynamic_cast<ImageView*>(popupLayer->getChildByName("StarBG")->getChildByName("Star1"));
	start2 = dynamic_cast<ImageView*>(popupLayer->getChildByName("StarBG")->getChildByName("Star2"));
	start3 = dynamic_cast<ImageView*>(popupLayer->getChildByName("StarBG")->getChildByName("Star3"));

	lost = dynamic_cast<Widget*>(popupLayer->getChildByName("Lost"));
	win = dynamic_cast<Widget*>(popupLayer->getChildByName("Win"));

	btnMenu = dynamic_cast<Button*>(popupLayer->getChildByName("Button")->getChildByName("btnMenu"));
	btnAgain = dynamic_cast<Button*>(popupLayer->getChildByName("Button")->getChildByName("btnAgain"));
	btnNext = dynamic_cast<Button*>(popupLayer->getChildByName("Button")->getChildByName("btnNext"));

	btnMenu->addTouchEventListener(this, toucheventselector(PopupLayer::touchButton));
	btnAgain->addTouchEventListener(this, toucheventselector(PopupLayer::touchButton));
	btnNext->addTouchEventListener(this, toucheventselector(PopupLayer::touchButton));

	level = dynamic_cast<TextAtlas*>(popupLayer->getChildByName("levelBG")->getChildByName("Level"));

	return layer;
}

void PopupLayer::popWin(int n){

	win->setVisible(true);
	lost->setVisible(false);

	btnMenu->setVisible(true);
	btnNext->setVisible(true);
	btnAgain->setVisible(true);

	showStar(n);
}

void PopupLayer::popLost(){

	win->setVisible(false);
	lost->setVisible(true);

	btnMenu->setVisible(true);
	btnNext->setVisible(false);
	btnAgain->setVisible(true);

	showStar(0);
}

void PopupLayer::showStar(int n){
	switch (n)
	{
	case 0:{
			   start1->setVisible(false);
			   start2->setVisible(false);
			   start3->setVisible(false);
			   break;
	}
	case 1:{
			   start1->setVisible(true);
			   start2->setVisible(false);
			   start3->setVisible(false);
			   break;
	}
	case 2:{
			   start1->setVisible(true);
			   start2->setVisible(true);
			   start3->setVisible(false);
			   break;
	}
	case 3:{
			   start1->setVisible(true);
			   start2->setVisible(true);
			   start3->setVisible(true);
			   break;
	}
	default:
		CCLOG("num of stars wrong");
		start1->setVisible(false);
		start2->setVisible(false);
		start3->setVisible(true);
		break;
	}
}

void PopupLayer::touchButton(cocos2d::Ref *object, cocos2d::ui::TouchEventType type){
	if (type == TOUCH_EVENT_ENDED)
	{
		auto widget = dynamic_cast<Widget*>(object);
		auto name = widget->getName();
		if (name.compare("btnMenu") == 0)
		{
			CCLOG("btnMenu");
		}
		else if (name.compare("btnNext") == 0)
		{
			CCLOG("btnNext");
		}
		else if (name.compare("btnAgain") == 0)
		{
			CCLOG("btnAgain");
		}
		else
		{
			CCLOG("no btn");
		}
	}
}

Layer*  PopupLayer::setResult(int n, int curLevel){
	auto layer = Layer::create();
	layer->addChild(initResultLayer(), 3);
	if (n==0)
	{
		popLost();
	}
	else
	{
		popWin(n);
	}
	char num[32] = { 0 };
	sprintf(num, "%d", curLevel);
	level->setStringValue(num);
	return layer;
}
