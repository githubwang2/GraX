#include "AppDelegate.h"
#include "Scene/StartScene.h"
#include "Scene/GameMainScene.h"
#include "Layer/GameMainLayer.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");

        director->setOpenGLView(glview);
	}
	//glview->setFrameSize(1280, 720);
	glview->setDesignResolutionSize(960, 680, ResolutionPolicy::EXACT_FIT);

    director->setDisplayStats(true);
    director->setAnimationInterval(1.0 / 60);

	auto scene = GameMainScene::createScene();
	director->runWithScene(scene);
	//auto scene = StartScene::create();
	//scene->gameStart();
	
    return true;
}

void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
}

void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
}
