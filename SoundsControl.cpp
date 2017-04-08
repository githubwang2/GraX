#include "SoundsControl.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

SoundsControl::CurBGMState SoundsControl::curBGMState;

SoundsControl::SoundsControl()
{
	curBGMState = curNull;
}

void SoundsControl::setBGM(BGMState soundState)
{
	bool _isBGM = cocos2d::UserDefault::getInstance()->getBoolForKey("music_on_key");
	if (!_isBGM)
	{
		return;
	}
	switch (soundState)
	{
	case BGMState::MenuBGM:
		if (CurBGMState::curMenuState == curBGMState )
		{
			//先判断当前在放什么BGM
			return;
		}
		SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Sounds/BG_1.mp3");
		SimpleAudioEngine::getInstance()->playBackgroundMusic("Sounds/BG_1.mp3",true);
		curBGMState = CurBGMState::curMenuState;
		break;
	case BGMState::MainGameBGM:
		if (curBGMState == CurBGMState::curMainGame)
		{
			return;
		}
		SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Sounds/BG_3.mp3");
		SimpleAudioEngine::getInstance()->playBackgroundMusic("Sounds/BG_3.mp3",true);
		curBGMState = CurBGMState::curMainGame;
		break;
	case BGMState::DiologBGM:
		if (curBGMState == CurBGMState::curDiologBGM)
		{
			return;
		}
		SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Sounds/BG_6.mp3");
		SimpleAudioEngine::getInstance()->playBackgroundMusic("Sounds/BG_6.mp3", true);
		curBGMState = CurBGMState::curDiologBGM;
		break;
	default:
		break;
	}
}

void SoundsControl::stopBGM()
{
	curBGMState = curNull;
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
	//SimpleAudioEngine::sharedEngine()->stopAllEffects();
}

void SoundsControl::startBGM()
{
	setBGM(BGMState::MenuBGM);
	SimpleAudioEngine::sharedEngine()->setEffectsVolume(1.0);
}

void SoundsControl::setSound(SoundState soundState)
{
	switch (soundState)
	{
	case SoundsControl::BtnSelect:
		SimpleAudioEngine::sharedEngine()->preloadEffect(MENU_SELECTl_VOI);
		SimpleAudioEngine::sharedEngine()->playEffect(MENU_SELECTl_VOI, false);
		break;
	case SoundsControl::BuyItem:
		SimpleAudioEngine::sharedEngine()->preloadEffect(BUY_ITEM_VOI);
		SimpleAudioEngine::sharedEngine()->playEffect(BUY_ITEM_VOI, false);
		break;
	case SoundsControl::Bomb:
		SimpleAudioEngine::sharedEngine()->preloadEffect(BOMB_VOI);
		SimpleAudioEngine::sharedEngine()->playEffect(BOMB_VOI, false);
		break;
	case SoundsControl::OneStar:
		SimpleAudioEngine::sharedEngine()->preloadEffect("Sounds/ME_1.mp3");
		SimpleAudioEngine::sharedEngine()->playEffect("Sounds/ME_1.mp3", false);
		break;
	case SoundsControl::TwoStars:
		SimpleAudioEngine::sharedEngine()->preloadEffect("Sounds/ME_2.mp3");
		SimpleAudioEngine::sharedEngine()->playEffect("Sounds/ME_2.mp3", false);
		break;
	case SoundsControl::ThreeStars:
		SimpleAudioEngine::sharedEngine()->preloadEffect("Sounds/ME_3.mp3");
		SimpleAudioEngine::sharedEngine()->playEffect("Sounds/ME_3.mp3", false);
		break;
	case SoundsControl::GameOver:
		SimpleAudioEngine::sharedEngine()->preloadEffect("Sounds/ME_4.mp3");
		SimpleAudioEngine::sharedEngine()->playEffect("Sounds/ME_4.mp3", false);
		break;
	default:
		break;
	}
}


