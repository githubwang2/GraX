#ifndef __TowerWar_FireManager__
#define __TowerWar_FireManager__
#include "Sprite/Components/Constants.h"
#include "SoundsControl.h"
#include "ConstUtil.h"
USING_NS_CC;

//·ÀÓùËþ×Óµ¯¹ÜÀí(ÒÆ¶¯ºÍÅö×²)
class FireManager:public Layer
{
public:

	CREATE_FUNC(FireManager);
	//×Óµ¯ÒÆ¶¯
	void moveBullet(float dt);
	//Í£Ö¹¹¥»÷
	void endMoveBullet();
private:
	void bullets();
	void towers();
	void FanAttackType();
	void ArrowAttackType();
	void RocketAttackType();
	void BottleAttackType();

	void FanBulletManager();
	void ArrowBulletManager();
	void RocketBulletManager();
	void BottleBulletManager();

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

public:
	std::list<ComBullet*>	m_bullets;
	std::list<ComTower*>	m_towers;

	std::list<ComTower*>	m_fanTowers;
	std::list<ComTower*>    m_arrowTowers;
	std::list<ComTower*>    m_rocketTower;
	std::list<ComTower*>    m_bottleTowers;

	std::list<ComBullet*>	m_fanBullets;
	std::list<ComBullet*>	m_arrowBullets;
	std::list<ComBullet*>	m_rocketBullets;
	std::list<ComBullet*>	m_bottleBullets;

	std::list<ComMove*>		m_monsters;
	std::list<ComMove*>		m_tmpMonster;

	void anchorAttackType();
	void anchorBulletManager();
	std::list<ComTower*>    m_anchorTowers;
	std::list<ComBullet*>    m_anchorBullets;
};

#endif