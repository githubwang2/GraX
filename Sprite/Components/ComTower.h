#ifndef __Tower_ComTower__
#define __Tower_ComTower__

#include "cocos2d.h"

class ComTower :public cocos2d::Component
{
protected:
	ComTower();

public:

	static ComTower*create();

	virtual void onEnter() override;

	CC_SYNTHESIZE(bool, m_isFiring, IsFire);				//塔是否开火
	CC_PROPERTY_READONLY(int, m_range, Range);				//塔的攻击范围
	CC_SYNTHESIZE_READONLY(float, m_reloadTime, RelodTime);	//塔的攻击间隔

private:

};
#endif