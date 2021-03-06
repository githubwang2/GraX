#include "Scene/MenuScene.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;

Scene* MenuScene::createScene(Layer*pLayer)
{
	auto scene = Scene::create();
	if ( nullptr!=pLayer){
		scene->addChild(pLayer);
	}
	return scene;
}

void MenuScene::touchButton(Ref *object, TouchEventType type){
	if (type == TOUCH_EVENT_ENDED)
	{
		auto widget = dynamic_cast<Widget*>(object);
		auto name = widget->getName();
		if (name.compare(BTN_START) == 0)
		{
			GameLayerControl::changeScene(GameLayerControl::StageChooseLayerState);
		}
		else if (name.compare(BTN_DEX) == 0)
		{
			GameLayerControl::changeScene(GameLayerControl::DexLayerState);
		}
		else if (name.compare(BTN_RESTART) == 0)
		{
			UserDefault::getInstance()->setBoolForKey("is_init", false);
			GameState::initGameState();
		}
		else if (name.compare(BTN_SETTING) == 0)
		{
			GameLayerControl::changeScene(GameLayerControl::SetttingLayerState);
		}
		else if (name.compare(BTN_ABOUT) == 0)
		{
			GameLayerControl::changeScene(GameLayerControl::AboutSLayerState);
		}
		else if (name.compare(BTN_MENU) == 0)
		{
			GameLayerControl::changeScene(GameLayerControl::MenuLayerState);
		}
		else 
		{
			GameLayerControl::changeScene(GameLayerControl::EndState);
		}
	}
}