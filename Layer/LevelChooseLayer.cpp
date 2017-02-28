#include"Layer/LevelChooseLayer.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;

int LevelChooseLayer::g_current_level=1;

Layer* LevelChooseLayer::createWithJsonFile()
{
	LevelChooseLayer*levelChooseLayer = new LevelChooseLayer();
	if (levelChooseLayer && levelChooseLayer->init())
	{
		levelChooseLayer->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(levelChooseLayer);
	}
	return levelChooseLayer;
}

bool LevelChooseLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	m_currentStage = StageChooseLayer::g_current_stage;

	initLevelLayer();
	for (int i = 0; i < MAX_LEVEL;i++)
	{
		initLevelButton(i+1);
	}
	
	return true;
}

void LevelChooseLayer::initLevelLayer()
{
	levelChoose = dynamic_cast<Widget*>(GUIReader::getInstance()->widgetFromJsonFile("LevelChoose/LevelChoose.json"));
	levelChoose->setPosition(Point::ZERO);
	addChild(levelChoose);

	auto BG = dynamic_cast<ImageView*>(levelChoose->getChildByName("BG"));
	char levelBgPath[32] = { 0 };
	sprintf(levelBgPath, "LevelChoose/levelBG0%d.png", m_currentStage);
	BG->loadTexture(levelBgPath);

	auto btnMenu = dynamic_cast<Button*>(levelChoose->getChildByName("btnGameMenu"));
	btnMenu->addTouchEventListener(this, toucheventselector(MenuScene::touchButton));

}

void LevelChooseLayer::initLevelButton(int levelNum)
{
	char levelNumber[32] = { 0 };
	sprintf(levelNumber, "level%d", levelNum);
	char levelName[32] = { 0 };
	sprintf(levelName, "level_%d", levelNum);
	char UnlevelName[32] = { 0 };
	sprintf(UnlevelName, "level_unable_%d", levelNum);

	char getLevelDate[32] = { 0 };
	sprintf(getLevelDate, "level%d-%d", m_currentStage, levelNum);


	auto level = dynamic_cast<Widget*>(levelChoose->getChildByName(levelNumber)->getChildByName(levelName));
	auto levelUnable = dynamic_cast<Widget*>(levelChoose->getChildByName(levelNumber)->getChildByName(UnlevelName));
	auto btnLevel = dynamic_cast<Button*>(level->getChildByName("btn"));
	auto btnUnLevel = dynamic_cast<Button*>(levelUnable->getChildByName("btn"));
	auto oneStar = dynamic_cast<Widget*>(btnLevel->getChildByName("one_star"));
	auto twoStars = dynamic_cast<Widget*>(btnLevel->getChildByName("two_stars"));
	auto threeStars = dynamic_cast<Widget*>(btnLevel->getChildByName("three_stars"));

	oneStar->setVisible(false);
	twoStars->setVisible(false);
	threeStars->setVisible(false);

	switch (GameState::getLevelDate(getLevelDate))
	{
	case 0:{
			   level->setVisible(false);
			   levelUnable->setVisible(true);
			   break;
	}
	case 1:{
			   level->setVisible(true);
			   oneStar->setVisible(true);
			   levelUnable->setVisible(false);
			   break;
	}
	case 2:{
			   level->setVisible(true);
			   twoStars->setVisible(true);
			   levelUnable->setVisible(false);
			   break;
	}
	case 3:{
			   level->setVisible(true);
			   threeStars->setVisible(true);
			   levelUnable->setVisible(false);
			   break;
	}
	case 4:{
			   level->setVisible(true);
			   levelUnable->setVisible(false);
			   break;
	}
	default:
		break;
	} 
	btnLevel->addTouchEventListener(this, toucheventselector(LevelChooseLayer::touchButton));
 
}

void LevelChooseLayer::touchButton(cocos2d::Ref *object, cocos2d::ui::TouchEventType type)
{
	if (type == TOUCH_EVENT_ENDED)
	{
		auto widget = dynamic_cast<Widget*>(object);
		auto name = widget->getParent()->getName();
		if (name.compare("level_1") == 0)
		{
			g_current_level = 1;
			GameLayerControl::changeScene(GameLayerControl::GameMainScene);
		}
		else if (name.compare("level_2") == 0)
		{
			g_current_level = 2;
			GameLayerControl::changeScene(GameLayerControl::GameMainScene);
		}
		else if (name.compare("level_3") == 0)
		{
			g_current_level = 3;
			GameLayerControl::changeScene(GameLayerControl::GameMainScene);
		}
		else
		{
			CCLOG("no unlocked");
		}
		
	}
}



