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
		SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Sounds/BG_1.mid");
		SimpleAudioEngine::getInstance()->playBackgroundMusic("Sounds/BG_1.mid",true);
		curBGMState = CurBGMState::curMenuState;
		break;
	case BGMState::MainGameBGM:
		if (curBGMState == CurBGMState::curMainGame)
		{
			return;
		}
		SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Sounds/BG_3.mid");
		SimpleAudioEngine::getInstance()->playBackgroundMusic("Sounds/BG_3.mid",true);
		curBGMState = CurBGMState::curMainGame;
		break;
	case BGMState::DiologBGM:
		if (curBGMState == CurBGMState::curDiologBGM)
		{
			return;
		}
		SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Sounds/BG_6.mid");
		SimpleAudioEngine::getInstance()->playBackgroundMusic("Sounds/BG_6.mid", true);
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
	SimpleAudioEngine::sharedEngine()->setEffectsVolume(0);
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
		SimpleAudioEngine::sharedEngine()->preloadEffect("Sounds/MenuSelect.mp3");
		SimpleAudioEngine::sharedEngine()->playEffect("Sounds/MenuSelect.mp3", false);
		break;
	case SoundsControl::BuyItem:
		SimpleAudioEngine::sharedEngine()->preloadEffect("Sounds/BuyItem.mp3");
		SimpleAudioEngine::sharedEngine()->playEffect("Sounds/BuyItem.mp3", false);
		break;
	case SoundsControl::Bomb:
		SimpleAudioEngine::sharedEngine()->preloadEffect("Sounds/Bomb.mp3");
		SimpleAudioEngine::sharedEngine()->playEffect("Sounds/Bomb.mp3", false);
		break;
	case SoundsControl::OneStar:
		SimpleAudioEngine::sharedEngine()->preloadEffect("Sounds/ME_1.mid");
		SimpleAudioEngine::sharedEngine()->playEffect("Sounds/ME_1.mid", false);
		break;
	case SoundsControl::TwoStars:
		SimpleAudioEngine::sharedEngine()->preloadEffect("Sounds/ME_2.mid");
		SimpleAudioEngine::sharedEngine()->playEffect("Sounds/ME_2.mid", false);
		break;
	case SoundsControl::ThreeStars:
		SimpleAudioEngine::sharedEngine()->preloadEffect("Sounds/ME_3.mid");
		SimpleAudioEngine::sharedEngine()->playEffect("Sounds/ME_3.mid", false);
		break;
	case SoundsControl::GameOver:
		SimpleAudioEngine::sharedEngine()->preloadEffect("Sounds/ME_4.mid");
		SimpleAudioEngine::sharedEngine()->playEffect("Sounds/ME_4.mid", false);
		break;
	default:
		break;
	}
}


