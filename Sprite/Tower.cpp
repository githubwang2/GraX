#include "Sprite/Tower.h"
#include"Sprite/Components/ComTower.h"
#include "Layer/HUDLayer.h"

USING_NS_CC;
using namespace cocostudio;
using namespace ui;

Tower* Tower::createTower(Point pos, GameMap *gameMap){
	Tower* tower = new Tower();
	if (tower && tower->init(pos, gameMap))
	{
		tower->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(tower);
	}
	return tower;
}

bool Tower::init(Point pos, GameMap *gameMap)
{
	if (!Layer::init())
	{
		return false;
	}

	auto tileMap = gameMap->getTileMap();
	int offestX = -(int)pos.x % (int)tileMap->getTileSize().width +
		tileMap->getTileSize().width / 2;
	int offestY = -(int)pos.y % (int)tileMap->getTileSize().height +
		tileMap->getTileSize().height / 2;
	auto blockCenter = Point((int)(pos.x + offestX), (int)(pos.y + offestY));

	std::string str = gameMap->getTowerValue(pos);
	//CCLOG("%s", str.c_str());
	if (str.size() != 0)
	{
		if (str.compare("True") == 0)
		{
			auto playground = dynamic_cast<GameMainLayer*>(this->getParent());
			auto curGold = playground->changeGold(0);
			if (curGold < 150)		//�жϽ�Ǯ�Ƿ��㹻 ����ʱ��Ǯ��� �޷�����������
			{
				playground->goldWarn();
				return true;//���� ��������������ͼƬ
			}
			else                   ///��Ǯ�㹻  �۳���Ǯ  ����������
			{
				playground->changeGold(-150);
				Sprite*tower = Sprite::create(Tower1_IMG);
				tower->setPosition(blockCenter);

				//��comTower���ص�ÿ��tower��
				auto comTower = ComTower::create();
				tower->addComponent(comTower);
				//����FireManager��m_towers list��
				GameMainLayer::fileManager->m_towers.push_back(comTower);
				//-----------------
				addChild(tower);
				SoundsControl::setSound(SoundsControl::SoundState::BuyItem);
				return true;//���� ��������������ͼƬ
			}
		}
	}
	Sprite*errorPos = Sprite::create("Tower/ErrorPos.png");
	errorPos->setPosition(blockCenter);
	addChild(errorPos);
	auto action = Sequence::create(FadeOut::create(3), CallFunc::create([=]{
		errorPos->removeFromParent(); }), NULL);
		errorPos->runAction(action);
		return true;
}