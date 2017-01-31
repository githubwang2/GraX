#include"StageChooseScene.h"


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
	
	return true;
}

void StageChooseScene::addBackgroundSprite(){
	stageChoose = dynamic_cast<Widget*>(GUIReader::getInstance()
		->widgetFromJsonFile("StageChoose/StageChoose.json"));
	stageChoose->setPosition(Point::ZERO);
	addChild(stageChoose);

	addButton("stage1");
	addButton("stage2");
	addButton("stage3");
	addButton("stage4");
	//auto label = LabelTTF::create("雄大なる緑の大地", "Meiryo", 24);
	//label->setPosition(500, 100);
	//this->addChild(label);
	auto scrollView = dynamic_cast<ScrollView*>(stageChoose->getChildByName("ScrollView"));
	//scrollView->scrollToPercentHorizontal(17.5,1.0, false);
//	scrollView->scrollToPercentHorizontal(35, 1.0, false);
	scrollView->scrollToPercentHorizontal(70, 1.0, false);
}

void StageChooseScene::addButton( char*name){
	auto button = dynamic_cast<Button*>(stageChoose->getChildByName("ScrollView")->getChildByName(name));
	button->addTouchEventListener(this, toucheventselector(StageChooseScene::touchButton));
}

void StageChooseScene::touchButton(Ref *object, TouchEventType type){
	if (type == TOUCH_EVENT_ENDED)
	{
		auto widget = dynamic_cast<Widget*>(object);
		auto name = widget->getName();
		if (name.compare("stage1") == 0)
		{
			CCLOG("stage1");
		}
		else if (name.compare("stage2") == 0)
		{
			CCLOG("stage2");
		}
		else if (name.compare("stage3") == 0)
		{
			CCLOG("stage3");
		}
		else if(name.compare("stage4") == 0)
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