//
//	AboutScene.h
//
//	TowerWar
//
//	Create by wang2 on	17-1-27
//
#ifndef __TowerWar_AboutScene__
#define __TowerWar_AboutScene__
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;

class AboutScene : public Layer
{
public:

	static cocos2d::Scene* createScene();
	virtual bool init();
	void initAboutScene();
	void touchButton(Ref *object, TouchEventType type);

	CREATE_FUNC(AboutScene);

private:
	Size visibleSize;
};

#endif 
