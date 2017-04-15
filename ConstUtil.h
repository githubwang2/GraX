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

//-----------------------Tower---------------------

//p子弹  从缓存中读取 所以不用Tower/
//火箭
#define		Rocket1_IMG				"Rocket-1.png"
#define		Rocket2_IMG				"Rocket-2.png"
#define		Rocket3_IMG				"Rocket-3.png"
#define		Rocket4_IMG				"Rocket-4.png"
#define		PRocket1_IMG			"PRocket1.png"
#define		PRocket2_IMG			"PRocket2.png"
#define		PRocket3_IMG			"PRocket3.png"
#define		PRocket4_IMG			"PRocket4.png"
//弓箭
#define		Arrow1_IMG				"Arrow-1.png"
#define		Arrow2_IMG				"Arrow-2.png"
#define		Arrow3_IMG				"Arrow-3.png"
#define		PArrow_IMG				"PArrow1.png"
//炮
#define		Bottle1_IMG				"Bottle-1.png"
#define		Bottle2_IMG				"Bottle-2.png"
#define		Bottle3_IMG				"Bottle-3.png"
#define		PBottle1_IMG			"PBottle3.png"
//风扇
#define		Fan1_IMG				"Fan-1.png"
#define		Fan2_IMG				"Fan-2.png"
#define		Fan3_IMG				"Fan-3.png" 
#define		PFan1_IMG				"PFan1.png"
#define		PFan2_IMG				"PFan2.png"
#define		PFan3_IMG				"PFan3.png"
#define		PFan01_IMG				"PFan01.png"//风扇爆炸
#define		PFan02_IMG				"PFan02.png"

//-----------------------SoundsControl---------------------

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#define		MENU_SELECTl_VOI		"Sounds/MenuSelect.mp3"
#define		BUY_ITEM_VOI			"Sounds/BuyItem.mp3"
#define		BOMB_VOI				"Sounds/Bomb.mp3"
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#define		MENU_SELECTl_VOI		"Sounds/MenuSelect.wav"
#define		BUY_ITEM_VOI			"Sounds/BuyItem.wav"
#define		BOMB_VOI				"Sounds/Bomb.wav"
#endif


#endif 
