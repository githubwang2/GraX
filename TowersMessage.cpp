#include "TowersMessage.h"

USING_NS_CC;

TowersMessage::TowersMessage()
{
	
}


void TowersMessage::createRocket(cocos2d::Point pos)
{
	auto playground = dynamic_cast<GameMainLayer*>(this->getParent()->getParent());
	auto curGold = playground->changeGold(0);
	if (curGold < 150)		//�жϽ�Ǯ�Ƿ��㹻 ����ʱ��Ǯ��� �޷�����������
	{
		playground->goldWarn();
		return ;//���� ��������������ͼƬ
	}
	else                   ///��Ǯ�㹻  �۳���Ǯ  ����������
	{
		playground->changeGold(-150);
		Sprite*tower = Sprite::create(Tower1_IMG);
		tower->setPosition(pos);

		//��comTower���ص�ÿ��tower��
		auto comTower = ComTower::create();
		tower->addComponent(comTower);
		//����FireManager��m_towers list��
		GameMainLayer::fileManager->m_towers.push_back(comTower);
		//-----------------
		addChild(tower);
		SoundsControl::setSound(SoundsControl::SoundState::BuyItem);
		return ;//���� ��������������ͼƬ
	}
}
