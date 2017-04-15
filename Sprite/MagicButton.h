#ifndef __TowerWar_MagicButton__
#define __TowerWar_MagicButton__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "ConstUtil.h"
#include "GameMap.h"
#include "Layer/GameMainLayer.h"
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
	void touchButton(cocos2d::Object *object, cocos2d::ui::TouchEventType type  );

	int btnId;
	cocos2d::Sprite* skillRange;
	cocos2d::Sprite*anchorSprite;
	GameMap *m_gameMap;
	cocos2d::Point m_blockCenter;

	void createAnchor();
};
#endif 
