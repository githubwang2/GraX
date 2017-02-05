//
//	MenuScene.h
//
//	TowerWar
//
//	Create by wang2 on	17-1-25
//
#ifndef __TowerWar_MenuScene__
#define __TowerWar_MenuScene__
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include"ConstUtil.h"

class MenuScene : public cocos2d::Layer
{
public:

	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(MenuScene);

private:
	void initMenuBG();

	void initMenuBtn(char*btnName);

	void touchButton(Ref *object, cocos2d::ui::TouchEventType type);

	cocos2d::ui::Widget*menuScene;
	cocos2d::Size visibleSize;
};

#endif 
