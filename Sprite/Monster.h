
#ifndef __TowerWar_Monster__
#define __TowerWar_Monster__
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"


class Monster : public cocos2d::Layer
{
protected:
	
public:
	Monster(int id);
	void initAnimation(int id);
private:
	
	cocos2d::Animation*ani_up;
	cocos2d::Animation*ani_down;
	cocos2d::Animation*ani_left;
	cocos2d::Animation*ani_right;
};

#endif 
