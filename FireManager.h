#ifndef __TowerWar_FireManager__
#define __TowerWar_FireManager__
#include "Sprite/Components/Constants.h"
#include "SoundsControl.h"
#include "ConstUtil.h"
USING_NS_CC;

//·ÀÓùËþ×Óµ¯¹ÜÀí(ÒÆ¶¯ºÍÅö×²)
class FireManager :public Layer
{
public:

	CREATE_FUNC(FireManager);
	//×Óµ¯ÒÆ¶¯
	void moveBullet(float dt);
	//Í£Ö¹¹¥»÷
	void endMoveBullet();
private:
	void towers();
	void bullets();
	void magic();

	void FanAttackType();
	void ArrowAttackType();
	void RocketAttackType();
	void BottleAttackType();

	void FanBulletManager();
	void ArrowBulletManager();
	void RocketBulletManager();
	void BottleBulletManager();

	void anchorAttackType();
	void anchorBulletManager();

	void FBottleAttackType();
	void FBottleBulletManager();

	cocos2d::Size visibleSize;
	bool hitMonster;

	virtual bool init();
	void createBoom(int x, int y);
	void endBoom(Node*node);
	void createFunBoom(int x, int y);
	void endFunBoom(Node*node);
	void createFire(int x, int y);
	void endFire(Node*node);
	void createIce(int x, int y);
	void endIce(Node*node);
	void createStars(int x, int y);
	void endStars(Node*node);

public:
	std::list<ComBullet*>	m_bullets;
	std::list<ComTower*>	m_towers;

	//tower
	std::list<ComTower*>	m_fanTowers;
	std::list<ComTower*>    m_arrowTowers;
	std::list<ComTower*>    m_rocketTower;
	std::list<ComTower*>    m_bottleTowers;
	//bullet
	std::list<ComBullet*>	m_fanBullets;
	std::list<ComBullet*>	m_arrowBullets;
	std::list<ComBullet*>	m_rocketBullets;
	std::list<ComBullet*>	m_bottleBullets;
	//monster
	std::list<ComMove*>		m_monsters;
	std::list<ComMove*>		m_tmpMonster;

	//maigc
	std::list<ComTower*>    m_anchorTowers;
	std::list<ComBullet*>    m_anchorBullets;

	std::list<ComMagic*>    m_FBottleMagic;
	std::list<ComBullet*>    m_FBottleBullets;

	std::list<ComMagic*>    m_sunMagic;
	std::list<ComMagic*>    m_snowMagic;
	std::list<ComMagic*>    m_starMagic;
};

#endif