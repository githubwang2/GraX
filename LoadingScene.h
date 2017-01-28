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
	void load();

	CREATE_FUNC(LoadingScene);
private:
	cocos2d::Size visibleSize;

	cocos2d::CCLabelTTF *m_pLabelLoading;//文字标签，用于显示“Loading”字样  
	cocos2d::CCLabelTTF *m_pLabelPercent;//文字标签，用于显示百分比  

	int currentNum;//当前加载到第几张  
	int totalNum;//加载总数  

	cocos2d::ProgressTimer* loadProgress;
	cocos2d::LabelTTF* loadLabel;
	int  _numberOfSprites=2;
	int _numberOfLoadedSprites=0;
	void loadingCallBack(cocos2d::Texture2D *texture);
};

#endif 
