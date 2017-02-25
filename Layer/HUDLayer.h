#ifndef __TowerWar_HUDLayer__
#define __TowerWar_HUDLayer__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

class HUDLayer : public cocos2d::Layer
{
public:
	bool init();
	CREATE_FUNC(HUDLayer);
	//初始化金钱 总波数 生命值
	void setInitHUD(int gold, int allRound, int life);
	//生成怪物波数
	void createWaveRusher();
	//金钱
	int changeGold(int num);
	//生命
	int changeLife(int num);		//	返回life 因为要判定是否为0

	void goldWarn();
private:
	cocos2d::ui::Widget		*		m_hud;
	cocos2d::ui::TextAtlas	*		lblGold;
	cocos2d::ui::TextAtlas	*		lblRound;
	cocos2d::ui::TextAtlas	*		lblLife;
	cocos2d::ui::TextAtlas	*		lblAllRound;

	int m_allRound;					//	总波数
	int m_curRound;					//	当前波数
	int m_curGold;					//	当前金币
	int m_curLife;					//	当前生命
};

#endif 
