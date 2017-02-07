#include "GameMap.h"

GameMap *GameMap::createTMXTiledMap(char*tileMap)
{
	GameMap* gameMap = new GameMap();
	if (gameMap != nullptr && gameMap->init(tileMap))
	{
		gameMap->autorelease();
	}
	else
	{
		//CC_SAFE_DELETE(gameMap);
	}
	return gameMap;
}

bool GameMap::init(char*tileMap)
{
	if (!Layer::init())
	{
		return false;
	}

	m_tileMap = TMXTiledMap::create("Tower/TowerTileMap/gate1.tmx");
	addChild(m_tileMap, -1);
	getWalkPath("Walk");

	m_bulid = m_tileMap->getLayer("meta");
	m_bulid->setVisible(false);

	return true;
}


std::vector<Point>GameMap::getWalkPath(const char*key){
	std::vector<Point>pathVec;
	if (!m_tileMap)
	{
		CCLOG("can't find map");
		return pathVec;
	}

	TMXObjectGroup*walk = m_tileMap->getObjectGroup(key);

	if (!walk)
	{
		CCLOG("no such key = %s", key);
		return pathVec;
	}

	ValueVector path = walk->getObjects();

	int myX = 0;
	int myY = 0;
	for (auto pos : path)
	{
		myX = pos.asValueMap()["x"].asInt();
		myY = pos.asValueMap()["y"].asInt();
		CCLOG("find the pos x:%d\ty:%d", myX, myY);
		pathVec.push_back(Point(myX, myY));
	}
	return pathVec;
}

std::string GameMap::getTowerValue(Point&posIngl){
	auto value = getValue("Build", posIngl, m_bulid, m_tileMap);
	return value;
}

Point GameMap::worldToTile(Point &pos, TMXTiledMap*map){
	int x = pos.x / 80;
	int y = (640 - pos.y) / 80;
	return Point(x, y);
}

std::string GameMap::getValue(std::string key, Point&posIngl, TMXLayer*layer, TMXTiledMap*map){
	Point pos = worldToTile(posIngl,map);
	int tileGID = layer->getTileGIDAt(pos);
	if (tileGID)
	{
		Value pro = map->getPropertiesForGID(tileGID);
		auto map = pro.asValueMap();
		auto pos = map.find(key);
		if (pos != map.end())
		{
			return pos->second.asString();
		}
		else
		{
			return "";
		}
	}
	else
	{
		return "";
	}
}

