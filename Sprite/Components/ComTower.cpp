#include "Sprite/Components/ComTower.h"

USING_NS_CC;

ComTower::ComTower(int towerID, int towerLevel) :m_isFiring(false)
{
	setName("ComTower");
	m_towerID = towerID;
	m_towerLevel = towerLevel;
}

ComTower*ComTower::create(int towerID, int towerLevel)
{
	ComTower*ret = new ComTower(towerID,towerLevel);
	if (ret!=nullptr&&ret->init())
	{
		ret->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(ret);
	}
	return ret;
}

void ComTower::onEnter(){
	auto tower=new TowersMessage(m_towerID,m_towerLevel);
	m_range = tower->getTowerRange();
	m_reloadTime = tower->getTowerReloadTime();
	m_bulletDamage = tower->getBulletDamage();
	m_bulletSpeed = tower->getBulletSpeed();
}

int ComTower::getRange() const
{
	return m_range;
}

