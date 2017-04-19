#include "Sprite/Components/ComMagic.h"

USING_NS_CC;

ComMagic::ComMagic(int magicID) :m_isFiring(false)
{
	setName("ComMagic");
	m_magicID = magicID;
}

ComMagic* ComMagic::create(int magicID)
{
	ComMagic*ret = new ComMagic(magicID);
	if (ret != nullptr&&ret->init())
	{
		ret->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(ret);
	}
	return ret;
}

void ComMagic::onEnter(){
	/*auto tower = new TowersMessage(m_towerID, m_towerLevel);
	m_range = tower->getTowerRange();
	m_reloadTime = tower->getTowerReloadTime();
	m_bulletDamage = tower->getBulletDamage();
	m_bulletSpeed = tower->getBulletSpeed();*/
	m_range =100;
	m_reloadTime = 0.0f;
	m_bulletDamage =1;
	m_bulletSpeed = 30;
}

int ComMagic::getRange() const
{
	return m_range;
}

