#include "Sprite/TowerBase.h"
#include"HUDLayer/HUDLayer.h"

USING_NS_CC;
using namespace cocostudio;
using namespace ui;

TowerBase::TowerBase()
{
}

bool TowerBase::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}

Layer* TowerBase::createTower(Point pos, GameMap *gameMap){
	auto layer = Layer::create();

	auto tileMap = gameMap->getTileMap();
	int offestX = -(int)pos.x % (int)tileMap->getTileSize().width +
		tileMap->getTileSize().width / 2;
	int offestY = -(int)pos.y % (int)tileMap->getTileSize().height +
		tileMap->getTileSize().height / 2;
	auto blockCenter = Point((int)(pos.x + offestX), (int)(pos.y + offestY));

	std::string str = gameMap->getTowerValue(pos);
	CCLOG("%s", str.c_str());

	if (str.size() != 0)
	{
		if (str.compare("True") == 0)
		{
			if (HUDLayer::changeGold(0)<150)		//判断金钱是否足够 不够时金钱变红 无法产生防御塔
			{
				auto goldLable = dynamic_cast<Widget*>(HUDLayer::getHud())->getChildByName("LabelGold");
				auto toRed = TintBy::create(0.5f, -127, -255, -127);
				goldLable->runAction(Sequence::create(toRed, toRed->reverse(), nullptr));
				return layer;//跳出 不运行下面错误的图片
			}
			else                   ///金钱足够  扣除金钱  创建防御塔
			{

				HUDLayer::changeGold(-150);

				Sprite*tower = Sprite::create("Tower/Tower.png");
				tower->setPosition(blockCenter);

				////将comTower挂载到每个tower上
				//auto comTower = ComTower::create();
				//tower->addComponent(comTower);
				////存入FireManager的m_towers list中
				//m_fireManager->m_towers.push_back(comTower);
				//-----------------
				layer->addChild(tower);
				return layer;//跳出 不运行下面错误的图片
			}
		}
	}
		Sprite*errorPos = Sprite::create("Tower/ErrorPos.png");
		errorPos->setPosition(blockCenter);
		layer->addChild(errorPos);
		auto action = Sequence::create(FadeOut::create(3), CallFunc::create([=]{
			errorPos->removeFromParent(); }), NULL);
			errorPos->runAction(action);
			return layer;
	
}

