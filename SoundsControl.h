#ifndef __TowerWar_SoundsControl__
#define __TowerWar_SoundsControl__
#include "cocos2d.h"
#include "ConstUtil.h"
class SoundsControl
{
public:
	SoundsControl();
	enum BGMState
	{
		MenuBGM = 0,
		MainGameBGM,
		DiologBGM
	};
	enum SoundState
	{
		BtnSelect,
		BuyItem,
		Bomb,
		OneStar,
		TwoStars,
		ThreeStars,
		GameOver
	};
	static void setBGM(BGMState bgmState);
	
	static void setSound(SoundState soundState);
	//--ֻ��settting�е���
	static void stopBGM();
	static void startBGM();
private:
	
	enum CurBGMState
	{
		curNull ,
		curMenuState,
		curMainGame,
		curDiologBGM
	};
	static CurBGMState curBGMState;
};


#endif 
