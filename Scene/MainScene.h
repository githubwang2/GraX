
#ifndef __TowerWar_MainScene__
#define __TowerWar_MainScene__
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "HUDLayer/HUDLayer.h"

#include"GameMap.h"

class MainScene : public cocos2d::Layer
{
public:

	static cocos2d::Scene* createScene();
	virtual bool init();
	


	CREATE_FUNC(MainScene);

	void addMonster(float dt);

	void attachTowerBuild();
	//������Ϸ�����ﱻɱ��������Ϸʧ�ܣ�
	void endGame(bool isWin);
	//�Ƴ����� 
	void removeMonster(Node* monster);
private:

	void initBG();
	cocos2d::Size visibleSize;

	GameMap *gameMap;

	//HUDLayer*hud;
	int     m_beginHp;		//	��ʼʱ�������ֵ
	int		m_beginGold;	//	��ʼʱ��ҽ�Ǯ
	int		m_level;		//	��ǰ�ؿ���
	int     m_level_WavNum;  //	��ǰ�ؿ������ܲ���
	bool	m_isWin;		//	
};

#endif 
