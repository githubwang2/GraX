#ifndef __TowerWar_ComBullet__
#define __TowerWar_ComBullet__

#include "cocos2d.h"

//防御塔子弹组件

class ComBullet :public cocos2d::Component
{
protected:
	ComBullet(float fireDamage, float speed);

public:
	//子弹伤害，子弹速度
	static ComBullet*create(float fireDamage, float speed);

	virtual void onEnter() override;

	//塔的坐标   怪物的坐标
	//返回 子弹对准怪物 所需旋转角度
	float setSpeedXY(cocos2d::Point org, cocos2d::Point des);

	CC_SYNTHESIZE_READONLY(float, m_speedX, SpeedX);					//子弹速度X轴上的分量
	CC_SYNTHESIZE_READONLY(float, m_speedY, SpeedY);					//子弹速度Y轴上的分量
	CC_SYNTHESIZE_READONLY(float, m_fireDamage, FireDamage);            //每颗子弹的伤害

private:
	float m_speed;
};

#endif