
#ifndef __TowerWar_GameMAP__
#define __TowerWar_GameMAP__
#include "cocos2d.h"

class GameMap : public cocos2d::Layer
{
public:
	//创建瓦片地图
	GameMap* createTMXTiledMap(char*tileMap);
	//取得移动路径
	std::vector<cocos2d::Point>	getWalkPath(const char*key);
	//可坐标是否可以放置防御塔
	std::string getTowerValue(cocos2d::Point&posIngl);

	virtual bool init(char*tileMap);

private:

	std::string		getValue(std::string key, cocos2d::Point&posIngl, cocos2d::TMXLayer*layer, cocos2d::TMXTiledMap*map);

	cocos2d::Point	worldToTile(cocos2d::Point &pos);		//cocos2dx坐标  转化为  Tiled坐标 （y轴相反）

	static  cocos2d::TMXTiledMap				* m_tileMap;
	static	cocos2d::TMXLayer				* m_bulid;

};

#endif 
