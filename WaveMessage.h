#ifndef __TowerWar_WavesMessage__
#define __TowerWar_WavesMessage__
#include "cocos2d.h"

class WavesMessage 
{
public:
	WavesMessage(int pStage, int pLevel);
	~WavesMessage();

	void updataLevelMessage();
	//���õ�ǰ����
	void setCurNo(int curNo);
	//ȡ�øò�������
	int getCurMonsterId();
	//ȡ�øò���������
	int getCurMonsterNum ();
	//ȡ�øò�ÿ�����������ʱ����
	float getMonsterInterval();
	//ȡ���²���������ʱ����
	float getWaveInteval();
public:
	void getMessage();

	void getBeginMessage();
	int m_stage;
	int m_level; 
	//�ֹؿ���ʼ��Ϣ
	int m_beginHp;
	int m_beginGold;
	//������Ϣ
	int m_numOfWav;                 // �ùؿ��ܲ���
	int m_curNo;					// �ڼ���
	int m_id;						// ������
	std::vector<int> vecId;
	int m_num;						// �ò���������
	std::vector<int> vecNum;
	float m_monster_interval;		// �������ʱ����
	std::vector<float> vecMonsterInterval;
	float m_wave_inteval;			// ����ʱ����
	std::vector<float> vecWaveInterval;
};

#endif
