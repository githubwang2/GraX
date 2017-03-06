#include "GameState.h"
USING_NS_CC;

//Scene* GameState::createScene()
//{
//	auto scene = Scene::create();
//	auto layer = GameState::create();
//	scene->addChild(layer);
//	return scene;
//}
//
//bool GameState::init()
//{
//	if (!Layer::init())
//	{
//		return false;
//	}
//
//	//UserDefault::getInstance()->setStringForKey("string", "value");
//	//UserDefault::getInstance()->setIntegerForKey("int", 2);
//	//UserDefault::getInstance()->setFloatForKey("float", 2.3f);
//	
//	//std::string ret = UserDefault::getInstance()->getStringForKey("string");
//	//int a = UserDefault::getInstance()->getIntegerForKey("int");
//	//float b = UserDefault::getInstance()->getFloatForKey("float", 2.3f);
//	//bool c = UserDefault::getInstance()->getBoolForKey("bool", "true");
//	//
//
//	//CCLOG("%d", a);
//	
//	//getStageDate();
//	return true;
//}

bool GameState::getStageDate(char *stageName){
	if (!UserDefault::getInstance()->getBoolForKey("Stage1"))
	{
		UserDefault::getInstance()->setBoolForKey("Stage1", true);
		UserDefault::getInstance()->setBoolForKey("Stage2", false);
		UserDefault::getInstance()->setBoolForKey("Stage3", false);
		UserDefault::getInstance()->setBoolForKey("Stage4", false);
	}
	auto isLock = UserDefault::getInstance()->getBoolForKey(stageName);
	UserDefault::getInstance()->flush();
	return isLock;

}

bool GameState::getIsFirst()
{
	if (!UserDefault::getInstance()->getBoolForKey("is_first"))
	{
		UserDefault::getInstance()->setBoolForKey("is_first", true);
		return false;
	}
	else
	{
		return true;
	}
}

int GameState::getLevelDate(char *levelName)
{
	if (!UserDefault::getInstance()->getIntegerForKey("level1-1"))
	{
		for (int s = 1; s <= MAX_STAGE;s++)
		{
			for (int l = 1; l <= MAX_LEVEL;l++)
			{
				char buf[32] = { 0 };
				sprintf(buf, "level%d-%d", s, l);
				CCLOG("level name%s", buf);
				UserDefault::getInstance()->setIntegerForKey(buf, 0);
			}
		}
		UserDefault::getInstance()->setIntegerForKey("level1-1", 4);
	}
	auto isLock = UserDefault::getInstance()->getIntegerForKey(levelName);
	UserDefault::getInstance()->flush();
	return isLock;
}

void GameState::setLevelDate(char *levelName, int startNum)
{
	UserDefault::getInstance()->setIntegerForKey(levelName, startNum);
	UserDefault::getInstance()->flush();
}

void GameState::setStageDate(char *stageName)
{
	UserDefault::getInstance()->setBoolForKey(stageName, true);
	UserDefault::getInstance()->flush();
}

void GameState::isInitLanguageAndBGM()
{
	if (!UserDefault::getInstance()->getBoolForKey("music_on_key")
		&& !UserDefault::getInstance()->getBoolForKey("music_on_key"))
	{
		UserDefault::getInstance()->setBoolForKey("music_on_key", true);
		UserDefault::getInstance()->setBoolForKey("language_jp_key", true);
		UserDefault::getInstance()->flush();
	}
}
