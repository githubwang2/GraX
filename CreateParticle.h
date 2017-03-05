#ifndef __TowerWar_CreateParticle__
#define __TowerWar_CreateParticle__
#include "cocos2d.h"

class CreateParticle : public cocos2d::Layer
{
public:
	//1 snow 2 rain 3 clear 4 setting
	static CreateParticle*create(int id);
private:
	cocos2d::Size visibleSize;

	virtual bool init(int id);

	void snow(); 
	void rain();
	void clear();
	void setting();
	
};

#endif 
