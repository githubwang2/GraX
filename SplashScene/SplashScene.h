//
//	SplashScene.h
//
//	TowerWar
//
//	Create by wang2 on	17-1-24
//
#ifndef __TowerWar_SplashScene__
#define __TowerWar_SplashScene__

#include "cocos2d.h"
#include"ConstUtil.h"

USING_NS_CC;


class SplashScene : public cocos2d::LayerColor
{
public:
	static Scene* createScene();

	virtual bool init();

	Sprite* initMoveSprite(char *a, float i);

	void startMoveSprite(float dt);
	void moveNSpriteToLeft();
	void moveASpriteToLeft();

	void gotoMenuScene();
	void spriteFadeOut();

	CREATE_FUNC(SplashScene);

private:
	Sprite*W_Sprite;
	Sprite*A_Sprite;
	Sprite*N_Sprite;
	Sprite*G_Sprite;

	Vector<Sprite*>allSprites;

	Size visibleSize;
	Size spriteSize;
};

#endif 
