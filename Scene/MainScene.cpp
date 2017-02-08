#include "Scene/MainScene.h"
#include "DialogLayer/DialogLayer.h"

USING_NS_CC;

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
	//--------------------------------------
	hud = new HUDLayer();
	addChild(hud->createHUDLayer());
	//------------------------------------------------------------------------
	SpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("DialogLayer/face1.plist");
	//auto dialogLayer=DialogLayer::createWithJsonFile("DialogLayer/0-1.json");
	//this->addChild(dialogLayer, 3);

	initBG();

	//------------------------------------------------
	gameMap = new GameMap();
	addChild(gameMap->createTMXTiledMap("Tower/TowerTileMap/gate2.tmx"));
	std::vector<Point> pathVec = gameMap->getWalkPath("Walk");
	for (auto pos : pathVec)
	{
		int myX = pos.x;
		int myY = pos.y;
		CCLOG("find the pos x:%d\ty:%d", myX, myY);
	}
	attachTowerBuild();
	
	return true;
}



void MainScene::attachTowerBuild(){
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = [=](Touch *pTouch, Event *pEvent){return true; };
	listener->onTouchEnded = [=](Touch *pTouch, Event *pEvent){
		auto touchPos = pTouch->getLocation();
		std::string str = gameMap->getTowerValue(touchPos);
		CCLOG("%s", str.c_str());
		//--------------------text---------------
		hud->changeGold(10);
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