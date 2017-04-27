#include "FireManager.h"

void FireManager::towers()
{
	FanAttackType();
	ArrowAttackType();
	RocketAttackType();
	BottleAttackType();
}

void FireManager::bullets()
{
	FanBulletManager();
	ArrowBulletManager();
	RocketBulletManager();
	BottleBulletManager();
}

void FireManager::magic()
{
	anchorAttackType();
	anchorBulletManager();
	FBottleAttackType();
	FBottleBulletManager();
}

void FireManager::FanAttackType()
{
	for (auto tower : m_fanTowers)
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
					Sprite* bullet = Sprite::createWithSpriteFrameName(PFan1_IMG);
					bullet->setPosition(owner->getPosition());
					auto comBullet = ComBullet::create(tower->getBulletDamage(), tower->getBulletSpeed());
					bullet->addComponent(comBullet);
					m_fanBullets.push_back(comBullet);

					float angle = comBullet->setSpeedXY(owner->getPosition(), monster->getOwner()->getPosition());

					owner->getParent()->addChild(bullet, 2);
					tower->setIsFire(true);
					runAction(Sequence::create(DelayTime::create(tower->getRelodTime()),
						CallFunc::create([=]{
						tower->setIsFire(false);
					}), nullptr));

					bullet->runAction(RepeatForever::create(RotateBy::create(0.6, 360)));
					//owner->setRotation(angle);//防御塔旋转对准怪物
					break;
				}
			}
		}
	}
}
void FireManager::FanBulletManager()
{
	for (auto bullet : m_fanBullets)
	{
		hitMonster = false;
		auto owner = bullet->getOwner();

		Point realPos  = Point(bullet->getSpeedX() + owner->getPositionX(),
			bullet->getSpeedY() + owner->getPositionY());
  
		for (auto monster : m_monsters)
		{
			auto distance = realPos.getDistance(monster->getOwner()->getPosition());
			if (distance < monster->getOwner()->getContentSize().width / 2)
			{
				auto comLife = dynamic_cast<ComLife*>(monster->getOwner()->getComponent("ComLife"));
				bool isDead = comLife->attacked(bullet->getFireDamage());
				hitMonster = true;
				createFunBoom(monster->getOwner()->getPositionX(), monster->getOwner()->getPositionY());
				if (isDead)
				{
					monster->getOwner()->removeFromParent();
					m_monsters.remove(monster);
					break;
				}
			}
		}

		Point increasePos = Point(bullet->getSpeedX(), bullet->getSpeedY());
		if (increasePos.getLength()>300)
		{
			owner->removeFromParent();
			m_fanBullets.remove(bullet);
			break;
		}
		else
		{
			owner->setPosition(realPos);
		}
	}
}

void FireManager::ArrowAttackType()
{
	for (auto tower : m_arrowTowers)
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
					Sprite* bullet = Sprite::createWithSpriteFrameName(PArrow_IMG);
					bullet->setPosition(owner->getPosition());
					auto comBullet = ComBullet::create(tower->getBulletDamage(), tower->getBulletSpeed());
					bullet->addComponent(comBullet);
					m_arrowBullets.push_back(comBullet);

					float angle = comBullet->setSpeedXY(owner->getPosition(), monster->getOwner()->getPosition());

					owner->getParent()->addChild(bullet, 2);
					tower->setIsFire(true);
					runAction(Sequence::create(DelayTime::create(tower->getRelodTime()),
						CallFunc::create([=]{
						tower->setIsFire(false);
					}), nullptr));

					bullet->setRotation(angle);				//子弹旋转对准怪物
					owner->setRotation(angle);				//防御塔旋转对准怪物
					break;
				}
			}
		}
	}
}
void FireManager::ArrowBulletManager()
{
	for (auto bullet : m_arrowBullets)
	{
		hitMonster = false;
		auto owner = bullet->getOwner();
		Point realPos = Point(bullet->getSpeedX() + owner->getPositionX(),
			bullet->getSpeedY() + owner->getPositionY());
		for (auto monster : m_monsters)
		{
			auto distance = realPos.getDistance(monster->getOwner()->getPosition());
			if (distance < monster->getOwner()->getContentSize().width / 2)
			{
				auto comLife = dynamic_cast<ComLife*>(monster->getOwner()->getComponent("ComLife"));
				bool isDead = comLife->attacked(bullet->getFireDamage());
				hitMonster = true;
				//createBoom(monster->getOwner()->getPositionX(), monster->getOwner()->getPositionY());
				if (isDead)
				{
					monster->getOwner()->removeFromParent();
					m_monsters.remove(monster);
					break;
				}
			}
		}
		if (hitMonster || visibleSize.width < realPos.x || visibleSize.height <realPos.y || 0 > realPos.x || 0>realPos.y)
		{
			owner->removeFromParent();
			m_arrowBullets.remove(bullet);
			break;
		}
		else
		{
			owner->setPosition(realPos);
		}
	}
}

void FireManager::RocketAttackType()
{
	for (auto tower : m_rocketTower)
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
					auto comBullet = ComBullet::create(tower->getBulletDamage(), tower->getBulletSpeed());
					bullet->addComponent(comBullet);
					m_rocketBullets.push_back(comBullet);

					float angle = comBullet->setSpeedXY(owner->getPosition(), monster->getOwner()->getPosition());

					owner->getParent()->addChild(bullet, 2);
					tower->setIsFire(true);
					runAction(Sequence::create(DelayTime::create(tower->getRelodTime()),
						CallFunc::create([=]{
						tower->setIsFire(false);
					}), nullptr));

					bullet->setRotation(angle);				//子弹旋转对准怪物
					owner->setRotation(angle);				//防御塔旋转对准怪物
					break;

				}
			}
		}
	}
}
void FireManager::RocketBulletManager()
{
	for (auto bullet : m_rocketBullets)
	{
		hitMonster = false;
		auto owner = bullet->getOwner();
		Point realPos = Point(bullet->getSpeedX() + owner->getPositionX(),    //子弹现在的坐标加上速度
			bullet->getSpeedY() + owner->getPositionY());
		for (auto monster : m_monsters)
		{
			auto distance = realPos.getDistance(monster->getOwner()->getPosition());
			if (distance < monster->getOwner()->getContentSize().width / 2)
			{
				//如果子弹命中怪物   
				//怪物掉血   
				//hitMonster为true
				//怪物死亡 移除怪物
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
		//如果子弹命中怪物  或者子弹飞出屏幕  移除子弹
		if (hitMonster || visibleSize.width < realPos.x || visibleSize.height <realPos.y || 0 > realPos.x || 0>realPos.y)
		{
			owner->removeFromParent();
			m_rocketBullets.remove(bullet);
			break;
		}
		else
		{
			owner->setPosition(realPos);
		}
	}
}

void FireManager::BottleAttackType()
{
	for (auto tower : m_bottleTowers)
	{
		Sprite* bullet = Sprite::createWithSpriteFrameName(PBottle1_IMG);
		auto owner = tower->getOwner();
		if (tower->getIsFire())
		{
			bullet->setVisible(false);
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
					
					//bullet->setPosition(owner->getPosition());
					auto comBullet = ComBullet::create(tower->getBulletDamage(), tower->getBulletSpeed());
					bullet->addComponent(comBullet);
					m_bottleBullets.push_back(comBullet);

					float angle = comBullet->setSpeedXY(owner->getPosition(), monster->getOwner()->getPosition());
					CCLOG("angle%f", angle);
					owner->getParent()->addChild(bullet, 2);
					tower->setIsFire(true);
					runAction(Sequence::create(DelayTime::create(tower->getRelodTime()),
						CallFunc::create([=]{
						tower->setIsFire(false);
					}), nullptr));
					bullet->setAnchorPoint(Point::ZERO);
					bullet->setPosition(owner->getPosition() + Point(comBullet->getSpeedX(), comBullet->getSpeedY()));
					bullet->setRotation(angle);				//子弹旋转对准怪物
					owner->setRotation(angle);				//防御塔旋转对准怪物
					break;
				}
			}
		}
	}
}
void FireManager::BottleBulletManager()
{
	for (auto bullet : m_bottleBullets)
	{
		hitMonster = false;
		auto owner = bullet->getOwner();
		Point realPos = Point(/*bullet->getSpeedX()*/ + owner->getPositionX(),
			/*bullet->getSpeedY() */+ owner->getPositionY());
		for (auto monster : m_monsters)
		{
			auto distance = realPos.getDistance(monster->getOwner()->getPosition());
			if (distance < monster->getOwner()->getContentSize().width / 2)
			{
				auto comLife = dynamic_cast<ComLife*>(monster->getOwner()->getComponent("ComLife"));
				bool isDead = comLife->attacked(bullet->getFireDamage()/5);//因为火频率太高。。
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
		if (hitMonster)
		{
			owner->removeFromParent();
			m_bottleBullets.remove(bullet);
			break;
		}
		else
		{
			owner->setPosition(realPos);
		}
	}
}

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

	 visibleSize = Director::getInstance()->getVisibleSize();
	 hitMonster = false;			//子弹是否已经打中怪物

	//bullets
	 bullets();
	//tower
	 towers();
	 //magic
	 magic();
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

void FireManager::createFunBoom(int x, int y)
{
	Vector<SpriteFrame*>allFrame;
	Animation * animation = Animation::create();
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(PFan01_IMG));
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(PFan02_IMG));
	animation->setDelayPerUnit(0.1f);
	animation->setRestoreOriginalFrame(true);
	auto sp = Sprite::create();
	Action *act = Sequence::create(
		Animate::create(animation),
		CallFuncN::create(sp, callfuncN_selector(FireManager::endBoom)), nullptr);

	sp->runAction(act);
	sp->setPosition(x, y);
	addChild(sp, 1);
	SoundsControl::setSound(SoundsControl::SoundState::Bomb);
}
void FireManager::endFunBoom(Node*node)
{
	node->removeFromParentAndCleanup(true);
}

//createFire(monster->getOwner()->getPositionX(), monster->getOwner()->getPositionY() - 20);
void FireManager::createFire(int x, int y)
{
	Vector<SpriteFrame*>allFrame;
	Animation * animation = Animation::create();
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PSun01.png"));
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PSun02.png"));
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PSun03.png"));
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PSun04.png"));
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PSun05.png"));
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PSun06.png"));
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PSun07.png"));
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PSun08.png"));
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PSun09.png"));

	animation->setDelayPerUnit(0.1f);
	animation->setRestoreOriginalFrame(true);
	auto sp = Sprite::create();
	Action *act = Sequence::create(
		Repeat::create(Animate::create(animation),1),
		CallFuncN::create(sp, callfuncN_selector(FireManager::endFire)), nullptr);

	sp->runAction(act);
	sp->setPosition(x, y);
	addChild(sp, 1);
}
void FireManager::endFire(Node*node)
{
	node->removeFromParentAndCleanup(true);
}

void FireManager::createIce(int x, int y)
{
	Vector<SpriteFrame*>allFrame;
	Animation * animation = Animation::create();
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PSun01.png"));
	/*animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PSun02.png"));
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PSun03.png"));
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PSun04.png"));
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PSun05.png"));
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PSun06.png"));
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PSun07.png"));
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PSun08.png"));
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PSun09.png"));*/

	animation->setDelayPerUnit(0.1f);
	animation->setRestoreOriginalFrame(true);
	auto sp = Sprite::create();
	Action *act = Sequence::create(
		Repeat::create(Animate::create(animation), 1),
		CallFuncN::create(sp, callfuncN_selector(FireManager::endFire)), nullptr);

	sp->runAction(act);
	sp->setPosition(x, y);
	addChild(sp, 1);
}
void FireManager::endIce(Node*node)
{
	node->removeFromParentAndCleanup(true);
}

void FireManager::createStars(int x, int y)
{
	Vector<SpriteFrame*>allFrame;
	Animation * animation = Animation::create();
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PAnchor01.png"));
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PAnchor02.png"));
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PAnchor03.png"));
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PAnchor04.png"));
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PAnchor05.png"));
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PAnchor06.png"));

	animation->setDelayPerUnit(0.1f);
	animation->setRestoreOriginalFrame(true);
	auto sp = Sprite::create();
	Action *act = Sequence::create(
		Repeat::create(Animate::create(animation), 1),
		CallFuncN::create(sp, callfuncN_selector(FireManager::endFire)), nullptr);

	sp->runAction(act);
	sp->setPosition(x, y);
	addChild(sp, 1);
}
void FireManager::endStars(Node*node)
{
	node->removeFromParentAndCleanup(true);
}

void FireManager::anchorAttackType()
{
	for (auto tower : m_anchorTowers)
	{
		auto owner = tower->getOwner();
		if (tower->getIsFire())
		{
			continue;
		}
		else
		{
			Point towerPos = tower->getOwner()->getPosition();
			//int fireRange = 5;//改
			//Action *act = Sequence::create(DelayTime::create(5),
			//	CallFunc::create(CC_CALLBACK_0(FireManager::anchorBulletManager, this)), nullptr);
			//runAction(act);
			for (auto monster : m_monsters)
			{		
				auto anchorFalling = Sprite::createWithSpriteFrameName("pAnchor311.png");
				anchorFalling->setScale(2.0);
				anchorFalling->setPosition(owner->getPositionX(), 900);
				auto comBullet = ComBullet::create(5, 5);//改  下落锚点的攻击
				anchorFalling->addComponent(comBullet);
				m_anchorBullets.push_back(comBullet);

				owner->getParent()->addChild(anchorFalling, 2);
				tower->setIsFire(true);
				runAction(Sequence::create(DelayTime::create(5),
					CallFunc::create([=]{tower->setIsFire(false);
				}), nullptr));

				break;
			}
		}
	}
}
void FireManager::anchorBulletManager()
{
	for (auto bullet : m_anchorBullets)
	{
		hitMonster = false;
		auto owner = bullet->getOwner();
		Point realPos = Point(owner->getPositionX(), -5 + owner->getPositionY());
		for (auto monster : m_monsters)
		{
			auto distance = realPos.getDistance(monster->getOwner()->getPosition());

			auto monsterSize = monster->getOwner()->getBoundingBox().size;
			Rect monsterRect(monster->getOwner()->getPositionX(), monster->getOwner()->getPositionY(),
				monsterSize.width, monsterSize.height);
			auto bulletSize = bullet->getOwner()->getBoundingBox().size;
			Rect bulletRect(bullet->getOwner()->getPositionX(), bullet->getOwner()->getPositionY(),
				bulletSize.width, bulletSize.height );
			if (monsterRect.intersectsRect(bulletRect))
			{
				auto comLife = dynamic_cast<ComLife*>(monster->getOwner()->getComponent("ComLife"));
			/*	if (hitMonster == false)
				{
					isDead = comLife->attacked(bullet->getFireDamage());
					hitMonster = true;
					runAction(Sequence::create(DelayTime::create(2.0f),
						CallFunc::create([=](){hitMonster = false; }), nullptr));
				}	*/
				bool isDead = comLife->attacked(bullet->getFireDamage());
				if (isDead)
				{
					createStars(monster->getOwner()->getPositionX(), monster->getOwner()->getPositionY());
					monster->getOwner()->removeFromParent();
					m_monsters.remove(monster);
					break;
				}
			}
		}
		if (0 > realPos.y)
		{
			owner->removeFromParent();
			m_anchorBullets.remove(bullet);
			break;
		}
		else
		{
			owner->setPosition(realPos);
		}
	}
}

void FireManager::FBottleAttackType()
{
	for (auto magic : m_FBottleMagic)
	{
		 auto bulletFireBottle = Sprite::createWithSpriteFrameName("PFBottle3.png");
		auto owner = magic->getOwner();
		if (magic->getIsFire())
		{
			//bulletFireBottle->setVisible(false);
			continue;
		}
		else
		{
			int fireRange = magic->getRange();//100;
			Point towerPos = magic->getOwner()->getPosition();
			for (auto monster : m_monsters)
			{
				if (towerPos.getDistance(monster->getOwner()->getPosition()) <= fireRange)
				{ 
					//************
					auto comBullet = ComBullet::create(/*tower->getBulletDamage(), tower->getBulletSpeed()*/1, 60);
					bulletFireBottle->addComponent(comBullet);
					m_FBottleBullets.push_back(comBullet);

					float angle = comBullet->setSpeedXY(owner->getPosition(), monster->getOwner()->getPosition()); 
					owner->getParent()->addChild(bulletFireBottle, 2);
					magic->setIsFire(true);
					runAction(Sequence::create(DelayTime::create(magic->getRelodTime()),
						CallFunc::create([=]{
						magic->setIsFire(false);
					}), nullptr));
					bulletFireBottle->setAnchorPoint(Point::ZERO);
					bulletFireBottle->setPosition(owner->getPosition() + Point(comBullet->getSpeedX(), comBullet->getSpeedY()));
					bulletFireBottle->setRotation(angle);				 
					owner->setRotation(angle); 
					break;
				}
			}
		}
	}
}
void FireManager::FBottleBulletManager()
{
	for (auto bullet : m_FBottleBullets)
	{
		hitMonster = false;
		auto owner = bullet->getOwner();
		Point realPos = Point(/*bullet->getSpeedX()*/ +owner->getPositionX(),
			/*bullet->getSpeedY() */+owner->getPositionY());
		for (auto monster : m_monsters)
		{
			auto distance = realPos.getDistance(monster->getOwner()->getPosition());
			//因为火焰不产生位移  所以距离应为怪物半径+火焰长度 
			if (distance < /*80-monster->getOwner()->getContentSize().width / 2*/monster->getOwner()->getContentSize().width / 2+50)
			{
				auto comLife = dynamic_cast<ComLife*>(monster->getOwner()->getComponent("ComLife"));
				bool isDead = comLife->attacked(bullet->getFireDamage() / 5);//因为火频率太高。。
				hitMonster = true;
				createFire(monster->getOwner()->getPositionX(), monster->getOwner()->getPositionY());

				if (isDead)
				{
					monster->getOwner()->removeFromParent();
					m_monsters.remove(monster);
					break;
				}
			}
		}
		if (hitMonster)
		{
			owner->removeFromParent();
			m_FBottleBullets.remove(bullet);
			break;
		}
		else
		{
			owner->setPosition(realPos);
		}
	}
}

