#include "Sprite/MagicButton.h"

USING_NS_CC;
using namespace cocostudio;
using namespace ui;

bool MagicButton::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Tower/AnchorEffects/AnchorEffects.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Tower/FBottleEffects/FBottle.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Tower/StarEffects/StarEffects.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Tower/SnowEffects/SnowEffects.plist");


	btnId = 0;
	m_blockCenter = Point(0, 0);
	initMagicRange();
	initMagicButton();
	
	return true;
}

void MagicButton::initMagicButton()
{
	createButton("Sun01.png", "Sun00.png");
	createButton("Snow01.png", "Snow00.png");
	createButton("Anchor01.png", "Anchor00.png");
	createButton("FBottle01.png", "FBottle00.png");
	createButton("Star01.png", "Star00.png");
}

void MagicButton::initMagicRange()
{
	sunSprite = Sprite::createWithSpriteFrameName("Sun-11.png");
	addChild(sunSprite);
	sunSprite->setVisible(false);

	iceSprite = Sprite::createWithSpriteFrameName("Snow-1.png");
	addChild(iceSprite);
	iceSprite->setVisible(false);

	anchorSprite = Sprite::createWithSpriteFrameName("Anchor31.png");
	addChild(anchorSprite);
	anchorSprite->setVisible(false);

	fireSprite = Sprite::createWithSpriteFrameName("FBottle-1.png");
	addChild(fireSprite);
	fireSprite->setVisible(false);

	starSprite = Sprite::createWithSpriteFrameName("Star-1.png");
	addChild(starSprite);
	starSprite->setVisible(false);
}

void MagicButton::setGameMap(GameMap*gameMap)
{
	m_gameMap = gameMap;
}

void MagicButton::touchButton(Object *object, cocos2d::ui::TouchEventType type)
{
	auto button = dynamic_cast<Button*>(object);
	int tag = button->getTag();
	m_tag = tag;
	switch (tag)
	{
	case 0:{
			   if (type == TouchEventType::TOUCH_EVENT_BEGAN)
			   {
				   button->setScale(1.5);
				   sunSprite->setPosition(button->getTouchBeganPosition());
				   sunSprite->setVisible(true);
			   }
			   if (type == TouchEventType::TOUCH_EVENT_MOVED)
			   {
				   button->setScale(1.0);
				   sunSprite->setPosition(button->getTouchMovePosition());
			   }
			   if (type == TouchEventType::TOUCH_EVENT_ENDED)
			   {
				   button->setScale(1.0);
				   sunSprite->setVisible(false);
			   }
			   if (type == TouchEventType::TOUCH_EVENT_CANCELED)
			   {
				   button->setScale(1.0);
				   sunSprite->setVisible(false);
				   Point pos = button->getTouchEndPosition();
				   isAbleToCreate(pos);
			   }
			   break; }
	case 1:{
			   if (type == TouchEventType::TOUCH_EVENT_BEGAN)
			   {
				   button->setScale(1.5);
				   iceSprite->setPosition(button->getTouchBeganPosition());
				   iceSprite->setVisible(true);
			   }
			   if (type == TouchEventType::TOUCH_EVENT_MOVED)
			   {
				   button->setScale(1.0);
				   iceSprite->setPosition(button->getTouchMovePosition());
			   }
			   if (type == TouchEventType::TOUCH_EVENT_ENDED)
			   {
				   button->setScale(1.0);
				   iceSprite->setVisible(false);
			   }
			   if (type == TouchEventType::TOUCH_EVENT_CANCELED)
			   {
				   button->setScale(1.0);
				   iceSprite->setVisible(false);
				   Point pos = button->getTouchEndPosition();
				   isAbleToCreate(pos);
			   }
			   break; }
	case 2:{
			   if (type == TouchEventType::TOUCH_EVENT_BEGAN)
			   {
				   button->setScale(1.5);
				   anchorSprite->setPosition(button->getTouchBeganPosition());
				   anchorSprite->setVisible(true);
			   }
			   if (type == TouchEventType::TOUCH_EVENT_MOVED)
			   {
				   button->setScale(1.0);
				   anchorSprite->setPosition(button->getTouchMovePosition());
			   }
			   if (type == TouchEventType::TOUCH_EVENT_ENDED)
			   {
				   button->setScale(1.0);
				   anchorSprite->setVisible(false);
			   }
			   if (type == TouchEventType::TOUCH_EVENT_CANCELED)
			   {
				   button->setScale(1.0);
				   anchorSprite->setVisible(false);
				   Point pos = button->getTouchEndPosition();
				   isAbleToCreate(pos);
			   }
			   break; }
	case 3:{
			   if (type == TouchEventType::TOUCH_EVENT_BEGAN)
			   {
				   button->setScale(1.5);
				   fireSprite->setPosition(button->getTouchBeganPosition());
				   fireSprite->setVisible(true);
			   }
			   if (type == TouchEventType::TOUCH_EVENT_MOVED)
			   {
				   button->setScale(1.0);
				   fireSprite->setPosition(button->getTouchMovePosition());
			   }
			   if (type == TouchEventType::TOUCH_EVENT_ENDED)
			   {
				   button->setScale(1.0);
				   fireSprite->setVisible(false);
			   }
			   if (type == TouchEventType::TOUCH_EVENT_CANCELED)
			   {
				   button->setScale(1.0);
				   fireSprite->setVisible(false);
				   Point pos = button->getTouchEndPosition();
				   isAbleToCreate(pos);
			   }
			   break; }
	case 4:{
			   if (type == TouchEventType::TOUCH_EVENT_BEGAN)
			   {
				   button->setScale(1.5);
				   starSprite->setPosition(button->getTouchBeganPosition());
				   starSprite->setVisible(true);
			   }
			   if (type == TouchEventType::TOUCH_EVENT_MOVED)
			   {
				   button->setScale(1.0);
				   starSprite->setPosition(button->getTouchMovePosition());
			   }
			   if (type == TouchEventType::TOUCH_EVENT_ENDED)
			   {
				   button->setScale(1.0);
				   starSprite->setVisible(false);
			   }
			   if (type == TouchEventType::TOUCH_EVENT_CANCELED)
			   {
				   button->setScale(1.0);
				   starSprite->setVisible(false);
				   Point pos = button->getTouchEndPosition();
				   isAbleToCreate(pos);
			   }
			   break; }
	default:break;
	}
}

void MagicButton::createButton(std::string normal, std::string disabled)
{
	auto btn = Button::create();
	btn->loadTextures(normal, normal, disabled, TextureResType::PLIST);
	btn->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
	btn->setPosition(Point(10, 500 - btnId * 60));
	btn->addTouchEventListener(this, toucheventselector(MagicButton::touchButton));
	addChild(btn);
	btn->setTag(btnId);
	btnId++;
}

void MagicButton::isAbleToCreate(cocos2d::Point pos)
{
	if (nullptr == m_gameMap)
	{
		CCLOG("no gameMap");
		return;
	}
	auto tileMap = m_gameMap->getTileMap();
	int offestX = -(int)pos.x % (int)tileMap->getTileSize().width +
		tileMap->getTileSize().width / 2;
	int offestY = -(int)pos.y % (int)tileMap->getTileSize().height +
		tileMap->getTileSize().height / 2;
	auto blockCenter = Point((int)(pos.x + offestX), (int)(pos.y + offestY));

	std::string str = m_gameMap->getTowerValue(pos);

	switch (m_tag)
	{
	case 0:{//sun
			   createSunAttackEffects(pos);
			   Action *act = Sequence::create(DelayTime::create(0.9f),
				   CallFunc::create(CC_CALLBACK_0(MagicButton::createSunAttack, this)), nullptr);
			   this->runAction(act);
			   break; }
	case 1:{//ice
			   createSnowAttackEffects(pos);
			   Action *act = Sequence::create(DelayTime::create(0.9f),
				   CallFunc::create(CC_CALLBACK_0(MagicButton::createSnowAttack, this)), nullptr);
			   this->runAction(act);
			   break; }
	case 2:{//anrchor
			   if (str.compare("True") == 0)
			   {
				   m_blockCenter = blockCenter;
				   createAnchorEffects(blockCenter);
				   Action *act = Sequence::create(DelayTime::create(1.3f),
					   CallFunc::create(CC_CALLBACK_0(MagicButton::createAnchor, this)), nullptr);
				   this->runAction(act);
			   }
			   else
			   {
				   Sprite*errorPos = Sprite::create("Tower/ErrorPos.png");
				   errorPos->setPosition(blockCenter);
				   addChild(errorPos);
				   auto action = Sequence::create(FadeOut::create(3), CallFunc::create([=]{
					   errorPos->removeFromParent(); }), NULL);
					   errorPos->runAction(action);
			   }
			   break; }
	case 3:{//fire
			   if (str.compare("True") == 0)
			   {
				   m_blockCenter = blockCenter;
				   createFireBottleEffects(blockCenter);
				   Action *act = Sequence::create(DelayTime::create(1.7f),
					   CallFunc::create(CC_CALLBACK_0(MagicButton::createFireBottle, this)), nullptr);
				   this->runAction(act);
			   }
			   else
			   {
				   Sprite*errorPos = Sprite::create("Tower/ErrorPos.png");
				   errorPos->setPosition(blockCenter);
				   addChild(errorPos);
				   auto action = Sequence::create(FadeOut::create(3), CallFunc::create([=]{
					   errorPos->removeFromParent(); }), NULL);
					   errorPos->runAction(action);
			   }
			   break; }
	case 4:{//star
			  
			   break; }
	default:
		break;
	}
}

void MagicButton::createAnchor()
{
	auto playground = dynamic_cast<GameMainLayer*>(this->getParent());
	auto curGold = playground->changeGold(0);

	if (curGold < 260)
	{
		playground->goldWarn();
	}
	else
	{
		playground->changeGold(-260);
		Sprite*Anchor = Sprite::createWithSpriteFrameName("Anchor31.png");
		Anchor->setPosition(m_blockCenter);
		Sprite*bAnchor = Sprite::createWithSpriteFrameName("Anchor-13.png");
		bAnchor->setPosition(m_blockCenter);
		bAnchor->runAction(RepeatForever::create(RotateBy::create(1, 360)));

		//Action *act = Sequence::create(DelayTime::create(5),
		//	CallFunc::create(CC_CALLBACK_0(FireManager::anchorBulletManager, this)), nullptr);
		//runAction(act);
		Anchor->runAction(RepeatForever::create(RotateBy::create(5, 360)));
		addChild(bAnchor);
		addChild(Anchor);
		//------------------------------------------------
		auto comTower = ComTower::create(0, 1);
		Anchor->addComponent(comTower);
		GameMainLayer::fileManager->m_anchorTowers.push_back(comTower);
		//------------------------------------------------
	}
}
void MagicButton::createAnchorEffects(cocos2d::Point pos)
{
	Animation * animation = Animation::create();
	char buf[60] = { 0 };
	for (int i = 1; i < 14;i++)
	{
		sprintf(buf, "AnchorEffects%d.png", i);
		animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(buf));
	}	 
	//animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("AnchorEffects/AnchorEffects1.png.png"));
	animation->setDelayPerUnit(0.1f);
	animation->setRestoreOriginalFrame(true);
	auto sp = Sprite::create();
	Action *act = Sequence::create(
		Repeat::create(Animate::create(animation), 1),
		CallFuncN::create(sp, callfuncN_selector(MagicButton::endAnchorEffects)), nullptr);

	sp->runAction(act);
	sp->setPosition(pos+Point(0,80));
	addChild(sp, 1);
}
void MagicButton::endAnchorEffects(Node*node){
	node->removeFromParentAndCleanup(true);
}

void MagicButton::createFireBottle()
{
	auto playground = dynamic_cast<GameMainLayer*>(this->getParent());
	auto curGold = playground->changeGold(0);

	if (curGold < 160)
	{
		playground->goldWarn();
	}
	else
	{
	playground->changeGold(-160);
	Sprite*FBottle = Sprite::createWithSpriteFrameName("FBottle-1.png");
	FBottle->setPosition(m_blockCenter);
	Sprite*bFBottle = Sprite::createWithSpriteFrameName("Anchor-13.png");
	bFBottle->setPosition(m_blockCenter);
	addChild(bFBottle);
	addChild(FBottle);
	//------------------------------------------------
	auto comMagic = ComMagic::create(3);
	FBottle->addComponent(comMagic);
	GameMainLayer::fileManager->m_FBottleMagic.push_back(comMagic);
	//------------------------------------------------
	}
}
void MagicButton::createFireBottleEffects(cocos2d::Point pos)
{
	Animation * animation = Animation::create();
	char buf[60] = { 0 };
	for (int i = 1; i < 18; i++)
	{
		sprintf(buf, "FBottle%d.png", i);
		animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(buf));
	}
	animation->setDelayPerUnit(0.1f);
	animation->setRestoreOriginalFrame(true);
	auto sp = Sprite::create();
	Action *act = Sequence::create(
		Repeat::create(Animate::create(animation), 1),
		CallFuncN::create(sp, callfuncN_selector(MagicButton::endFireBottleEffects)), nullptr);

	sp->runAction(act);
	sp->setPosition(pos + Point(0, 30));
	addChild(sp, 1);
}
void MagicButton::endFireBottleEffects(Node*node)
{
	node->removeFromParentAndCleanup(true);
}

void MagicButton::createSunAttack()
{
	auto playground = dynamic_cast<GameMainLayer*>(this->getParent());
	auto curGold = playground->changeGold(0);

	if (curGold < 180)
	{
		playground->goldWarn();
	}
	else
	{
		playground->changeGold(-180);

		auto sunMagic = Sprite::create("Tower/SunRange.png");
		sunMagic->setPosition(m_pos);
		addChild(sunMagic);
		//------------------------------------------------
		auto comMagic = ComMagic::create(0);
		sunMagic->addComponent(comMagic);
		GameMainLayer::fileManager->m_sunMagic.push_back(comMagic);

		this->runAction(Repeat::create(
			CallFunc::create(CC_CALLBACK_0(MagicButton::sunAttackType, this)), 3));
	}
}
void MagicButton::sunAttackType()
{
	for (auto magicSun : GameMainLayer::fileManager->m_sunMagic)
	{
		Point fallingPos = magicSun->getOwner()->getPosition();
		
		for (auto monster : GameMainLayer::fileManager->m_monsters)
		{
			Size magicSize = magicSun->getOwner()->getContentSize();
			Rect magicStarRect(fallingPos.x, fallingPos.y, magicSize.width, magicSize.height);
			Size monsterSize = monster->getOwner()->getContentSize();
			Rect monsterRect(monster->getOwner()->getPositionX(), monster->getOwner()->getPositionY(),
				monsterSize.width, monsterSize.height);
			if (magicStarRect.intersectsRect(monsterRect))
			{
				auto comLife = dynamic_cast<ComLife*>(monster->getOwner()->getComponent("ComLife"));
				bool isDead = comLife->attacked(200);//¸Ä Ì«ÑôµÄ¹¥»÷
				if (isDead)
				{
					monster->getOwner()->removeFromParent();
					GameMainLayer::fileManager->m_monsters.remove(monster);
					break;
				}
			}
		}
		/*if (hitMonster)
		{
			owner->removeFromParent();
			m_bottleBullets.remove(bullet);
			break;
		}*/
	}
}
void MagicButton::createSunAttackEffects(cocos2d::Point pos)
{
	auto playground = dynamic_cast<GameMainLayer*>(this->getParent());
	auto curGold = playground->changeGold(0);

	if (curGold > 180)
	{
		Animation * aniReading = Animation::create();
		char buf[60] = { 0 };
		for (int i = 1; i < 10; i++)
		{
			sprintf(buf, "StarReadying%d.png", i);
			aniReading->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(buf));
		}
		aniReading->setDelayPerUnit(0.1f);
		aniReading->setRestoreOriginalFrame(true);
		Animation * animation = Animation::create();
		for (int i = 1; i < 10; i++)
		{
			sprintf(buf, "Star%d.png", i);
			animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(buf));
		}
		animation->setDelayPerUnit(0.1f);
		animation->setRestoreOriginalFrame(true);

		auto spriteReadying = Sprite::create();
		spriteReadying->runAction(Repeat::create(Animate::create(aniReading), 1));

		auto sp = Sprite::create();
		Action *act = Sequence::create(DelayTime::create(0.9f), Repeat::create(Animate::create(animation), 1),
			CallFuncN::create(sp, callfuncN_selector(MagicButton::endSunAttackEffects)), nullptr);
		sp->runAction(act);

		m_pos = pos;
		spriteReadying->setPosition(pos + Point(0, 0));
		sp->setPosition(pos + Point(0, 140));
		addChild(spriteReadying, 1);
		addChild(sp, 1);
	}
}
void MagicButton::endSunAttackEffects(Node*node)
{
	node->removeFromParentAndCleanup(true);
}

void MagicButton::createSnowAttack()
{
	auto playground = dynamic_cast<GameMainLayer*>(this->getParent());
	auto curGold = playground->changeGold(0);

	if (curGold < 160)
	{
		playground->goldWarn();
	}
	else
	{
		playground->changeGold(-160);

		auto snowMagic = Sprite::create("Tower/SnowRange.png");
		snowMagic->setPosition(m_pos);
		addChild(snowMagic);
		//------------------------------------------------
		auto comMagic = ComMagic::create(1);
		snowMagic->addComponent(comMagic);
		GameMainLayer::fileManager->m_snowMagic.push_back(comMagic);

		this->runAction(Repeat::create(
			CallFunc::create(CC_CALLBACK_0(MagicButton::SnowAttackType, this)), 3));
	}
}
void MagicButton::SnowAttackType()
{
	for (auto magicSnow : GameMainLayer::fileManager->m_snowMagic)
	{
		Point fallingPos = magicSnow->getOwner()->getPosition();

		for (auto monster : GameMainLayer::fileManager->m_monsters)
		{
			Size magicSize = magicSnow->getOwner()->getContentSize();
			Rect magicSnowRect(fallingPos.x, fallingPos.y, 600, 400);
			Size monsterSize = monster->getOwner()->getContentSize();
			Rect monsterRect(monster->getOwner()->getPositionX(), monster->getOwner()->getPositionY(),
				monsterSize.width, monsterSize.height);
			if (magicSnowRect.intersectsRect(monsterRect))
			{
				auto comLife = dynamic_cast<ComLife*>(monster->getOwner()->getComponent("ComLife"));
				bool isDead = comLife->attacked(30);//¸Ä ±ù¶³µÄ¹¥»÷
				if (isDead)
				{
					monster->getOwner()->removeFromParent();
					GameMainLayer::fileManager->m_monsters.remove(monster);
					break;
				}
			}
		}
	}
}
void MagicButton::createSnowAttackEffects(cocos2d::Point pos)
{
	auto playground = dynamic_cast<GameMainLayer*>(this->getParent());
	auto curGold = playground->changeGold(0);

	if (curGold > 160)
	{
		char buf[60] = { 0 };
		Animation * animation = Animation::create();
		for (int i = 1; i < 13; i++)
		{
			sprintf(buf, "SnowEffects%d.png", i);
			animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(buf));
		}
		animation->setDelayPerUnit(0.1f);
		animation->setRestoreOriginalFrame(true);

		auto sp = Sprite::create();
		Action *act = Sequence::create(DelayTime::create(0.9f), Repeat::create(Animate::create(animation), 1),
			CallFuncN::create(sp, callfuncN_selector(MagicButton::endSnowAttackEffects)), nullptr);
		sp->runAction(act);

		m_pos = pos;
		sp->setPosition(pos);
		sp->setScale(2.0);
		addChild(sp, 1);
	}
}
void MagicButton::endSnowAttackEffects(Node*node)
{
	node->removeFromParentAndCleanup(true);
}

