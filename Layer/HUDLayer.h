#ifndef __TowerWar_HUDLayer__
#define __TowerWar_HUDLayer__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

class HUDLayer : public cocos2d::Layer
{
public:
	bool init();
	CREATE_FUNC(HUDLayer);
	//��ʼ����Ǯ �ܲ��� ����ֵ
	void setInitHUD(int gold, int allRound, int life);
	//���ɹ��ﲨ��
	void createWaveRusher();
	//��Ǯ
	int changeGold(int num);
	//����
	int changeLife(int num);		//	����life ��ΪҪ�ж��Ƿ�Ϊ0

	void goldWarn();
private:
	cocos2d::ui::Widget		*		m_hud;
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
