#include "Scene/MenuScene.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;

Scene* MenuScene::createScene(Layer*pLayer)
{
	auto scene = Scene::create();
	Layer* layer = pLayer;
	scene->addChild(layer);
	return scene;
}


void MenuScene::touchButton(Ref *object, TouchEventType type){
	if (type == TOUCH_EVENT_ENDED)
	{
		auto widget = dynamic_cast<Widget*>(object);
		auto name = widget->getName();
		if (name.compare(BTN_START) == 0)
		{
			GameSceneControl::changeScene(GameSceneControl::MainSceneState);
		}
		else if (name.compare(BTN_SETTING) == 0)
		{
			GameSceneControl::changeScene(GameSceneControl::SetttingSceneState);
		}
		else if (name.compare(BTN_ABOUT) == 0)
		{
			GameSceneControl::changeScene(GameSceneControl::AboutSceneState);
		}
		else if (name.compare(BTN_MENU) == 0)
		{
			GameSceneControl::changeScene(GameSceneControl::MenuSceneState);
		}
		else 
		{
			GameSceneControl::changeScene(GameSceneControl::EndState);
		}
	}
}