#ifndef __TowerWar_MenuScene__
#define __TowerWar_MenuScene__
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "ConstUtil.h"
#include "GameLayerControl.h"
#include "GameState.h"

class MenuScene : public cocos2d::Scene
{
public:

	static cocos2d::Scene* createScene(cocos2d::Layer*pLayer);
	//CREATE_FUNC(MenuScene);

	void touchButton(Ref *object, cocos2d::ui::TouchEventType type);

private:


};

#endif 
