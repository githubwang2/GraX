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


//bool StartScene::init()
//{
//	if (!Scene::init())
//	{
//		return false;
//	}
//	splashLayer = SplashLayer::create();
//	return true;
//}

