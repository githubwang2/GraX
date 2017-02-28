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
		//gameMainLayer->retain();
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

	startGame();

	return true;
}

void GameMainLayer::startGame()
{
	m_currentStage = StageChooseLayer::g_current_stage;
	m_currentLevel = LevelChooseLayer::g_current_level;

	beginHp = 5;
	level = 1;
	level_WavNum = m_currentLevel*3+m_currentStage*2;
	curWacNum = 0;
	beginGold = 300;

	monsterCreateLeft = 0;
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
	//					怪物波数刷新
	createWaveRusher();
	//-------------------------------------------------------------------------
	//					FileManager
	fileManager = FireManager::create();
	addChild(fileManager);

	scheduleUpdate();
}

void GameMainLayer::initBG(){
	char bgPath[50] = { 0 };
	sprintf(bgPath, "GameMain/stage%d/level%d-%d/background.png", m_currentStage, m_currentStage, m_currentLevel);
	CCLOG("%s", bgPath);
	auto spriteBG = Sprite::create(bgPath);
	spriteBG->setPosition(visibleSize / 2);
	spriteBG->setScale(visibleSize.width / spriteBG->getContentSize().width,
		visibleSize.height / spriteBG->getContentSize().height);
	addChild(spriteBG, -1);
}

void GameMainLayer::update(float dt)
{
	auto curLife = changeLife(0);
	if (curLife<=0)
	{
		endGame(false);
	}
	if (curWacNum >= level_WavNum)
	{
		if (fileManager->m_monsters.size() == 0)
		{
			unschedule(schedule_selector(GameMainLayer::addMonster));
			endGame(true);
		}
		return;
	}
}

void GameMainLayer::createWaveRusher()
{
	//--无限模式
	if (curWacNum <level_WavNum)
	{
		monsterCreateLeft = 1 + curWacNum * increase_monste;
		hudLayer->createWaveRusher();       //hud中当前波数+1
	schedule(schedule_selector(GameMainLayer::addMonster), interval_time);
	}
}

void GameMainLayer::addMonster(float dt){
	monsterCreateLeft--;                //需要产生monster-1
	if (level_WavNum == curWacNum&&monsterCreateLeft == 0)
	{
		unschedule(schedule_selector(GameMainLayer::addMonster));
	}
	else
	{
		if (monsterCreateLeft == 0)
		{
			unschedule(schedule_selector(GameMainLayer::addMonster));
			runAction(Sequence::create(DelayTime::create(wave_interal),
				CallFunc::create([=](){
				curWacNum++;                        //波数+1
				
				createWaveRusher();
			})
				, nullptr));
		}
	}
	addChild(Monster::create(curWacNum), 1);
}

void GameMainLayer::attachTowerBuild(GameMap *gameMap){
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = [=](Touch *pTouch, Event *pEvent){return true; };
	listener->onTouchEnded = [=](Touch *pTouch, Event *pEvent){
		auto touchPos = pTouch->getLocation();
		auto tower = Tower::createTower(touchPos, gameMap);
		addChild(tower);
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

void GameMainLayer::endGame(bool isWin){
	ResultLayer*resultLayer;
	if (isWin)
	{
		int starsNum;
		if (hudLayer->changeLife(0) == beginHp)
		{
			starsNum = 3;
		}
		else if (beginHp / 2 < hudLayer->changeLife(0) < beginHp)
		{
			starsNum = 2;
		}
		else
		{
			starsNum = 1;
		}
		resultLayer = ResultLayer::createLayer(starsNum, m_currentLevel);
		this->unscheduleAllSelectors();
		//写入存档
		char levelName[32] = { 0 };
		sprintf(levelName, "level%d-%d",m_currentStage,m_currentLevel);
		GameState::setLevelDate(levelName, starsNum);
	}
	else
	{
		resultLayer = ResultLayer::createLayer(0, m_currentLevel);
		this->unscheduleAllSelectors();
	}
	addChild(resultLayer, 5);
}

void GameMainLayer::removeMonster(Node*monster){
	auto comMove = dynamic_cast<ComMove*>(monster->getComponent("ComMove"));
	fileManager->m_tmpMonster.push_back(comMove);
}