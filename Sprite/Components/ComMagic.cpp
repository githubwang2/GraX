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
	auto maigc = new MagicMessage(m_magicID );
	m_range = maigc->getMagicRange();
	m_magicDamage = maigc->getMagicDamage();
	m_reloadTime = maigc->getMagicReloadTime();
	m_bulletDamage= maigc->getMagicBulletDamage();
	m_bulletSpeed= maigc->getMagicBulletSpeed();
}

int ComMagic::getRange() const
{
	return m_range;
}

