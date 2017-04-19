#ifndef __TowerWar_ComLife__
#define __TowerWar_ComLife__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

//�����HP���
class ComLife :public cocos2d::Component
{
public:
	//��HP
	static ComLife*create(int maxLife);

	virtual void onEnter() override;
	
	bool attacked(float damage);

private:
	ComLife(int maxLife);
	cocos2d::ui::LoadingBar*m_hpBar;
	float m_maxLife;
	float m_currentHp;						

};

#endif