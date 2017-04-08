#ifndef __TowerWar_AboutLayer__
#define __TowerWar_AboutLayer__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include"Scene/MenuScene.h"
#include"GameLayerControl.h"
#include"ConstUtil.h"

class AboutLayer : public cocos2d::Layer
{
public:
	CREATE_FUNC(AboutLayer);
private:
	virtual bool init();
	void initAboutBG();

	cocos2d::ui::Widget*aboutLayer;
	cocos2d::Size visibleSize;
};

#endif 
