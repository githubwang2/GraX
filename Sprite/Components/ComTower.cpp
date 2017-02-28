#include "Sprite/Components/ComTower.h"

USING_NS_CC;


ComTower::ComTower():m_isFiring(false)
{
	setName("ComTower");
}

ComTower*ComTower::create()
{
	ComTower*ret = new ComTower();
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
	m_range = tower_range;
	m_reloadTime = tower_reloadTime;	
}

int ComTower::getRange() const
{
	return m_range;
}