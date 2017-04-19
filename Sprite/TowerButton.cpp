#include "Sprite/TowerButton.h"

USING_NS_CC;
using namespace cocostudio;
using namespace ui;


//TowerButton* TowerButton::m_towerButton = nullptr;

//TowerButton* TowerButton::getInstance(){
//	 if (m_towerButton==nullptr)
//	{
//		 m_towerButton = new TowerButton();
//
//		 if (m_towerButton && m_towerButton->init())
//		 {
//			// m_towerButton->autorelease();
//			 m_towerButton->retain(); 
//			 //这个自己管
//		 }
//		 else
//		 {
//			 CC_SAFE_DELETE(m_towerButton);
//		 }
//	 }
//	 return m_towerButton;
//}

bool TowerButton::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	_isVisible = false;
	m_gameMap = nullptr;
	m_pos = Point(0, 0); 

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Tower/Tower.plist");

	initTowerButton();
	return true;
}

void TowerButton::initTowerButton()
{
	towerButton = dynamic_cast<Widget*>(GUIReader::getInstance()
		->widgetFromJsonFile("Tower/TowerButton.json"));
	towerButton->setPosition(Point (0,0));
	this->addChild(towerButton);
	towerButton->setVisible(_isVisible);
	btnFan = dynamic_cast<Button*>(towerButton->getChildByName("TowerButton")->getChildByName("btnFan"));
	btnAgain = dynamic_cast<Button*>(towerButton->getChildByName("TowerButton")->getChildByName("btnArrow"));
	btnRocket = dynamic_cast<Button*>(towerButton->getChildByName("TowerButton")->getChildByName("btnRocket"));
	btnBottle = dynamic_cast<Button*>(towerButton->getChildByName("TowerButton")->getChildByName("btnBottle"));

	btnFan->addTouchEventListener(this, toucheventselector(TowerButton::touchButton));
	btnAgain->addTouchEventListener(this, toucheventselector(TowerButton::touchButton));
	btnRocket->addTouchEventListener(this, toucheventselector(TowerButton::touchButton));
	btnBottle->addTouchEventListener(this, toucheventselector(TowerButton::touchButton));
}

void TowerButton::changeVisible()
{
	auto  Act1 = MoveTo::create(0.2f, Point(-50, 0));
	auto  Act2 = MoveTo::create(0.2f, Point(50, 0));
	auto  Act3 = MoveTo::create(0.2f, Point(0, -50));
	auto  Act4 = MoveTo::create(0.2f, Point(0, 50));

	btnFan->runAction(Act1);
	btnAgain->runAction(Act2);
	btnRocket->runAction(Act3);
	btnBottle->runAction(Act4);

	if (_isVisible)
	{
		btnFan->runAction(MoveTo::create(0.2f, Point(0, 0)));
		btnAgain->runAction(MoveTo::create(0.2f, Point(0, 0)));
		btnRocket->runAction(MoveTo::create(0.2f, Point(0, 0)));
		btnBottle->runAction(MoveTo::create(0.2f, Point(0, 0)));

		_isVisible = false;
	}
	else
	{
		_isVisible = true;
	}
	towerButton->setVisible(_isVisible);
}

void TowerButton::buttonReset()
{
	//m_towerButton->release();
	_isVisible = true;
	changeVisible();
}

void TowerButton::ableToCreat(cocos2d::Point pos, GameMap *gameMap)
{
	if (nullptr==gameMap)
	{
		CCLOG("no gameMap");
		return;
	}
	auto tileMap = gameMap->getTileMap();
	int offestX = -(int)pos.x % (int)tileMap->getTileSize().width +
		tileMap->getTileSize().width / 2;
	int offestY = -(int)pos.y % (int)tileMap->getTileSize().height +
		tileMap->getTileSize().height / 2;
	auto blockCenter = Point((int)(pos.x + offestX), (int)(pos.y + offestY));
	m_pos = blockCenter;

	std::string str = gameMap->getTowerValue(pos);
	if (str.size() != 0)
	{
		if (str.compare("True") == 0)
		{
			towerButton->setPosition(blockCenter);
			changeVisible();
			//------------------------------
		}
	}
	else
	{
		if (_isVisible)
		{
			changeVisible();
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
}

void TowerButton::touchButton(Ref *object, TouchEventType type)
{
	if (type == TOUCH_EVENT_ENDED)
	{
		auto widget = dynamic_cast<Widget*>(object);
		auto name = widget->getName();

		auto playground = dynamic_cast<GameMainLayer*>(this->getParent());
		auto curGold = playground->changeGold(0);
		//---------------------------------------------
		if (name.compare("btnFan") == 0)
		{
			if (curGold < 160)		
			{
				playground->goldWarn();
			}
			else                   
			{
				playground->changeGold(-160);
				Sprite*fan1 = Sprite::createWithSpriteFrameName(Fan1_IMG);
				fan1->setPosition(m_pos);
				Sprite*pFan1 = Sprite::createWithSpriteFrameName(PFan1_IMG);
				pFan1->setPosition(m_pos+Point(0,10));
				pFan1->runAction(RepeatForever::create(RotateBy::create(1,360)));
				
				auto comTower = ComTower::create(0,1);
				fan1->addComponent(comTower);
				GameMainLayer::fileManager->m_fanTowers.push_back(comTower);
				addChild(fan1);
				addChild(pFan1);
				SoundsControl::setSound(SoundsControl::SoundState::BuyItem);
			}
		}
		//---------------------------------------------
		else if (name.compare("btnArrow") == 0)
		{
			if (curGold < 220)
			{
				playground->goldWarn();
			}
			else
			{
				playground->changeGold(-220);
				Sprite*arrow = Sprite::createWithSpriteFrameName(Arrow1_IMG);
				arrow->setPosition(m_pos);

				auto comTower = ComTower::create(1,1);
				arrow->addComponent(comTower);
				GameMainLayer::fileManager->m_arrowTowers.push_back(comTower);
				addChild(arrow);
				SoundsControl::setSound(SoundsControl::SoundState::BuyItem);
			}
		}
		//---------------------------------------------
		else if (name.compare("btnRocket") == 0)
		{
			if (curGold < 220)		//判断金钱是否足够 不够时金钱变红 无法产生防御塔
			{
				playground->goldWarn();
			}
			else                   ///金钱足够  扣除金钱  创建防御塔
			{
				playground->changeGold(-220);
				Sprite*tower = Sprite::createWithSpriteFrameName(Rocket1_IMG);
				tower->setPosition(m_pos);

				//将comTower挂载到每个tower上
				auto comTower = ComTower::create(2,1);
				tower->addComponent(comTower);
				//存入FireManager的m_towers list中
				GameMainLayer::fileManager->m_rocketTower.push_back(comTower);
				//-----------------
				addChild(tower);
				SoundsControl::setSound(SoundsControl::SoundState::BuyItem);
			}
		}
		//---------------------------------------------
		else if (name.compare("btnBottle") == 0)
		{
			if (curGold < 100)
			{
				playground->goldWarn();
			}
			else
			{
				playground->changeGold(-100);
				Sprite*bottle = Sprite::createWithSpriteFrameName(Bottle1_IMG);
				bottle->setPosition(m_pos);

				auto comTower = ComTower::create(3,1);
				bottle->addComponent(comTower);
				GameMainLayer::fileManager->m_bottleTowers.push_back(comTower);
				addChild(bottle);
				SoundsControl::setSound(SoundsControl::SoundState::BuyItem);
			}
		}
		else
		{
		}
		changeVisible();
	}
}

