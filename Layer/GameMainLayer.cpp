#include"Layer/GameMainLayer.h"

USING_NS_CC;
using namespace cocostudio;
using namespace ui;

HUDLayer*GameMainLayer::hudLayer;
FireManager*GameMainLayer::fileManager;

GameMainLayer* GameMainLayer::create()
{
	GameMainLayer*gameMainLayer = new GameMainLayer();
	if (gameMainLayer && gameMainLayer->init())
	{
		gameMainLayer->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(gameMainLayer);
	}
	return gameMainLayer;
}

bool GameMainLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	m_currentStage = StageChooseLayer::s_current_stage;
	m_currentLevel = LevelChooseLayer::s_current_level;
	
	
	beginHp = 5;
	level = 1;
	level_WavNum = 10;
	beginGold = 300; 

	//-------------------------------------------------------------------------
	//					background
	initBG();
	//------------------------------------------------------------------------
	//					HUD
	hudLayer = HUDLayer::create();
	hudLayer->setInitHUD(beginGold, level_WavNum, beginHp);
	addChild(hudLayer, 3);
	//------------------------------------------------------------------------
	//					TileMap
	char tmxtilePath[50] = { 0 };
	sprintf(tmxtilePath, "GameMain/stage%d/level%d-%d/level.tmx", m_currentStage, m_currentStage, m_currentLevel);
	auto gameMap = GameMap::createTMXTiledMap(tmxtilePath);
	addChild(gameMap);
	//-------------------------------------------------------------------------
	//					Tower触摸响应
	attachTowerBuild(gameMap);
	//-------------------------------------------------------------------------
	//					怪物产生
	schedule(schedule_selector(GameMainLayer::addMonster), 1.5f);
	//-------------------------------------------------------------------------
	//					FileManager
	fileManager = FireManager::create();
	addChild(fileManager);
	return true;
}

void GameMainLayer::initBG(){
	char bgPath[50] = { 0 };
	sprintf(bgPath, "GameMain/stage%d/level%d-%d/background.png", m_currentStage, m_currentStage, m_currentLevel);
	auto spriteBG = Sprite::create(bgPath);
	spriteBG->setPosition(visibleSize / 2);
	spriteBG->setScale(visibleSize.width / spriteBG->getContentSize().width,
		visibleSize.height / spriteBG->getContentSize().height);
	addChild(spriteBG, -1);
}

void GameMainLayer::addMonster(float dt){
	addChild(Monster::create(1),1);
	
}

void GameMainLayer::attachTowerBuild(GameMap *gameMap){
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = [=](Touch *pTouch, Event *pEvent){return true; };
	listener->onTouchEnded = [=](Touch *pTouch, Event *pEvent){
		auto touchPos = pTouch->getLocation();
		auto tower = Tower::createTower(touchPos, gameMap);
		addChild(tower);
		//std::string str = gameMap->getTowerValue(touchPos);
		//CCLOG("%s", str.c_str());
		//--------------------text---------------
	};

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

int  GameMainLayer::changeGold(int i)
{
	int currentGold= hudLayer->changeGold(i);
	return currentGold;
}

int GameMainLayer::changeLife(int num)
{
	int currentLife = hudLayer->changeLife(num);
	return currentLife;
}

void GameMainLayer::goldWarn()
{
	hudLayer->goldWarn();
}

//void GameMainLayer::endGame(bool isWin){
//	auto poppup = new PopupLayer();
//
//	if (isWin)
//	{
//		int starsNum;
//		if (HUDLayer::changeLife(0) == m_beginHp)
//		{
//			starsNum = 3;
//		}
//		else if (m_beginHp / 2<HUDLayer::changeLife(0) < m_beginHp)
//		{
//			starsNum = 2;
//		}
//		else
//		{
//			starsNum = 1;
//		}
//		addChild(poppup->setResult(starsNum, m_level), 3);
//		this->unscheduleAllSelectors();
//	}
//	else
//	{
//		addChild(poppup->setResult(0, m_level), 3);
//		this->unscheduleAllSelectors();
//	}
//}

//void GameMainLayer::removeMonster(Node* monster)
//{//可以考虑移到comMove中去
//	auto comMove = dynamic_cast<ComMove*>(monster->getComponent("ComMove"));
//	m_fireManager->m_tmpMonster.push_back(comMove);
//}

void GameMainLayer::removeMonster(Node*monster){
	auto comMove = dynamic_cast<ComMove*>(monster->getComponent("ComMove"));
	fileManager->m_tmpMonster.push_back(comMove);
}