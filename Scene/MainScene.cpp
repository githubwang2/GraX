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

	
	
	SpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("DialogLayer/face1.plist");

	initBG();
	a = new GameMap();
	auto aaa = a->createTMXTiledMap("asa");
	addChild(aaa);
	attachTowerBuild();
	//auto dialogLayer=DialogLayer::createWithJsonFile("DialogLayer/0-1.json");
	//this->addChild(dialogLayer, 3);
	return true;
}

void MainScene::initBG(){
	auto spriteBG = Sprite::create("Tower/background.png");
	spriteBG->setPosition(visibleSize / 2);
	spriteBG->setScale(visibleSize.width / spriteBG->getContentSize().width,
		visibleSize.height / spriteBG->getContentSize().height);
	addChild(spriteBG, -1);
}

void MainScene::attachTowerBuild(){
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = [=](Touch *pTouch, Event *pEvent){return true; };
	listener->onTouchEnded = [=](Touch *pTouch, Event *pEvent){
		
		
		auto touchPos = pTouch->getLocation();
		std::string str = a->getTowerValue(touchPos);
		CCLOG("%s", str);
	};

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}
