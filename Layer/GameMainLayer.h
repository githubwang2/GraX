#ifndef __TowerWar_GameMainLayer__
#define __TowerWar_GameMainLayer__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "GameMap.h"
#include "FireManager.h"
#include "Layer/HUDLayer.h"
#include "Layer/PopupLayer.h"
#include "Layer/LevelChooseLayer.h"
#include "Layer/StageChooseLayer.h"

#include "Sprite/Monster.h"
#include "Sprite/Tower.h"

class GameMainLayer : public cocos2d::Layer
{
public:
	static GameMainLayer*create();
	virtual bool init();

	void addMonster(float dt);

    void attachTowerBuild(GameMap *gameMap);
	//������Ϸ�����ﱻɱ�������Ϸʧ�ܣ�
	//void endGame(bool isWin);
	//�Ƴ����� 
	//void removeMonster(Node* monster);
	
	int  changeGold(int i);
	int  changeLife(int num);
	void goldWarn();
	static HUDLayer*hudLayer;
	static FireManager*fileManager;
private:

	void initBG();

	cocos2d::Size visibleSize;

	//GameMap *gameMap;
	int m_currentStage;
	int m_currentLevel;

	
	int     beginHp;			//	��ʼʱ�������ֵ
	int		beginGold;			//	��ʼʱ��ҽ�Ǯ
	int		level;				//	��ǰ�ؿ���
	int     level_WavNum;		//	��ǰ�ؿ������ܲ���
	//bool	m_isWin;		//	

};

#endif 
