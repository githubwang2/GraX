#ifndef __TowerWar_SkillLayer__
#define __TowerWar_SkillLayer__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include"Scene/MenuScene.h"
#include"GameLayerControl.h"
#include"ConstUtil.h"
#include"GameState.h"

class SkillLayer : public cocos2d::Layer
{
public:
	CREATE_FUNC(SkillLayer);
private:
	virtual bool init();
	void initSkill();
	cocos2d::Animation* initSkillAct(std::string btnName);
	void moveSkillBG(float dt);
	void endMoveSkill(Node*node);
	cocos2d::ui::Button* initButton(std::string btnName);
	void touchButton(cocos2d::Ref *object, cocos2d::ui::TouchEventType type);

	void skillOpenEffect(cocos2d::Point pos);
	void starsNotEnough();

	cocos2d::ui::Widget*skillLayer;
	cocos2d::Size visibleSize;

	cocos2d::ui::TextAtlas*lblNumOfStars;

	cocos2d::Sprite*spWater;
	cocos2d::Sprite*spWing;
	cocos2d::Sprite*spEarth;
	cocos2d::Sprite*spLight;

};

#endif 
