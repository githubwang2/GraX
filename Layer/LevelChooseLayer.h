#ifndef __TowerWar_LevelChooseLayer__
#define __TowerWar_LevelChooseLayer__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include"ConstUtil.h"
#include"GameState.h"
#include"Scene/MenuScene.h"
#include"Scene/GameMainScene.h"
#include"Layer/StageChooseLayer.h"

class LevelChooseLayer : public cocos2d::Layer
{
public:
	static Layer*createWithJsonFile();

	virtual bool init();

	//void onEnter();
	static int g_current_level;
private:
	void initLevelLayer();

	void initLevelButton(int levelNum);

	cocos2d::ui::Widget* levelChoose;

	void touchButton(cocos2d::Ref *object, cocos2d::ui::TouchEventType type);

	int	m_currentStage;
};

#endif 
