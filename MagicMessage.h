#ifndef __TowerWar_MagicMessage__
#define __TowerWar_MagicMessage__
#include "cocos2d.h"

class MagicMessage
{
public:
	MagicMessage(int magicID);
	int		getMagicRange();			// ¹¥»÷·¶Î§
	int		getMagicDamage();			// ¹¥»÷ÉËº¦
	int		getMagicReloadTime();			
	int		getMagicBulletDamage();
	int		getMagicBulletSpeed();

private:
	void	getMessage();

	int		m_magicID;
	int		m_magicRange;
	int		m_magicDamage;
	int		m_magicReloadTime;
	int		m_magicBulletDamage;
	int		m_magicBulletSpeed;
};


#endif 
