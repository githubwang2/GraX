#ifndef __TowerWar_LoadingScene__
#define __TowerWar_LoadingScene__
#include "cocos2d.h"
#include "ui/UIVideoPlayer.h"
#include "ui/CocosGUI.h"

class LoadingScene : public cocos2d::Layer
{
public:

	static cocos2d::Scene* createScene();
	
	CREATE_FUNC(LoadingScene);

private:
	virtual bool init();

	void gotoMenuScene();
	void playOP();
	void load();
	void loadingCallBack(cocos2d::Texture2D *texture);
	void endOP();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	void videoEventCallback(Ref* sender, cocos2d::experimental::ui::VideoPlayer::EventType eventType);
#endif

	cocos2d::Size visibleSize;
	cocos2d::ProgressTimer* loadProgress;
	cocos2d::LabelTTF* loadLabel;
	///---------------------------------
	int  _allOfSprites;							//	总共需要预加载文件数
	int _numberOfLoadedSprites;				    //	已经预加载文件数
};

#endif 
