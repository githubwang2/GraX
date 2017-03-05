#ifndef __TowerWar_WavesMessage__
#define __TowerWar_WavesMessage__
#include "cocos2d.h"

class WavesMessage 
{
public:
	WavesMessage(int pStage, int pLevel);
	~WavesMessage();

	void updataLevelMessage();
	//设置当前波数
	void setCurNo(int curNo);
	//取得该波怪物编号
	int getCurMonsterId();
	//取得该波怪物数量
	int getCurMonsterNum ();
	//取得该波每个怪物间生成时间间隔
	float getMonsterInterval();
	//取得下波怪物生成时间间隔
	float getWaveInteval();
public:
	void getMessage();

	void getBeginMessage();
	int m_stage;
	int m_level; 
	//怪关卡初始信息
	int m_beginHp;
	int m_beginGold;
	//波数信息
	int m_numOfWav;                 // 该关卡总波数
	int m_curNo;					// 第几波
	int m_id;						// 怪物编号
	std::vector<int> vecId;
	int m_num;						// 该波怪物数量
	std::vector<int> vecNum;
	float m_monster_interval;		// 怪物产生时间间隔
	std::vector<float> vecMonsterInterval;
	float m_wave_inteval;			// 波数时间间隔
	std::vector<float> vecWaveInterval;
};

#endif
