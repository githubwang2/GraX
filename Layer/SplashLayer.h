#ifndef __TowerWar_SplashLayer__
#define __TowerWar_SplashLayer__

#include "cocos2d.h"
#include"Scene/StartScene.h"

class SplashLayer : public cocos2d::LayerColor
{
public:
	CREATE_FUNC(SplashLayer);
private:
	virtual bool init();

	cocos2d::Sprite* initMoveSprite(char *a, float i);

	void startMoveSprite(float dt);
	void moveNSpriteToLeft();
	void moveASpriteToLeft();

	void spriteFadeOut();
	void gotoLoadingLayer();

	cocos2d::Sprite*W_Sprite;
	cocos2d::Sprite*A_Sprite;
	cocos2d::Sprite*N_Sprite;
	cocos2d::Sprite*G_Sprite;

	cocos2d::Vector<cocos2d::Sprite*>allSprites;

	cocos2d::Size visibleSize;
	cocos2d::Size spriteSize;
};

#endif 
