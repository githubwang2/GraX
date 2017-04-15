#ifndef __TowerWar_TowersMessage__
#define __TowerWar_TowersMessage__
#include "cocos2d.h"

class TowersMessage
{
public:
	TowersMessage(int towerID,int towerLevel);

	int		getTowerRange();			// ������������Χ
	float	getTowerReloadTime();		// �������������
	int		getTowerType();				// ������������ʽ

	int		getBulletDamage();			// �ӵ��˺�
	int		getBulletSpeed();			// �ӵ��ٶ�
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
