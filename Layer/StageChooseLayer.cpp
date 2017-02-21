#include"Layer/StageChooseLayer.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;

int StageChooseLayer::s_current_stage = 1;

bool StageChooseLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}


	isFirst();

	addBackgroundSprite();
	
	this->schedule(schedule_selector(StageChooseLayer::adjustScrollView), 0.2f);
	return true;
}

void StageChooseLayer::isFirst()
{
	if (!GameState::getIsFirst())
	{
		auto layer = DialogLayer::createWithJsonFile("DialogLayer/0-1.json");
		this->addChild(layer,2);
	}
}

void StageChooseLayer::addBackgroundSprite(){
	stageChoose = dynamic_cast<Widget*>(GUIReader::getInstance()->widgetFromJsonFile("StageChoose/StageChoose.json"));
	stageChoose->setPosition(Point::ZERO);
	addChild(stageChoose);

	scrollView = dynamic_cast<ScrollView*>(stageChoose->getChildByName("ScrollView"));

	auto stage1 = addButton("Stage1");
	auto stage2 = addButton("Stage2");
	auto stage3 = addButton("Stage3");
	auto stage4 = addButton("Stage4");

	//auto label = LabelTTF::create("ÐÛ´ó¤Ê¤ë¾v¤Î´óµØ", "Meiryo", 24);
	//label->setPosition(500, 100);
	//this->addChild(label);
}

Button*StageChooseLayer::addButton(char*name){
	auto button = dynamic_cast<Button*>(stageChoose->getChildByName("ScrollView")->getChildByName(name));
	button->addTouchEventListener(this, toucheventselector(StageChooseLayer::touchButton));
	char buf[32] = { 0 };
	std::sprintf(buf, "lbl%s", name);
	CCLOG("%s", buf);
	auto lblstage = dynamic_cast<ImageView*>(button->getChildByName(buf));

	button->setBright(GameState::getStageDate(name));
	lblstage->setVisible(GameState::getStageDate(name));

	return button;
}

void StageChooseLayer::touchButton(Ref *object, TouchEventType type){
	if (type == TOUCH_EVENT_ENDED)
	{
		auto widget = dynamic_cast<Widget*>(object);
		auto name = widget->getName();
		if (name.compare("Stage1") == 0)
		{
			//CCLOG("stage1");
			s_current_stage = 1;
			GameLayerControl::changeScene(GameLayerControl::LevelChooseLayerState);
		}
		else if (name.compare("Stage2") == 0)
		{
			//CCLOG("stage2");
			s_current_stage = 2;
			GameLayerControl::changeScene(GameLayerControl::LevelChooseLayerState);
		}
		else if (name.compare("Stage3") == 0)
		{
			//CCLOG("stage3");
			s_current_stage = 3;
			GameLayerControl::changeScene(GameLayerControl::LevelChooseLayerState);
		}
		else if (name.compare("Stage4") == 0)
		{
			//CCLOG("stage4");
			s_current_stage = 4;
			GameLayerControl::changeScene(GameLayerControl::LevelChooseLayerState);
		}
		else
		{
			CCLOG("no stage");
			return;
		}
	}
}

void StageChooseLayer::adjustScrollView(float dt){
	auto innerSize = scrollView->getInnerContainer()->getContentSize();
	auto layerPosx = scrollView->getInnerContainer()->getPositionX();

	if (-SCROLL_WIDTH / 2  < layerPosx)
	{
		//CCLOG("stage1");
		scrollView->scrollToPercentHorizontal(0, ADJUEST_TIME, false);
	}
	else if (-SCROLL_WIDTH * 3 / 2 < layerPosx&&layerPosx<-SCROLL_WIDTH / 2)
	{
		//CCLOG("stage2");
		int a = 100 * SCROLL_WIDTH / (innerSize.width - SCROLL_WIDTH);
		scrollView->scrollToPercentHorizontal(a, ADJUEST_TIME, false);
	}
	else if (-SCROLL_WIDTH * 5 / 2 < layerPosx&&layerPosx < -SCROLL_WIDTH * 3 / 2)
	{
		//CCLOG("stage3");
		int a = 100 * 2 * SCROLL_WIDTH / (innerSize.width - SCROLL_WIDTH);
		scrollView->scrollToPercentHorizontal(a, ADJUEST_TIME, false);
	}
	else if (layerPosx < -SCROLL_WIDTH * 5 / 2)
	{
		//CCLOG("stage4");
		int a = 100 * 3 * SCROLL_WIDTH / (innerSize.width - SCROLL_WIDTH);
		scrollView->scrollToPercentHorizontal(a, ADJUEST_TIME, false);
	}
}


