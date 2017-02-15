#include "LoadingScene.h"
#include "Scene/MenuScene.h"
#include"ConstUtil.h"

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
	
	load();
	
	return true;
}

void LoadingScene::gotoMenuScene(){
	Director::sharedDirector()->replaceScene(TransitionFade::create(2, MenuScene::createScene()));
}

void LoadingScene::playOP(){
	auto sprite = Sprite::create();
	Animation*animation = Animation::create();
	char buf[32] = { 0 };
	for (int i = 1; i < 182; i++)
	{
		sprintf(buf, "op/OP%d.JPG", i);
		
		animation->addSpriteFrameWithFileName(buf);
		log("path name is:%s", buf);
	}
	
	animation->setDelayPerUnit(0.08f);
	//
	auto act = Sequence::create(Animate::create(animation), 
		CallFunc::create(CC_CALLBACK_0(LoadingScene::gotoMenuScene,this)), nullptr);
	sprite->runAction(act);
	sprite->setPosition(visibleSize / 2);
	addChild(sprite, 1);
}

void LoadingScene::load(){
	loadLabel = LabelTTF::create("Loading..", "Arial", 20);			//创建显示Loading: 的label
	loadLabel->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2 + 30));
	this->addChild(loadLabel, 1);

	auto loadBg = Sprite::create(PROGRESSBAR_BG);				//进度条底图
	loadBg->setPosition(Point(visibleSize / 2));
	addChild(loadBg, 0);
	
	loadProgress = ProgressTimer::create(Sprite::create(PROGRESS_BAR));
	loadProgress->setBarChangeRate(Point(1, 0));					//设置进程条的变化速率
	loadProgress->setType(ProgressTimer::Type::BAR);				//设置进程条的类型
	loadProgress->setMidpoint(Point(0, 1));							//设置进度的运动方向
	loadProgress->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	loadProgress->setPercentage(0.0f);								//设置初始值为0
	this->addChild(loadProgress, 1);

	for (int i = 1; i < 182;i++)
	{
		char buf[32] = { 0 };
		sprintf(buf, "op/OP%d.JPG", i);
		CCLOG("name is:%s", buf);
		Director::getInstance()->getTextureCache()->addImageAsync(buf, CC_CALLBACK_1(LoadingScene::loadingCallBack, this));
	}
}

void LoadingScene::loadingCallBack(cocos2d::Texture2D *texture)
{
	++_numberOfLoadedSprites;

	float newPercent = 100 - ((float)_numberOfSprites - (float)_numberOfLoadedSprites) / ((float)_numberOfSprites / 100);//计算进度条当前的百分比

	loadProgress->setPercentage(newPercent);//更新进度

	char buf[32] = { 0 };
	sprintf(buf, "Loading.. %d%%", (int)newPercent);
	loadLabel->setString(buf);

	CCLOG("%d",_numberOfLoadedSprites);
	//图片加载完成
	if (_numberOfLoadedSprites == _numberOfSprites)
	{
		loadLabel->setString("all loaded");
		playOP();
	}
}