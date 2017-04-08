#include"Scene/StartScene.h"

USING_NS_CC;

void StartScene::gameStart()
{
	auto layer = SplashLayer::create();
	if (nullptr != layer)
	{
		this->addChild(layer);
		Director::getInstance()->runWithScene(this);
	}
}

void StartScene::gameLoading()
{
	auto layer = LoadingLayer::create();
	if (nullptr != layer)
	{
		this->removeAllChildren();
		this->addChild(layer);
		Director::getInstance()->replaceScene(this);
	}
}
