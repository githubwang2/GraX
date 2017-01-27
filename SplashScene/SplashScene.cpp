#include"SplashScene\SplashScene.h"
#include "LoadingScene.h"

Scene*SplashScene::createScene(){
	auto scene = Scene::create();
	auto layer = SplashScene::create();
	scene->addChild(layer);
	return scene;
}

bool SplashScene::init(){
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

	scheduleOnce(schedule_selector(SplashScene::startMoveSprite), ONE_SECOND);

	return true;
}

Sprite* SplashScene::initMoveSprite(char *a, float i){
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

void SplashScene::startMoveSprite(float dt){
	MoveBy*moveToLeft = MoveBy::create(MOVE_SPLEED, Point(-spriteSize.width, 0));
	MoveBy*moveToRight = MoveBy::create(MOVE_SPLEED, Point(spriteSize.width, 0));
	W_Sprite->runAction(moveToLeft);
	CallFunc*callfunc1 = CallFunc::create(CC_CALLBACK_0(SplashScene::moveNSpriteToLeft, this));
	G_Sprite->runAction(Sequence::create(moveToRight, callfunc1, NULL));
}

void SplashScene::moveNSpriteToLeft(){
	MoveBy*moveToLeft = MoveBy::create(MOVE_SPLEED, Point(-spriteSize.width, 0));
	MoveBy*moveToRight = MoveBy::create(MOVE_SPLEED, Point(spriteSize.width, 0));
	W_Sprite->runAction(moveToLeft);
	CallFunc*callfunc2 = CallFunc::create(CC_CALLBACK_0(SplashScene::moveASpriteToLeft, this));
	N_Sprite->runAction(Sequence::create(moveToRight, callfunc2, NULL));
}

void SplashScene::moveASpriteToLeft(){
	MoveBy*moveToLeft = MoveBy::create(MOVE_SPLEED, Point(-spriteSize.width, 0));
	MoveBy*moveToRight = MoveBy::create(MOVE_SPLEED, Point(spriteSize.width, 0));
	W_Sprite->runAction(moveToLeft);
	CallFunc*callfunc3 = CallFunc::create(CC_CALLBACK_0(SplashScene::spriteFadeOut, this));
	A_Sprite->runAction(Sequence::create(moveToRight, callfunc3, NULL));
}

void SplashScene::spriteFadeOut(){
	FadeOut*fadeout1 = FadeOut::create(ONE_SECOND * 2);
	FadeOut*fadeout2 = FadeOut::create(ONE_SECOND * 2);
	FadeOut*fadeout3 = FadeOut::create(ONE_SECOND * 2);
	FadeOut*fadeout4 = FadeOut::create(ONE_SECOND * 2);
	W_Sprite->runAction(fadeout1);
	A_Sprite->runAction(fadeout2);
	N_Sprite->runAction(fadeout3);
	CallFunc*callfunc4 = CallFunc::create(CC_CALLBACK_0(SplashScene::gotoMenuScene, this));
	G_Sprite->runAction(Sequence::create(fadeout4, callfunc4, NULL));
}

void SplashScene::gotoMenuScene(){
	Director::getInstance()->replaceScene(LoadingScene::createScene());
	log("go to Menu");
}