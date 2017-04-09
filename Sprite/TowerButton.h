#ifndef __TowerWar_TowerButton__
#define __TowerWar_TowerButton__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "ConstUtil.h"
#include "GameMap.h"
#include "Layer/GameMainLayer.h"
#include "Sprite/Components/ComTower.h"
#include "FireManager.h"

class TowerButton : public cocos2d::Sprite
{
public:
	//static TowerButton*getInstance();
	CREATE_FUNC(TowerButton);
	virtual bool init();

	void ableToCreat(cocos2d::Point pos, GameMap *gameMap);	//判断该位置是否能建造防御塔

	void buttonReset();

private:
	//static TowerButton* m_towerButton;

	void initTowerButton();

	void touchButton(Ref *object, cocos2d::ui::TouchEventType type);

	void changeVisible();

	cocos2d::ui::Widget*towerButton;
	cocos2d::ui::Button* btnFan;
	cocos2d::ui::Button* btnAgain;
	cocos2d::ui::Button* btnRocket;
	cocos2d::ui::Button* btnBottle;

	GameMap *m_gameMap;
	bool _isVisible;
	cocos2d::Point m_pos;		//当前建立防御塔坐标
};
#endif 
