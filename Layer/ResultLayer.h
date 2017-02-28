#ifndef __TowerWar_ResultLayer__
#define __TowerWar_ResultLayer__
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "ConstUtil.h"

#include "GameLayerControl.h"
#include "Layer/LevelChooseLayer.h"
#include "Layer/StageChooseLayer.h"

class ResultLayer : public cocos2d::Layer
{
public:
	//	0Ê§°Ü //		1Ò»¿ÅÐÇ//	2¶þ¿ÅÐÇ//	3Èý¿ÅÐÇ
	static ResultLayer*createLayer(int n, int curLevel);
private:
	virtual bool init(int n, int curLevel);

	cocos2d::Layer *setResult(int n, int curLevel);
	cocos2d::Layer* initResultLayer();

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
