//
//	MainScene.h
//
//	TowerWar
//
//	Create by wang2 on	17-1-27
//
#ifndef __TowerWar_MainScene__
#define __TowerWar_MainScene__
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace cocostudio;
using namespace ui;

const int monster_speed = 100;

class MainScene : public cocos2d::Layer
{
public:

	static cocos2d::Scene* createScene();
	virtual bool init();
	//--------------------------------------------------------------------
	//后面可以考虑把背景单独放一个类里面做处理  根据m_gameState自动设置每个的背景
	void initBG();
	void initTMXTiledMap();
	void initHUD();

	//生成怪物
	void makeMonster(float dt);

	//--------------HUD-------------------------------------
	//生成怪物波数
	void createWaveRusher();

	void changeGold(int num);
	//生命
	int changeLife(int num);		//返回life 因为要判定是否为0

	CREATE_FUNC(MainScene);
private:
	Size visibleSize;

	TMXTiledMap*m_tileMap;
	TMXLayer*m_bulid;
	//应该是cocos2d的Vector其元素不能是结构体，可以用std的vector。
	std::vector<Point>m_pathVec;	//怪物行走的路径信息
	//从walk对象层中取出每个点的位置
	std::vector<Point>getWalkPath(const char*key);


	//--------------HUD-------------------------------------
	//生成怪物的波数
	int m_curRound;
	//该波生成怪物的数量
	int m_monsterCreateLeft;

	int m_gold = 0;

	int m_curLife = 0;
};

#endif 
