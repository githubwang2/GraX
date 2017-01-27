//
//	ComLife.h
//
//	TowerWar
//
//	Create by wang2 on	17-1-27
//
#ifndef __TowerWar_ComLife__
#define __TowerWar_ComLife__

#include "cocos2d.h"
#include"ui/CocosGUI.h"

//�����HP���
class ComLife :public cocos2d::Component
{
protected:
	ComLife(int maxLife);
public:
	//��HP
	static ComLife*create(int maxLife);

	virtual void onEnter() override;
	
	bool attacked(int damage);

private:

	cocos2d::ui::LoadingBar*m_hpBar;
	float m_maxLife;
	float m_currentHp;						//	��ǰHP

};

#endif