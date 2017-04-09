#ifndef __TowerWar_FireManager__
#define __TowerWar_FireManager__
#include "Sprite/Components/Constants.h"
#include "SoundsControl.h"
#include "ConstUtil.h"
USING_NS_CC;

//防御塔子弹管理(移动和碰撞)
class FireManager:public Layer
{
public:

	CREATE_FUNC(FireManager);
	//子弹移动
	void moveBullet(float dt);
	//停止攻击
	void endMoveBullet();
private:
	virtual bool init();
	void createBoom(int x, int y);
	void endBoom(Node*node);
	void createFunBoom(int x, int y);
	void endFunBoom(Node*node);
public:
	std::list<ComBullet*>	m_bullets;
	std::list<ComTower*>	m_towers;;
	std::list<ComMove*>		m_monsters;

	std::list<ComMove*>		m_tmpMonster;
	
};

#endif