
#ifndef __TowerWar_GameMAP__
#define __TowerWar_GameMAP__
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace cocostudio;
using namespace ui;



class GameMap : public cocos2d::Layer
{
public:
	//������Ƭ��ͼ
	GameMap* createTMXTiledMap(char*tileMap);
	//ȡ���ƶ�·��
	std::vector<Point>	getWalkPath(const char*key);
	//ȡ�ÿ��Է��÷�����������
	//ȡ����Ƭ �ڸ���Ƭ��ͼ   �ò�  ������ 
	std::string getTowerValue(Point&posIngl);

	virtual bool init(char*tileMap);

private:
	std::string getValue(std::string key, Point&posIngl, TMXLayer*layer, TMXTiledMap*map);

	cocos2d::Point	worldToTile(cocos2d::Point &pos, TMXTiledMap*map);		//cocos2dx����  ת��Ϊ  Tiled���� ��y���෴��

	TMXTiledMap				* m_tileMap;

	TMXLayer				* m_bulid;
};
#endif 
