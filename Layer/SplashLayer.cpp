#include"ConstUtil.h"
#include"Layer/SplashLayer.h"
#include"Layer/LoadingLayer.h"
#include"GameLayerControl.h"

USING_NS_CC;

bool SplashLayer::init(){
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	W_Sprite = initMoveSprite(W_IMG, 1.5);
	A_Sprite = initMoveSprite(A_IMG, -1.5);
	N_Sprite = initMoveSprite(N_IMG, -0.5);
	G_Sprite = initMoveSprite(G_IMG, 0.5);

	scheduleOnce(schedule_selector(SplashLayer::startMoveSprite), ONE_SECOND);

	return true;
}

Sprite* SplashLayer::initMoveSprite(char *a, float i){
	Sprite*sprite = Sprite::create(a);
	spriteSize = sprite->getContentSize();
	sprite->setPosition(Point(visibleSize.width / 2 + i * spriteSize.width, visibleSize.height / 2));
	addChild(sprite, 1);
	sprite->setOpacity(0);
	FadeIn*fade = FadeIn::create(ONE_SECOND * 2);
	sprite->runAction(fade);
	allSprites.pushBack(sprite);
	return sprite;
}

void SplashLayer::startMoveSprite(float dt){
	MoveBy*moveToLeft = MoveBy::create(MOVE_SPLEED, Point(-spriteSize.width, 0));
	MoveBy*moveToRight = MoveBy::create(MOVE_SPLEED, Point(spriteSize.width, 0));
	W_Sprite->runAction(moveToLeft);
	CallFunc*callfunc1 = CallFunc::create(CC_CALLBACK_0(SplashLayer::moveNSpriteToLeft, this));
	G_Sprite->runAction(Sequence::create(moveToRight, callfunc1, NULL));
}

void SplashLayer::moveNSpriteToLeft(){
	MoveBy*moveToLeft = MoveBy::create(MOVE_SPLEED, Point(-spriteSize.width, 0));
	MoveBy*moveToRight = MoveBy::create(MOVE_SPLEED, Point(spriteSize.width, 0));
	W_Sprite->runAction(moveToLeft);
	CallFunc*callfunc2 = CallFunc::create(CC_CALLBACK_0(SplashLayer::moveASpriteToLeft, this));
	N_Sprite->runAction(Sequence::create(moveToRight, callfunc2, NULL));
}

void SplashLayer::moveASpriteToLeft(){
	MoveBy*moveToLeft = MoveBy::create(MOVE_SPLEED, Point(-spriteSize.width, 0));
	MoveBy*moveToRight = MoveBy::create(MOVE_SPLEED, Point(spriteSize.width, 0));
	W_Sprite->runAction(moveToLeft);
	CallFunc*callfunc3 = CallFunc::create(CC_CALLBACK_0(SplashLayer::spriteFadeOut, this));
	A_Sprite->runAction(Sequence::create(moveToRight, callfunc3, NULL));
}

void SplashLayer::spriteFadeOut(){
	FadeOut*fadeout1 = FadeOut::create(ONE_SECOND * 2);
	FadeOut*fadeout2 = FadeOut::create(ONE_SECOND * 2);
	FadeOut*fadeout3 = FadeOut::create(ONE_SECOND * 2);
	FadeOut*fadeout4 = FadeOut::create(ONE_SECOND * 2);
	W_Sprite->runAction(fadeout1);
	A_Sprite->runAction(fadeout2);
	N_Sprite->runAction(fadeout3);
	CallFunc*callfunc4 = CallFunc::create(CC_CALLBACK_0(SplashLayer::gotoLoadingLayer, this));
	G_Sprite->runAction(Sequence::create(fadeout4, callfunc4, NULL));
}

void SplashLayer::gotoLoadingLayer(){
	auto scene = StartScene::create();
	scene->gameLoading();
}