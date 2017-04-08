#include "LoadingLayer.h"
#include "Scene/MenuScene.h"
#include "GameLayerControl.h"
#include "ConstUtil.h"

#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

USING_NS_CC;

bool LoadingLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	_allOfSprites = 13;
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	_allOfSprites = 194;
#endif
	_numberOfLoadedSprites = 0;

	visibleSize = Director::getInstance()->getVisibleSize();

	load();
	
	return true;
}

void LoadingLayer::gotoMenuScene(){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
#endif
	GameLayerControl::changeScene(GameLayerControl::MenuLayerState);
}

void LoadingLayer::playOP(){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	experimental::ui::VideoPlayer* videoPlayer = experimental::ui::VideoPlayer::create();

	videoPlayer->setPosition(Point(visibleSize.width / 2, visibleSize.height/2));
	videoPlayer->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	videoPlayer->setContentSize(Size(visibleSize.width, visibleSize.height));
	videoPlayer->setFileName("Videos/op.mp4");
	videoPlayer->play();
	this->addChild(videoPlayer,5);
	videoPlayer->addEventListener(CC_CALLBACK_2(LoadingLayer::videoEventCallback, this));  
	endOP();
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("op/op.mp3");
	auto sprite = Sprite::create();
	Animation*animation = Animation::create();
	char buf[32] = { 0 };
	for (int i = 1; i < 182; i++)
	{
		sprintf(buf, "op/OP%d.JPG", i);
		//sprintf(buf, "op2/OP (%d).JPG", i);
		//CCLOG("path name is:%s", buf);
		animation->addSpriteFrameWithFileName(buf);
	}

	animation->setDelayPerUnit(0.08f);
	auto act = Sequence::create(Animate::create(animation),
		CallFunc::create(CC_CALLBACK_0(LoadingLayer::gotoMenuScene, this)), nullptr);
	sprite->runAction(act);
	sprite->setPosition(visibleSize / 2);
	SimpleAudioEngine::getInstance()->playBackgroundMusic("op/op.mp3");
	endOP();

	addChild(sprite, 1);
#endif
}

void LoadingLayer::load(){
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

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	for (int i = 0; i < 181; i++)
	{
		char buf[32] = { 0 };
		sprintf(buf, "op/OP%d.JPG", i + 1);
		//CCLOG("name is:%s", buf);
		Director::getInstance()->getTextureCache()->addImageAsync(buf, CC_CALLBACK_1(LoadingLayer::loadingCallBack, this));
	}
#endif
	
	ADD_CACHE("MenuScene/key_1.png", CC_CALLBACK_1(LoadingLayer::loadingCallBack, this));
	ADD_CACHE("MenuScene/key_2.png", CC_CALLBACK_1(LoadingLayer::loadingCallBack, this));
	ADD_CACHE("MenuScene/key_3.png", CC_CALLBACK_1(LoadingLayer::loadingCallBack, this));
	ADD_CACHE("MenuScene/key_4.png", CC_CALLBACK_1(LoadingLayer::loadingCallBack, this));
	ADD_CACHE("MenuScene/key_bg.jpg", CC_CALLBACK_1(LoadingLayer::loadingCallBack, this));
	ADD_CACHE("MenuScene/key_bg_50.png", CC_CALLBACK_1(LoadingLayer::loadingCallBack, this));
	ADD_CACHE("MenuScene/GameAbout.png", CC_CALLBACK_1(LoadingLayer::loadingCallBack, this));
	ADD_CACHE("MenuScene/GameEnd.png", CC_CALLBACK_1(LoadingLayer::loadingCallBack, this));
	ADD_CACHE("MenuScene/restart.png", CC_CALLBACK_1(LoadingLayer::loadingCallBack, this));
	ADD_CACHE("MenuScene/return.png", CC_CALLBACK_1(LoadingLayer::loadingCallBack, this));
	ADD_CACHE("MenuScene/GameStart.png", CC_CALLBACK_1(LoadingLayer::loadingCallBack, this));
	ADD_CACHE("MenuScene/dex.png", CC_CALLBACK_1(LoadingLayer::loadingCallBack, this));
	ADD_CACHE("MenuScene/Setting.png", CC_CALLBACK_1(LoadingLayer::loadingCallBack, this));
	//SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Sounds/BG_1.mid");
	//SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Sounds/BG_3.mid");
	//SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Sounds/BG_6.mid");
	//SimpleAudioEngine::sharedEngine()->preloadEffect("Sounds/MenuSelect.mp3");
	//SimpleAudioEngine::sharedEngine()->preloadEffect("Sounds/BuyItem.mp3");
	//SimpleAudioEngine::sharedEngine()->preloadEffect("Sounds/Bomb.mp3");
	//SimpleAudioEngine::sharedEngine()->preloadEffect("Sounds/ME_1.mid");
	//SimpleAudioEngine::sharedEngine()->preloadEffect("Sounds/ME_2.mid");
	//SimpleAudioEngine::sharedEngine()->preloadEffect("Sounds/ME_3.mid");
	//SimpleAudioEngine::sharedEngine()->preloadEffect("Sounds/ME_4.mid");
}

void LoadingLayer::loadingCallBack(cocos2d::Texture2D *texture)
{
	++_numberOfLoadedSprites;

	float newPercent = 100 - ((float)_allOfSprites - (float)_numberOfLoadedSprites) / ((float)_allOfSprites / 100);//计算进度条当前的百分比

	loadProgress->setPercentage(newPercent);//更新进度

	char buf[32] = { 0 };
	sprintf(buf, "Loading.. %d%%", (int)newPercent);
	loadLabel->setString(buf);

	//CCLOG("%d", _numberOfLoadedSprites);
	//图片加载完成
	if (_numberOfLoadedSprites == _allOfSprites)
	{
		loadLabel->setString("all loaded");
		playOP();
	}
}

void LoadingLayer::endOP()
{
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [=](Touch *pTouch, Event *pEvent){
		gotoMenuScene();
		return true; };
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
void LoadingLayer::videoEventCallback(Ref* sender, experimental::ui::VideoPlayer::EventType eventType){
	switch (eventType) {
	case cocos2d::experimental::ui::VideoPlayer::EventType::PLAYING:
		break;
	case cocos2d::experimental::ui::VideoPlayer::EventType::PAUSED:
		gotoMenuScene();
	case cocos2d::experimental::ui::VideoPlayer::EventType::STOPPED:
		break;
	case cocos2d::experimental::ui::VideoPlayer::EventType::COMPLETED:
		gotoMenuScene();
		break;
	default:
		break;
	}
}
#endif