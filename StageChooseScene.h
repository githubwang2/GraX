//
//	StageChooseScene.h
//
//	TowerWar
//
//	Create by wang2 on	17-1-29
//
#ifndef __TowerWar_StageChooseScene__
#define __TowerWar_StageChooseScene__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;



//
const int STAGE_MAX = 4;


class StageChooseScene:public Layer
{
public:
	static Scene*createScene();
	virtual bool init();
	CREATE_FUNC(StageChooseScene);

	void addBackgroundSprite();

	void addButton(char*name);

	void touchButton(Ref *object, TouchEventType type);
private:
	Size visibleSize;

	Widget* stageChoose;

};

#endif