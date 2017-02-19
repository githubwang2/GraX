#include "Layer/DialogLayer.h"
#include "Scene/MainScene.h"
//#include "Sprite/Monster.h"
//#include "Sprite/Tower.h"
#include"Layer/PopupLayer.h"

USING_NS_CC;
using namespace cocostudio;
using namespace ui;

Scene* MainScene::createScene()
{
	auto scene = Scene::create();
	auto layer = MainScene::create();
	scene->addChild(layer);
	return scene;
}

bool MainScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	m_beginHp = 5;
	m_level = 1;
	m_level_WavNum = 10;
	m_beginGold = 300;
	//------------------------------------------------------------------------
	//					HUD
	HUDLayer::createHUDLayer();
	HUDLayer::setInitHUD(m_beginGold, m_level_WavNum, m_beginHp);
	addChild(HUDLayer::getHud() , 3);
	//------------------------------------------------------------------------
	//					TileMap
	gameMap = new GameMap();
	addChild(gameMap->createTMXTiledMap("Tower/TowerTileMap/gate1.tmx"));
	//-------------------------------------------------------------------------
	//					background
	initBG();
	//-------------------------------------------------------------------------
	//					Dialog
	/*SpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("DialogLayer/
	.plist");
	auto dialogLayer=DialogLayer::createWithJsonFile("DialogLayer/0-1.json");
	this->addChild(dialogLayer, 3);*/
	//-------------------------------------------------------------------------
	//					Tower触摸响应
	attachTowerBuild();
	//-------------------------------------------------------------------------
	//					怪物产生
	schedule(schedule_selector(MainScene::addMonster), 1.5f);

	

	return true;
}

void MainScene::addMonster(float dt){
	//Monster1*monster1=new Monster1();
	//Monster*monster = new Monster(1);
	//addChild(monster->createMonster(),1);
}

void MainScene::attachTowerBuild(){
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = [=](Touch *pTouch, Event *pEvent){return true; };
	listener->onTouchEnded = [=](Touch *pTouch, Event *pEvent){
		auto touchPos = pTouch->getLocation();
		//Tower*tower = new Tower();
		//addChild(tower->createTower(touchPos, gameMap));
		//std::string str = gameMap->getTowerValue(touchPos);
		//CCLOG("%s", str.c_str());
		//--------------------text---------------
	};

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

void MainScene::initBG(){
	auto spriteBG = Sprite::create("Tower/background.png");
	spriteBG->setPosition(visibleSize / 2);
	spriteBG->setScale(visibleSize.width / spriteBG->getContentSize().width,
		visibleSize.height / spriteBG->getContentSize().height);
	addChild(spriteBG, -1);
}

void MainScene::endGame(bool isWin){
	auto poppup = new PopupLayer();

	if (isWin)
	{
		int starsNum;
		if (HUDLayer::changeLife(0)==m_beginHp)
		{
			starsNum = 3;
		}
		else if (m_beginHp/2<HUDLayer::changeLife(0) < m_beginHp)
		{
			starsNum = 2;
		}
		else 
		{
			starsNum = 1;
		}
		addChild(poppup->setResult(starsNum, m_level),3);
		this->unscheduleAllSelectors();
	}
	else
	{
		addChild(poppup->setResult(0, m_level), 3);
		this->unscheduleAllSelectors();
	}
}

void MainScene::removeMonster(Node* monster)
{//可以考虑移到comMove中去
	/*auto comMove = dynamic_cast<ComMove*>(monster->getComponent("ComMove"));
	m_fireManager->m_tmpMonster.push_back(comMove);*/
}