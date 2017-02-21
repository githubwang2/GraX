#ifndef __TowerWar_GameMainLayer__
#define __TowerWar_GameMainLayer__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "GameMap.h"
#include "Layer/HUDLayer.h"
#include "Layer/PopupLayer.h"
#include "Layer/LevelChooseLayer.h"
#include "Layer/StageChooseLayer.h"

#include "Sprite/Monster.h"

class GameMainLayer : public cocos2d::Layer
{
public:
	static GameMainLayer*create();
	virtual bool init();

	void addMonster(float dt);

    //void attachTowerBuild();
	//������Ϸ�����ﱻɱ�������Ϸʧ�ܣ�
	//void endGame(bool isWin);
	//�Ƴ����� 
	//void removeMonster(Node* monster);
private:

	void initBG();

	cocos2d::Size visibleSize;

	//GameMap *gameMap;

	int m_currentStage;
	int m_currentLevel;

	//HUDLayer*hud;
	//int     m_beginHp;		//	��ʼʱ�������ֵ
	//int		m_beginGold;	//	��ʼʱ��ҽ�Ǯ
	//int		m_level;		//	��ǰ�ؿ���
	//int     m_level_WavNum;  //	��ǰ�ؿ������ܲ���
	//bool	m_isWin;		//	

};

#endif 
