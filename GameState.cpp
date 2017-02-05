#include "GameState.h"
USING_NS_CC;

Scene* GameState::createScene()
{
	auto scene = Scene::create();
	auto layer = GameState::create();
	scene->addChild(layer);
	return scene;
}

bool GameState::init()
{
	if (!Layer::init())
	{
		return false;
	}

	//UserDefault::getInstance()->setStringForKey("string", "value");
	//UserDefault::getInstance()->setIntegerForKey("int", 2);
	//UserDefault::getInstance()->setFloatForKey("float", 2.3f);
	
	//std::string ret = UserDefault::getInstance()->getStringForKey("string");
	//int a = UserDefault::getInstance()->getIntegerForKey("int");
	//float b = UserDefault::getInstance()->getFloatForKey("float", 2.3f);
	//bool c = UserDefault::getInstance()->getBoolForKey("bool", "true");
	//

	//CCLOG("%d", a);
	
	//getStageDate();
	return true;
}
bool GameState::getStageDate(char *stageName){
	if (!UserDefault::getInstance()->getBoolForKey("Stage1"))
	{
		UserDefault::getInstance()->setBoolForKey("Stage1", true);
		UserDefault::getInstance()->setBoolForKey("Stage2", false);
		UserDefault::getInstance()->setBoolForKey("Stage3", false);
		UserDefault::getInstance()->setBoolForKey("Stage4", false);
	}
	else
	{
		auto isLock=UserDefault::getInstance()->getBoolForKey(stageName);
		UserDefault::getInstance()->flush();
		return isLock;
	}
}
