#ifndef __TowerWar_SkillLayer__
#define __TowerWar_SkillLayer__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include"Scene/MenuScene.h"
#include"GameLayerControl.h"
#include"ConstUtil.h"
#include "GameState.h"

class SkillLayer : public cocos2d::Layer
{
public:
	CREATE_FUNC(SkillLayer);
private:
	virtual bool init();
	void initSkillBG();
	cocos2d::ui::Button* initButton(std::string btnName);
	void touchButton(cocos2d::Ref *object, cocos2d::ui::TouchEventType type);

	cocos2d::ui::Widget*skillLayer;
	cocos2d::Size visibleSize;

	cocos2d::ui::Button*btn1;
	cocos2d::ui::Button*btn2;
	cocos2d::ui::Button*btn3;

};

#endif 
