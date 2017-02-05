#include"Scene/StageChooseScene.h"
#include"GameState.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;

Scene*StageChooseScene::createScene(){
	auto scene = Scene::create();
	auto layer = StageChooseScene::create();
	scene->addChild(layer);
	return scene;
}
bool StageChooseScene::init(){
	if (!Layer::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getWinSize();

	addBackgroundSprite();

	this->schedule(schedule_selector(StageChooseScene::test), 0.2f);
	
	return true;
}

void StageChooseScene::addBackgroundSprite(){
	stageChoose = dynamic_cast<Widget*>(GUIReader::getInstance()
		->widgetFromJsonFile("StageChoose/StageChoose.json"));
	stageChoose->setPosition(Point::ZERO);
	addChild(stageChoose);

	scrollView = dynamic_cast<ScrollView*>(stageChoose->getChildByName("ScrollView"));

	auto stage1 = addButton("Stage1");
	auto stage2 = addButton("Stage2");
	auto stage3 = addButton("Stage3");
	auto stage4 = addButton("Stage4");

	//auto lblstage1 = dynamic_cast<ImageView*>(stage1->getChildByName("lblStage1"));
	//auto lblstage2 = dynamic_cast<ImageView*>(stage2->getChildByName("lblStage2"));
	//auto lblstage3 = dynamic_cast<ImageView*>(stage3->getChildByName("lblStage3"));
	//auto lblstage4 = dynamic_cast<ImageView*>(stage4->getChildByName("lblStage4"));

	/*stage1->setBright(true);
	lblstage1->setVisible(true);
	stage2->setBright(false);
	lblstage2->setVisible(false);
	stage3->setBright(false);
	lblstage3->setVisible(false);
	stage4->setBright(false);
	lblstage4->setVisible(false);*/

	//auto label = LabelTTF::create("雄大なる緑の大地", "Meiryo", 24);
	//label->setPosition(500, 100);
	//this->addChild(label);
}

Button*StageChooseScene::addButton(char*name){
	auto button = dynamic_cast<Button*>(stageChoose->getChildByName("ScrollView")->getChildByName(name));
	button->addTouchEventListener(this, toucheventselector(StageChooseScene::touchButton));
	char buf[32] = { 0 };
	std::sprintf(buf, "lbl%s", name);
	CCLOG("%s", buf);
	auto lblstage = dynamic_cast<ImageView*>(button->getChildByName(buf));

	button->setBright(GameState::getStageDate(name));
	lblstage->setVisible(GameState::getStageDate(name));

	return button;	
}

void StageChooseScene::touchButton(Ref *object, TouchEventType type){
	if (type == TOUCH_EVENT_ENDED)
	{
		auto widget = dynamic_cast<Widget*>(object);
		auto name = widget->getName();
		if (name.compare("Stage1") == 0)
		{
			CCLOG("stage1");
		}
		else if (name.compare("Stage2") == 0)
		{
			CCLOG("stage2");
		}
		else if (name.compare("Stage3") == 0)
		{
			CCLOG("stage3");
		}
		else if(name.compare("Stage4") == 0)
		{
			CCLOG("stage4");
		}
		else
		{
			CCLOG("no stage");
			return;
		}
	}
}

void StageChooseScene::adjustScrollView(){
	auto innerSize = scrollView->getInnerContainer()->getContentSize();
	auto layerPosx = scrollView->getInnerContainer()->getPositionX();
	
	if (-SCROLL_WIDTH / 2  < layerPosx)
	{
		//CCLOG("stage1");
		scrollView->scrollToPercentHorizontal(0, ADJUEST_TIME, false);
	}
	else if (-SCROLL_WIDTH *3/ 2 < layerPosx&&layerPosx<-SCROLL_WIDTH / 2)
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

void StageChooseScene::test(float dt){
	adjustScrollView();
}
