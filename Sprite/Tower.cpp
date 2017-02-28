#include "Sprite/Tower.h"
#include"Sprite/Components/ComTower.h"
#include"Layer/HUDLayer.h"

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
			if (curGold < 150)		//判断金钱是否足够 不够时金钱变红 无法产生防御塔
			{
				playground->goldWarn();
				return true;//跳出 不运行下面错误的图片
			}
			else                   ///金钱足够  扣除金钱  创建防御塔
			{

				playground->changeGold(-150);
				Sprite*tower = Sprite::create("GameMain/Tower.png");
				tower->setPosition(blockCenter);

				//将comTower挂载到每个tower上
				auto comTower = ComTower::create();
				tower->addComponent(comTower);
				//存入FireManager的m_towers list中
				GameMainLayer::fileManager->m_towers.push_back(comTower);
				//-----------------
				addChild(tower);
				return true;//跳出 不运行下面错误的图片
			}
		}
	}
	Sprite*errorPos = Sprite::create("GameMain/ErrorPos.png");
	errorPos->setPosition(blockCenter);
	addChild(errorPos);
	auto action = Sequence::create(FadeOut::create(3), CallFunc::create([=]{
		errorPos->removeFromParent(); }), NULL);
		errorPos->runAction(action);
		return true;
}