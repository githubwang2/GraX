#include "AppDelegate.h"
#include "Scene/MenuScene.h"
#include "Scene/LevelSelectScene.h"
#include "GameState.h"
#include "Layer/PopupLayer.h"
#include "Scene/GameMainScene.h"
#include "Layer/MenuLayer.h"
#include "GameMap.h"
#include "Scene/StartScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }

    director->setDisplayStats(true);

    director->setAnimationInterval(1.0 / 60);

	auto layer = MenuLayer::create();
	auto scene = MenuScene::createScene(layer);
	director->runWithScene(scene);
	//auto scene = StartScene::create();
	//scene->gameStart();
	

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
