#ifndef __TowerWar_DexLayer__
#define __TowerWar_DexLayer__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Scene/MenuScene.h"

class DexLayer : public cocos2d::Layer
{
public:
	virtual bool init();
	CREATE_FUNC(DexLayer);
private:
	void iniyBG();
	void initMonDex();
	void initDexBtn(int monsterId);
	void initAnimate();
	cocos2d::Layer* addAnimate();
	void touchButton(cocos2d::Ref *object, cocos2d::ui::TouchEventType type);

	void update(float dt);
	int btnTag;           //从配置文件中读取的button TAG
	cocos2d::Size visibleSize;
	cocos2d::ui::Widget*dexLayer;
	bool m_isVisible;
	int m_id;
	int m_hp;
	int m_speed;

	cocos2d::Animation*ani_up;
	cocos2d::Animation*ani_down;
	cocos2d::Animation*ani_left;
	cocos2d::Animation*ani_right;
	/*cocos2d::Sprite *spUp;
	cocos2d::Sprite *spDown;
	cocos2d::Sprite *spLeft;
	cocos2d::Sprite *spRight;*/
	cocos2d::Layer* monAniLayer;
	int n = 0;
};

#endif 
