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

class SplashScene : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(SplashScene);

private:
	cocos2d::Sprite* initMoveSprite(char *a, float i);

	void startMoveSprite(float dt);
	void moveNSpriteToLeft();
	void moveASpriteToLeft();

	void gotoLoadingScene();
	void spriteFadeOut();

	cocos2d::Sprite*W_Sprite;
	cocos2d::Sprite*A_Sprite;
	cocos2d::Sprite*N_Sprite;
	cocos2d::Sprite*G_Sprite;

	cocos2d::Vector<cocos2d::Sprite*>allSprites;

	cocos2d::Size visibleSize;
	cocos2d::Size spriteSize;
};

#endif 
