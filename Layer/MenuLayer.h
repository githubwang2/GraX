#ifndef __TowerWar_MenuLayer__
#define __TowerWar_MenuLayer__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "GameState.h"
#include "SoundsControl.h"
#include "Scene/MenuScene.h"
#include "ConstUtil.h"

class MenuLayer : public cocos2d::Layer
{
public:

	virtual bool init();

	CREATE_FUNC(MenuLayer);
	
private:
	void initMenuBG();

	void initMenuBtn(char*btnName);

	cocos2d::ui::Widget*menuLayer;
	cocos2d::Size visibleSize;
};

#endif 
