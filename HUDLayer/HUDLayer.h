
#ifndef __TowerWar_HUDLayer__
#define __TowerWar_HUDLayer__
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"


class HUDLayer : public cocos2d::Node
{
public:

	cocos2d::Layer* createHUDLayer();
	
	void setHUD(int gold, int allRound, int life);
	//���ɹ��ﲨ��
	void createWaveRusher();
	//��Ǯ
	void changeGold(int num);
	//����
	int changeLife(int num);		//	����life ��ΪҪ�ж��Ƿ�Ϊ0
private:
	cocos2d::ui::Widget		*		hud;
	cocos2d::ui::TextAtlas	*		lblGold;
	cocos2d::ui::TextAtlas	*		lblRound;
	cocos2d::ui::TextAtlas	*		lblLife;
	cocos2d::ui::TextAtlas	*		lblAllRound;

	int m_allRound;					//	�ܲ���
	int m_curRound;					//	��ǰ����
	int m_curGold;					//	��ǰ���
	int m_curLife;					//	��ǰ����
};

#endif 
