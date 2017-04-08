#include "TowersMessage.h"

USING_NS_CC;

TowersMessage::TowersMessage()
{
	
}


void TowersMessage::createRocket(cocos2d::Point pos)
{
	auto playground = dynamic_cast<GameMainLayer*>(this->getParent()->getParent());
	auto curGold = playground->changeGold(0);
	if (curGold < 150)		//判断金钱是否足够 不够时金钱变红 无法产生防御塔
	{
		playground->goldWarn();
		return ;//跳出 不运行下面错误的图片
	}
	else                   ///金钱足够  扣除金钱  创建防御塔
	{
		playground->changeGold(-150);
		Sprite*tower = Sprite::create(Tower1_IMG);
		tower->setPosition(pos);

		//将comTower挂载到每个tower上
		auto comTower = ComTower::create();
		tower->addComponent(comTower);
		//存入FireManager的m_towers list中
		GameMainLayer::fileManager->m_towers.push_back(comTower);
		//-----------------
		addChild(tower);
		SoundsControl::setSound(SoundsControl::SoundState::BuyItem);
		return ;//跳出 不运行下面错误的图片
	}
}
