#include "LoadingScene.h"


USING_NS_CC;

Scene* LoadingScene::createScene()
{
	auto scene = Scene::create();
	auto layer = LoadingScene::create();
	scene->addChild(layer);
	return scene;
}

bool LoadingScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	currentNum = 0;  
	totalNum = 500;

	m_pLabelLoading = CCLabelTTF::create("Loading...", "Arial", 25);
	m_pLabelPercent = CCLabelTTF::create("0%", "Arial", 25);

	m_pLabelLoading->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 3 + 50));
	m_pLabelPercent->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 3));

	this->addChild(m_pLabelLoading);
	this->addChild(m_pLabelPercent);



	run();



	return true;
}

void LoadingScene::run(){
	auto sprite = Sprite::create();
	Animation*animation = Animation::create();
	char buf[32] = { 0 };
	for (int i = 0; i < 12;i++)
	{
		sprintf(buf, "run/%d.png", (i + 1));
		animation->addSpriteFrameWithFile(buf);
		log("path name is:%s", buf);
	}
	
	animation->setDelayPerUnit(0.08f);
	sprite->runAction(RepeatForever::create(Animate::create(animation)));
	sprite->setPosition(visibleSize / 2);
	addChild(sprite, 1);
}

