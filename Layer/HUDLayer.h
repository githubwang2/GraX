#ifndef __TowerWar_HUDLayer__
#define __TowerWar_HUDLayer__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

class HUDLayer : public cocos2d::Layer
{
public:
	static void createHUDLayer();
	//��ʼ����Ǯ �ܲ��� ����ֵ
	static void setInitHUD(int gold, int allRound, int life);
	//���ɹ��ﲨ��
	static void createWaveRusher();
	//��Ǯ
	static int changeGold(int num);
	//����
	static int changeLife(int num);		//	����life ��ΪҪ�ж��Ƿ�Ϊ0

	static cocos2d::ui::Widget*getHud();

private:
	static cocos2d::ui::Widget		*		m_hud;
	static cocos2d::ui::TextAtlas	*		lblGold;
	static cocos2d::ui::TextAtlas	*		lblRound;
	static cocos2d::ui::TextAtlas	*		lblLife;
	static cocos2d::ui::TextAtlas	*		lblAllRound;

	static int m_allRound;					//	�ܲ���
	static int m_curRound;					//	��ǰ����
	static int m_curGold;					//	��ǰ���
	static int m_curLife;					//	��ǰ����
};

#endif 
