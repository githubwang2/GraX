#include "Sprite/TowerButton.h"

USING_NS_CC;
using namespace cocostudio;
using namespace ui;


TowerButton* TowerButton::m_towerButton = nullptr;

TowerButton* TowerButton::getInstance(){
	 if (m_towerButton==nullptr)
	{
		 m_towerButton = new TowerButton();

		 if (m_towerButton && m_towerButton->init())
		 {
			 m_towerButton->autorelease();
		 }
		 else
		 {
			 CC_SAFE_DELETE(m_towerButton);
		 }
	 }
	
	 return m_towerButton;
}

bool TowerButton::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	_isVisible = false;
	m_gameMap = nullptr;
	m_pos = Point(0, 0);

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
		if (name.compare("btnFan") == 0)
		{
			
		}
		else if (name.compare("btnAgain") == 0)
		{
		}
		else if (name.compare("btnRocket") == 0)
		{
			auto playground = dynamic_cast<GameMainLayer*>(this->getParent());
			auto curGold = playground->changeGold(0);
			if (curGold < 150)		//�жϽ�Ǯ�Ƿ��㹻 ����ʱ��Ǯ��� �޷�����������
			{
				playground->goldWarn();
				return ;//���� ��������������ͼƬ
			}
			else                   ///��Ǯ�㹻  �۳���Ǯ  ����������
			{
				playground->changeGold(-150);
				Sprite*tower = Sprite::create(Tower1_IMG);
				tower->setPosition(m_pos);

				//��comTower���ص�ÿ��tower��
				auto comTower = ComTower::create();
				tower->addComponent(comTower);
				//����FireManager��m_towers list��
				GameMainLayer::fileManager->m_towers.push_back(comTower);
				//-----------------
				addChild(tower);
				SoundsControl::setSound(SoundsControl::SoundState::BuyItem);
				return ;//���� ��������������ͼƬ
			}
		}
		else if (name.compare("btnBottle") == 0)
		{
		}
		else
		{
		}
		changeVisible();
	}
}



