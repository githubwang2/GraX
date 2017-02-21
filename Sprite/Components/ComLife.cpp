#include "Sprite/Components/ComLife.h"

USING_NS_CC;

ComLife::ComLife(int maxLife):m_currentHp(0), m_hpBar(nullptr)
{
	setName("ComLife");
	m_maxLife = maxLife;
	m_currentHp = maxLife;
}

ComLife*ComLife::create(int maxLife){
	ComLife*ret = new ComLife(maxLife);
	if (ret!=nullptr && ret->init())
	{
		ret->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(ret);
	}
	return ret;
}

void ComLife::onEnter(){
	//生成血条
	auto owner = getOwner();
	m_hpBar = ui::LoadingBar::create();
	m_hpBar->loadTexture("GameMain/Life.png");
	m_hpBar->setPercent(100);

	auto LoadBarBk = Sprite::create("GameMain/LifeBk.png");
	auto bar = Node::create();
	bar->addChild(LoadBarBk);
	bar->addChild(m_hpBar);

	Size spriteSize = owner->getContentSize();
	bar->setScale(spriteSize.width / m_hpBar->getContentSize().width);
	bar->setPosition(Point(spriteSize.width / 2, spriteSize.height));
	owner->addChild(bar);
}

bool ComLife::attacked(int damage)
{
	bool isDead = false;
	int after = m_currentHp - damage;
	if (after>0)
	{
		m_currentHp = after;
		m_hpBar->setPercent(m_currentHp / m_maxLife * 100);
	}
	else
	{
		//-------------------------------------------
		/*isDead = true;
		auto playground = dynamic_cast<MainScene*>(getOwner()->getParent());
		playground->changeGold(30);*/
	}
	return isDead;
}