
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
	//创建瓦片地图
	GameMap* createTMXTiledMap(char*tileMap);
	//取得移动路径
	std::vector<Point>	getWalkPath(const char*key);
	//取得可以放置防御塔的坐标
	//取该瓦片 在该瓦片地图   该层  的属性 
	std::string getTowerValue(Point&posIngl);

	virtual bool init(char*tileMap);

private:
	std::string getValue(std::string key, Point&posIngl, TMXLayer*layer, TMXTiledMap*map);

	cocos2d::Point	worldToTile(cocos2d::Point &pos, TMXTiledMap*map);		//cocos2dx坐标  转化为  Tiled坐标 （y轴相反）

	TMXTiledMap				* m_tileMap;

	TMXLayer				* m_bulid;
};
#endif 
