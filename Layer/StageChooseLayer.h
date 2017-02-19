#ifndef __TowerWar_StageChooseLayer__
#define __TowerWar_StageChooseLayer__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include"ConstUtil.h"
#include"GameState.h"
#include"Layer/DialogLayer.h"

class StageChooseLayer : public cocos2d::Layer
{
public:

	virtual bool init();

	CREATE_FUNC(StageChooseLayer);


private:
	void isFirst();
	//
	void addBackgroundSprite();
	//ScrollView滑动校正
	void adjustScrollView(float dt);
	//添加stage   
	cocos2d::ui::Button* addButton(char*name);
	//stage的按键回调
	void touchButton(cocos2d::Ref *object, cocos2d::ui::TouchEventType type);

	cocos2d::Size				visibleSize;
	cocos2d::ui::Widget		*	stageChoose;
	cocos2d::ui::ScrollView	*	scrollView;
};

#endif 
