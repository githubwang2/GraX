#ifndef __TowerWar_MonstersMessage__
#define __TowerWar_MonstersMessage__
#include "cocos2d.h"

class MonstersMessage
{
public:
	MonstersMessage();
	int getNumOfMonsters();
	std::string getNameOfMonsters(int id);
	int getSpeedOfMonsters(int id);
	int getHpOfMonsters(int id);

private:
	void getMessage();

	int m_numOfMonsters;
	int m_hp;
	int m_id;
	int m_speed;
	std::string m_name;
};


#endif 
