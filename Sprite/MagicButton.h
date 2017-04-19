#ifndef __TowerWar_MagicButton__
#define __TowerWar_MagicButton__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "ConstUtil.h"
#include "GameMap.h"
#include "Layer/GameMainLayer.h"
#include "Sprite/Components/ComMagic.h"
#include "FireManager.h"

class MagicButton : public cocos2d::Sprite
{
public:
	CREATE_FUNC(MagicButton);

	void setGameMap(GameMap*gameMap);
private:
	virtual bool init();

	void initMagicButton();
	void initMagicRange();
	void isAbleToCreate(cocos2d::Point pos);

	void createButton(std::string normal, std::string disabled);
	void touchButton(cocos2d::Object *object, cocos2d::ui::TouchEventType type);

	int btnId;
	int m_tag;//当前magic编号
	GameMap *m_gameMap;
	cocos2d::Point m_blockCenter;
	cocos2d::Point m_pos;	//魔法阵范围

	//点击MagicButton后 移动中的sprite
	cocos2d::Sprite*	sunSprite;
	cocos2d::Sprite*	iceSprite;
	cocos2d::Sprite*	anchorSprite;
	cocos2d::Sprite*	fireSprite;
	cocos2d::Sprite*	starSprite;

	void createSunAttack();
	void createSunAttackEffects(cocos2d::Point pos);
	void endSunAttackEffects(Node*node);
	void sunAttackType();

	void createSnowAttack();
	void createSnowAttackEffects(cocos2d::Point pos);
	void endSnowAttackEffects(Node*node);
	void SnowAttackType();

	void createAnchor();
	void createAnchorEffects(cocos2d::Point pos);
	void endAnchorEffects(Node*node);

	void createFireBottle();
	void createFireBottleEffects(cocos2d::Point pos);
	void endFireBottleEffects(Node*node);

};
#endif 
