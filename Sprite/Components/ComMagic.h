#ifndef __TowerWar_ComMagic__
#define __TowerWar_ComMagic__

#include "cocos2d.h"
#include "Sprite/Components/Constants.h"
#include "MagicMessage.h"

class ComMagic :public cocos2d::Component
{
protected:
	ComMagic(int magicID);
public:
	static ComMagic*create(int magicID);
	CC_SYNTHESIZE(bool, m_isFiring, IsFire);					// ÊÇ·ñÕýÔÚ¹¥»÷
	CC_PROPERTY_READONLY(int, m_range, Range);					// ¹¥»÷·¶Î§
	CC_SYNTHESIZE_READONLY(float, m_reloadTime, RelodTime);		// ¹¥»÷¼ä¸ô
	CC_SYNTHESIZE_READONLY(int, m_magicDamage,  MaigcDamage);	// ÉËº¦
	CC_SYNTHESIZE_READONLY(int, m_bulletDamage, BulletDamage);	// ÉËº¦
	CC_SYNTHESIZE_READONLY(int, m_bulletSpeed, BulletSpeed);	// ËÙ¶È

private:
	virtual void onEnter() override;
	int m_magicID;
};
#endif