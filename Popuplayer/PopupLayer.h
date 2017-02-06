//
//	PopupLayer.h
//
//	TowerWar
//
//	Create by wang2 on	17-2-6
//
#ifndef __TowerWar_PopupLayer__
#define __TowerWar_PopupLayer__
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include"ConstUtil.h"

class PopupLayer : public cocos2d::Layer
{
public:

	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(PopupLayer);

	//	0Ê§°Ü //		1Ò»¿ÅÐÇ//	2¶þ¿ÅÐÇ//	3Èý¿ÅÐÇ
	void setResult(int n,int curLevel);		
	
private:

	void initResultLayer();

	void showStar(int n);
	
	void popWin(int n);
	void popLost();

	void touchButton(cocos2d::Ref *object, cocos2d::ui::TouchEventType type);

	cocos2d::ui::Widget					* popupLayer;

	cocos2d::ui::ImageView				* start1;
	cocos2d::ui::ImageView				* start2;
	cocos2d::ui::ImageView				* start3;

	cocos2d::ui::Widget					* lost;
	cocos2d::ui::Widget					* win;

	cocos2d::ui::Button					* btnMenu;
	cocos2d::ui::Button					* btnAgain;
	cocos2d::ui::Button					* btnNext;

	cocos2d::ui::TextAtlas				* level;
};

#endif 
