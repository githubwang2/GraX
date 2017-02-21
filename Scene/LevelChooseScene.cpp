#include"Scene/LevelChooseScene.h"
#include"Layer/StageChooseLayer.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;

Scene* LevelChooseScene::createScene(Layer*pLayer)
{
	auto scene = Scene::create();
	Layer* layer = pLayer;
	scene->addChild(layer);
	return scene;
}

