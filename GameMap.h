
#ifndef __TowerWar_GameMAP__
#define __TowerWar_GameMAP__
#include "cocos2d.h"

class GameMap : public cocos2d::Layer
{
public:
	//������Ƭ��ͼ
	GameMap* createTMXTiledMap(char*tileMap);
	//ȡ���ƶ�·��
	std::vector<cocos2d::Point>	getWalkPath(const char*key);
	//�������Ƿ���Է��÷�����
	std::string getTowerValue(cocos2d::Point&posIngl);

	virtual bool init(char*tileMap);

private:

	std::string		getValue(std::string key, cocos2d::Point&posIngl, cocos2d::TMXLayer*layer, cocos2d::TMXTiledMap*map);

	cocos2d::Point	worldToTile(cocos2d::Point &pos);		//cocos2dx����  ת��Ϊ  Tiled���� ��y���෴��

	static  cocos2d::TMXTiledMap				* m_tileMap;
	static	cocos2d::TMXLayer				* m_bulid;

};

#endif 
