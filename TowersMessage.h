#ifndef __TowerWar_TowersMessage__
#define __TowerWar_TowersMessage__
#include "cocos2d.h"

class TowersMessage
{
public:
	TowersMessage(int towerID,int towerLevel);

	int		getTowerRange();			// ·ÀÓùËş¹¥»÷·¶Î§
	float	getTowerReloadTime();		// ·ÀÓùËş¹¥»÷¼ä¸ô
	int		getTowerType();				// ·ÀÓùËş¹¥»÷·½Ê½

	int		getBulletDamage();			// ×Óµ¯ÉËº¦
	int		getBulletSpeed();			// ×Óµ¯ËÙ¶È
private:
	void	getMessage();

	int		m_towerID;	
	int     m_towerLevel;

	int		m_towerRange;
	float	m_towerReloadTime;
	int		m_towerBulletDamage;
	int		m_towerType;
	int		m_towerBulletSpeed;
};


#endif 
