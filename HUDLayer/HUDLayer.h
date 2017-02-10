#ifndef __TowerWar_HUDLayer__
#define __TowerWar_HUDLayer__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

class HUDLayer : public cocos2d::Layer
{
public:
	static void createHUDLayer();
	//初始化金钱 总波数 生命值
	static void setInitHUD(int gold, int allRound, int life);
	//生成怪物波数
	static void createWaveRusher();
	//金钱
	static int changeGold(int num);
	//生命
	static int changeLife(int num);		//	返回life 因为要判定是否为0

	static cocos2d::ui::Widget*getHud();

private:
	static cocos2d::ui::Widget		*		m_hud;
	static cocos2d::ui::TextAtlas	*		lblGold;
	static cocos2d::ui::TextAtlas	*		lblRound;
	static cocos2d::ui::TextAtlas	*		lblLife;
	static cocos2d::ui::TextAtlas	*		lblAllRound;

	static int m_allRound;					//	总波数
	static int m_curRound;					//	当前波数
	static int m_curGold;					//	当前金币
	static int m_curLife;					//	当前生命
};

#endif 
