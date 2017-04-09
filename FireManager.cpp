#include "FireManager.h"

bool FireManager::init(){
	if (!Layer::init())
	{
		return false;
	}
	schedule(schedule_selector(FireManager::moveBullet));
	return true;
}

void FireManager::moveBullet(float dt){
	if (m_tmpMonster.size() > 0)
	{
		for (auto tmp : m_tmpMonster)
		{
			m_monsters.pop_front();
			tmp->getOwner()->removeFromParent();
		}
		m_tmpMonster.clear();
	}


	Size visibleSize = Director::getInstance()->getVisibleSize();

	bool hitMonster = false;			//�ӵ��Ƿ��Ѿ����й���

	//bullets

	for (auto bullet : m_bullets)
	{
		hitMonster = false;
		auto owner = bullet->getOwner();
		Point realPos = Point(bullet->getSpeedX() + owner->getPositionX(),    //�ӵ����ڵ���������ٶ�
			bullet->getSpeedY() + owner->getPositionY());
		for (auto monster : m_monsters)
		{
			auto distance = realPos.getDistance(monster->getOwner()->getPosition());
			if (distance < monster->getOwner()->getContentSize().width / 2) 
			{
				//����ӵ����й���   
				//�����Ѫ   
				//hitMonsterΪtrue
				//�������� �Ƴ�����
				auto comLife = dynamic_cast<ComLife*>(monster->getOwner()->getComponent("ComLife"));
				bool isDead = comLife->attacked(bullet->getFireDamage());
				hitMonster = true;
				createBoom(monster->getOwner()->getPositionX(), monster->getOwner()->getPositionY());
				if (isDead)
				{
					monster->getOwner()->removeFromParent();
					m_monsters.remove(monster);
					break;
				}
			}
		}
		//����ӵ����й���  �����ӵ��ɳ���Ļ  �Ƴ��ӵ�
		if (hitMonster || visibleSize.width < realPos.x || visibleSize.height <realPos.y || 0 > realPos.x || 0>realPos.y)
		{
			owner->removeFromParent();
			m_bullets.remove(bullet);
			break;
		}
		else
		{
			owner->setPosition(realPos);
		}
	}

	//tower
	for (auto tower : m_towers)
	{
		auto owner = tower->getOwner();
		if (tower->getIsFire())
		{
			continue;
		}
		else
		{
			int fireRange = tower->getRange();
			Point towerPos = tower->getOwner()->getPosition();
			for (auto monster : m_monsters)
			{
				if (towerPos.getDistance(monster->getOwner()->getPosition()) <= fireRange)
				{
					Sprite* bullet = Sprite::createWithSpriteFrameName(PRocket1_IMG);
					bullet->setPosition(owner->getPosition());
					auto comBullet = ComBullet::create(bullet_damage, bullet_speed);
					bullet->addComponent(comBullet);
					m_bullets.push_back(comBullet);

					float angle = comBullet->setSpeedXY(owner->getPosition(), monster->getOwner()->getPosition());

					owner->getParent()->addChild(bullet, 2);
					tower->setIsFire(true);
					runAction(Sequence::create(DelayTime::create(tower->getRelodTime()),
						CallFunc::create([=]{
						tower->setIsFire(false);
					}), nullptr));

					bullet->setRotation(angle);				//�ӵ���ת��׼����
					owner->setRotation(angle);				//��������ת��׼����
					break;
				}
			}
		}
	}
}
		
void FireManager::endMoveBullet()
{
	unschedule(schedule_selector(FireManager::moveBullet));
}

void FireManager::createBoom(int x, int y){
	Vector<SpriteFrame*>allFrame;
	for (int a = 0; a < 5; a++)
	{
		SpriteFrame*sf = SpriteFrame::create("GameMain/boom.png", Rect(0, 98 * a, 126, 98));
		allFrame.pushBack(sf);
	}
	Animation*ani = Animation::createWithSpriteFrames(allFrame, 0.05f);
	auto sp = Sprite::create();
	Action *act = Sequence::create(
		Animate::create(ani),
		CallFuncN::create(sp, callfuncN_selector(FireManager::endBoom)), nullptr);
	
	sp->runAction(act);
	sp->setPosition(x, y);
	addChild(sp,1);
	SoundsControl::setSound(SoundsControl::SoundState::Bomb);
}
void FireManager::endBoom(Node*node){
	node->removeFromParentAndCleanup(true);
}

