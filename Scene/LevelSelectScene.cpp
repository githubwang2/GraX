#include"Scene/LevelSelectScene.h"
#include"Layer/StageChooseLayer.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;

Scene*LevelSelectScene::createScene(){
	auto scene = Scene::create();
	auto layer =StageChooseLayer::create();
	scene->addChild(layer);
	return scene;
}
bool LevelSelectScene::init(){
	if (!Layer::init())
	{
		return false;
	}

	//visibleSize = Director::getInstance()->getWinSize();

	return true;
}


