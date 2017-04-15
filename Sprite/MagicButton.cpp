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

void MagicButton::touchButton(Object *object, cocos2d::ui::TouchEventType type)
{
	auto button = dynamic_cast<Button*>(object);
	int tag = button->getTag();
	switch (tag)
	{
	case 0:{
			   if (type == TouchEventType::TOUCH_EVENT_BEGAN)
			   {
				   button->setScale(1.5);
				   skillRange->setPosition(button->getTouchBeganPosition());
				   skillRange->setVisible(true);
			   }
			   if (type == TouchEventType::TOUCH_EVENT_MOVED)
			   {
				   button->setScale(1.0);
				   skillRange->setPosition(button->getTouchMovePosition());
			   }
			   if (type == TouchEventType::TOUCH_EVENT_ENDED)
			   {
				   button->setScale(1.0);
				   skillRange->setVisible(false);
			   }
			   if (type == TouchEventType::TOUCH_EVENT_CANCELED)
			   {
				   button->setScale(1.0);
				   skillRange->setVisible(false);
				   Point pos = button->getTouchEndPosition();
				   isAbleToCreate(pos);
			   }
			   break; }
	case 1:{
			   if (type == TouchEventType::TOUCH_EVENT_BEGAN)
			   {
				   button->setScale(1.5);
				   skillRange->setPosition(button->getTouchBeganPosition());
				   skillRange->setVisible(true);
			   }
			   if (type == TouchEventType::TOUCH_EVENT_MOVED)
			   {
				   button->setScale(1.0);
				   skillRange->setPosition(button->getTouchMovePosition());
			   }
			   if (type == TouchEventType::TOUCH_EVENT_ENDED)
			   {
				   button->setScale(1.0);
				   skillRange->setVisible(false);
			   }
			   if (type == TouchEventType::TOUCH_EVENT_CANCELED)
			   {
				   button->setScale(1.0);
				   skillRange->setVisible(false);
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
			   break; }
	case 4:{
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

void MagicButton::initMagicRange()
{
	skillRange = Sprite::createWithSpriteFrameName("PSun15.png");
	addChild(skillRange);
	skillRange->setVisible(false);

	anchorSprite = Sprite::createWithSpriteFrameName("Anchor31.png");
	addChild(anchorSprite);
	anchorSprite->setVisible(false);
}

void MagicButton::setGameMap(GameMap*gameMap)
{
	m_gameMap = gameMap;
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
	if (str.size() != 0)
	{
		if (str.compare("True") == 0)
		{
			m_blockCenter = blockCenter;
			Action *act = Sequence::create(DelayTime::create(1.5),
				CallFunc::create(CC_CALLBACK_0(MagicButton::createAnchor, this)), nullptr);
			this->runAction(act);
		}
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
}

void MagicButton::createAnchor()
{
	auto playground = dynamic_cast<GameMainLayer*>(this->getParent());
	auto curGold = playground->changeGold(0);

	if (curGold < 260)
	{
		playground->goldWarn();
	}
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

