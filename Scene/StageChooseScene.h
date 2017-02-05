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
#include "ui/CocosGUI.h"

#include"ConstUtil.h"

class StageChooseScene:public cocos2d::Layer
{
public:
	static cocos2d::Scene*createScene();
	virtual bool init();
	CREATE_FUNC(StageChooseScene);

	void test(float dt);
private:
	//
	void addBackgroundSprite();
	//ScrollView滑动校正
	void adjustScrollView();
	//添加stage   
	cocos2d::ui::Button* addButton(char*name);
	//stage的按键回调
	void touchButton(cocos2d::Ref *object, cocos2d::ui::TouchEventType type);

	cocos2d::Size				visibleSize;
	cocos2d::ui::Widget			*stageChoose;
	cocos2d::ui::ScrollView		*scrollView;
};

#endif