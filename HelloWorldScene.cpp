#include "HelloWorldScene.h"
#include"DialogLayer\DialogLayer.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


  

	DialogLayer*dialogLayer = DialogLayer::createWithJsonFile("1.json");
	this->addChild(dialogLayer, 3);

    
    return true;
}

