#ifndef __TowerWar_SettingLayer__
#define __TowerWar_SettingLayer__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include"SoundsControl.h"
#include"Scene/MenuScene.h"
#include"GameLayerControl.h"
#include"ConstUtil.h"

class SettingLayer : public cocos2d::Layer
{
public:

	virtual bool init();

	CREATE_FUNC(SettingLayer);

private:
	void initSettingButton();
	void touchEffect(cocos2d::ui::ImageView *imgShow);
	void touchButton(cocos2d::Ref *pSender);
	cocos2d::Size visibleSize;

	cocos2d::ui::Widget*settingLayer;
	cocos2d::ui::ImageView* imgMusicOn;
	cocos2d::ui::ImageView* imgMusicOff;
	cocos2d::ui::ImageView* imgJP;
	cocos2d::ui::ImageView* imgCN;
	cocos2d::ui::ImageView*imgTS;

	bool music_on;
	bool language_jp;
};

#endif 
