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
	//-----------------当前stage和level----------------
	m_currentStage = StageChooseLayer::g_current_stage;
	m_currentLevel = LevelChooseLayer::g_current_level;

	/*auto _is = FileUtils::getInstance()->isFileExist("DialogLayer/0-1.json");
	if (_is)
	{
		auto dialogLayer = DialogLayer::createWithJsonFile("DialogLayer/0-1.json");
		addChild(dialogLayer, 3);
		
	}
*/
	startGame();
	
	return true;
}

void GameMainLayer::startGame()
{
	SoundsControl::setBGM(SoundsControl::BGMState::MainGameBGM);
	wavesMessage = new WavesMessage(m_currentStage, m_currentLevel);
	beginHp = wavesMessage->m_beginHp;
	beginGold = wavesMessage->m_beginGold;
	level_WavNum =wavesMessage->m_numOfWav;
	curWacNum = 0;
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
	//					TowerButton
	TowerButton*towerButton = TowerButton::getInstance();
	addChild(towerButton, 3);
	attachTowerBuild(gameMap);
	//-------------------------------------------------------------------------
	//					怪物波数刷新
	//createWaveRusher();
	//-------------------------------------------------------------------------
	//					FileManager
	fileManager = FireManager::create();
	addChild(fileManager,2);//因为autorealse的关系  所以一开始没调用自动-1 这里+1

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
	if (curWacNum <level_WavNum)
	{
		//monsterCreateLeft = 1 + curWacNum * increase_monste;
		wavesMessage->setCurNo(curWacNum);
		monsterCreateLeft = wavesMessage->getCurMonsterNum();
	
		hudLayer->createWaveRusher();       //hud中当前波数+1
		schedule(schedule_selector(GameMainLayer::addMonster), wavesMessage->getMonsterInterval());
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
			runAction(Sequence::create(DelayTime::create(
				wavesMessage->getWaveInteval()),
				CallFunc::create([=](){
				curWacNum++;                        //波数+1
				createWaveRusher();
			})
				, nullptr));
		}
	}
	addChild(Monster::create(wavesMessage->getCurMonsterId()), 1);
}

void GameMainLayer::attachTowerBuild(GameMap *gameMap){
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = [=](Touch *pTouch, Event *pEvent){return true; };
	listener->onTouchEnded = [=](Touch *pTouch, Event *pEvent){
		auto touchPos = pTouch->getLocation();
		//auto tower = Tower::createTower(touchPos, gameMap);
		//addChild(tower);
		TowerButton*towerButton = TowerButton::getInstance();
		
		//towerButton->setGameMap(gameMap);
		towerButton->ableToCreat(touchPos, gameMap);
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
	//先停下所有
	fileManager->endMoveBullet();
	fileManager->unscheduleAllSelectors();
	this->unscheduleAllSelectors();
	for (auto monster:fileManager->m_monsters)
	{
		monster->getOwner()->stopAllActions();
	}
	//fileManager->unschedule(schedule_selector(FireManager::moveBullet));

	ResultLayer*resultLayer;
	if (isWin)
	{
		int starsNum;
		if (hudLayer->changeLife(0) == beginHp)
		{
			starsNum = 3;
		}
		else if (beginHp / 2 < hudLayer->changeLife(0) && hudLayer->changeLife(0)< beginHp)
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
		char nextLevelName[32] = { 0 };
		if (m_currentLevel == MAX_LEVEL)
		{
			sprintf(nextLevelName, "level%d-%d", m_currentStage+1, 1);
			GameState::setLevelDate(nextLevelName, 4);
		}
		else
		{
			sprintf(nextLevelName, "level%d-%d", m_currentStage , m_currentLevel+1);
			GameState::setLevelDate(nextLevelName, 4);
		}
		if (m_currentLevel == MAX_LEVEL)
		{
			char stageNum[32] = { 0 };
			sprintf(stageNum, "Stage%d", m_currentStage+1);
			GameState::setStageDate(stageNum);
		}
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