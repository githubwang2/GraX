#include "CreateParticle.h"
USING_NS_CC;

CreateParticle* CreateParticle::create(int id)
{
	CreateParticle*ret = new CreateParticle();
	if (ret != nullptr && ret->init(id))
	{
		ret->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(ret);
	}
	return ret;
}

bool CreateParticle::init(int id)
{
	if (!Layer::init())
	{
		return false;
	}
	visibleSize = Director::getInstance()->getVisibleSize();
	switch (id)
	{
	case 1:snow(); break; 
	case 2:rain(); break;
	case 3:clear(); break;
	case 4:setting(); break;
	default:
		break;
	}
	return true;
}

void CreateParticle::snow()
{
	ParticleSnow *snow = ParticleSnow::create();
	snow->setPosition(Point(visibleSize.width / 2, visibleSize.height));
	snow->setTexture(TextureCache::sharedTextureCache()->addImage("fire.png"));
	addChild(snow);
}

void CreateParticle::rain()
{
	ParticleSystem* particleSystem = ParticleRain::create();
	particleSystem->setTexture(TextureCache::sharedTextureCache()->addImage("fire.png"));
	addChild(particleSystem);
}

void CreateParticle::clear()
{
	ParticleSystemQuad*particle = ParticleSystemQuad::create("slowLight.plist");
	addChild(particle);
}

void CreateParticle::setting()
{
	ParticleSystemQuad*particle2 = ParticleSystemQuad::create("particle.plist");
	addChild(particle2);

}
