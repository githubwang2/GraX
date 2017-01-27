//
//	LoadingScene.h
//
//	TowerWar
//
//	Create by wang2 on	17-1-26
//
#ifndef __TowerWar_LoadingScene__
#define __TowerWar_LoadingScene__
#include "cocos2d.h"

class LoadingScene : public cocos2d::Layer
{
public:

	static cocos2d::Scene* createScene();
	virtual bool init();

	void run();

	CREATE_FUNC(LoadingScene);
private:
	cocos2d::Size visibleSize;

	cocos2d::CCLabelTTF *m_pLabelLoading;//文字标签，用于显示“Loading”字样  
	cocos2d::CCLabelTTF *m_pLabelPercent;//文字标签，用于显示百分比  

	int currentNum;//当前加载到第几张  
	int totalNum;//加载总数  
};

#endif 
