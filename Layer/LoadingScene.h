#ifndef __TowerWar_LoadingScene__
#define __TowerWar_LoadingScene__
#include "cocos2d.h"

class LoadingScene : public cocos2d::Layer
{
public:

	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(LoadingScene);

private:
	void gotoMenuScene();
	void playOP();
	void load();
	void loadingCallBack(cocos2d::Texture2D *texture);

	cocos2d::Size visibleSize;
	cocos2d::ProgressTimer* loadProgress;
	cocos2d::LabelTTF* loadLabel;
	///---------------------------------
	int  _numberOfSprites;						//	总共需要预加载文件数
	int _numberOfLoadedSprites;				//	已经预加载文件数
};

#endif 
