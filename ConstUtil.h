//
//	ConstUtil.h
//
//	TowerWar
//
//	Create by wang2 on	17-1-24
//
#ifndef  __CONSTUTIL_H__
#define  __CONSTUTIL_H__

//-----------------------GameState----------------
const		int						MAX_STAGE = 4;
const		int						MAX_LEVEL = 3;

//-----------------------SplashScene---------------------

const		double					MOVE_SPLEED = 0.5f;
const		int						ONE_SECOND = 1;

#define		W_IMG					"StartScene/W.png"
#define		A_IMG					"StartScene/A.png"
#define		N_IMG					"StartScene/N.png"
#define		G_IMG					"StartScene/G.png"

//-----------------------LoadingScene---------------------

#define		PROGRESSBAR_BG			"StartScene/ProgressBarBG.png"
#define		PROGRESS_BAR			"StartScene/ProgressBar.png"
#define     ADD_CACHE				Director::getInstance()->getTextureCache()->addImageAsync

//-----------------------MenuScene---------------------

#define		BTN_START				"btnGameStart"
#define		BTN_DEX				    "btnGameDex"
#define		BTN_RESTART				"btnGameReStart"
#define		BTN_SETTING				"btnGameSetting"
#define		BTN_ABOUT				"btnGameAbout"
#define		BTN_EXIT				"btnGameEnd"
#define		BTN_MENU				"btnGameMenu"

//-----------------------StageChooseScene---------------------

const int STAGE_MAX = 4;
const int SCROLL_WIDTH = 960;			//	滑动区域的大小
const float ADJUEST_TIME = 0.3f;		//	滑动校正时间

#endif 
