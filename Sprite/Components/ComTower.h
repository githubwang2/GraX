#ifndef __TowerWar_ComTower__
#define __TowerWar_ComTower__

#include "cocos2d.h"
#include "Sprite/Components/Constants.h"
#include "TowersMessage.h"

class ComTower :public cocos2d::Component
{
protected:
	ComTower(int towerID, int towerLevel);
public:
	static ComTower*create(int towerID, int towerLevel);
	CC_SYNTHESIZE(bool, m_isFiring, IsFire);					// 塔是否正在开火
	CC_PROPERTY_READONLY(int, m_range, Range);					// 塔的攻击范围
	CC_SYNTHESIZE_READONLY(float, m_reloadTime, RelodTime);		// 塔的攻击间隔

	CC_SYNTHESIZE_READONLY(int, m_bulletDamage, BulletDamage);	// 子弹伤害
	CC_SYNTHESIZE_READONLY(int, m_bulletSpeed, BulletSpeed);	// 子弹速度

	//CC_PROPERTY: 仅仅是定义了set和get 并没有完成这个函数的实现。可能set和get的实现比较复杂
	//CC_SYNTHESIZE：实现了set和get就是最基本的实现方式
private:
	virtual void onEnter() override;
	int m_towerID;
	int m_towerLevel;
};
#endif