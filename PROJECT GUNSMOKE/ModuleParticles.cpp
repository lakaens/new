#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;

	bulletu.anim.PushBack({ 255, 135, 2, 5 });
	bulletu.anim.PushBack({ 255, 135, 2, 5 });
	bulletu.anim.loop = false;
	bulletu.anim.speed = 0.3f;
	bulletu.life = 400;
	bulletu.speed.y = -4;

	bulletr.anim.PushBack({ 302, 136, 4, 4 });
	bulletr.anim.PushBack({ 325, 136, 5, 4 });
	bulletr.anim.loop = false;
	bulletr.anim.speed = 0.3f;
	bulletr.life = 400;
	bulletr.speed.y = -3;
	bulletr.speed.x = +2;

	bulletl.anim.PushBack({ 283, 144, 5, 4 });
	bulletl.anim.PushBack({ 292, 144, 4, 4 });
	bulletl.anim.loop = false;
	bulletl.anim.speed = 0.3f;
	bulletl.life = 400;
	bulletl.speed.y = -3;
	bulletl.speed.x = -2;

	explosion.anim.PushBack({ 177,23,4,4 });
	explosion.anim.PushBack({ 208,21,8,9 });
	explosion.anim.PushBack({ 238,18,17,16 });
	explosion.anim.loop = true;
	explosion.anim.speed = 0.3f;

	deadGunMen.anim.PushBack({ 511,11,26,25 });
	deadGunMen.anim.PushBack({ 480,27,28,27 });
	deadGunMen.anim.PushBack({ 509,40,30,20 });
	deadGunMen.anim.PushBack({ 507,62,30,22 });
	deadGunMen.anim.PushBack({ 553,26,5,5 });
	deadGunMen.anim.PushBack({ 507,62,30,22 });
	deadGunMen.anim.PushBack({ 553,26,5,5 });
	deadGunMen.anim.PushBack({ 507,62,30,22 });
	deadGunMen.anim.PushBack({ 553,26,5,5 });
	deadGunMen.anim.loop = false;
	deadGunMen.anim.speed = 0.1f;

	deadWindowSniperRight.anim.PushBack({ 58,176,18,14 });
	deadWindowSniperRight.anim.PushBack({ 98,176,17,15 });
	deadWindowSniperRight.anim.PushBack({ 138,178,14,15 });
	deadWindowSniperRight.anim.PushBack({ 178,179,18,14 });
	deadWindowSniperRight.anim.PushBack({ 553,26,5,5 });
	deadWindowSniperRight.anim.PushBack({ 455,555,18,14 });
	deadWindowSniperRight.anim.PushBack({ 553,26,5,5 });
	deadWindowSniperRight.anim.PushBack({ 455,555,18,14 });
	deadWindowSniperRight.anim.PushBack({ 553,26,5,5 });
	deadWindowSniperRight.anim.loop = false;
	deadWindowSniperRight.anim.speed = 0.1f;

	deadBomber.anim.PushBack({ 215,160,32,32,});
	deadBomber.anim.PushBack({ 255,160,31,30 });
	deadBomber.anim.PushBack({ 295,160,31,29 });
	deadBomber.anim.PushBack({ 334,172,34,21 });
	deadBomber.anim.PushBack({ 553,26,5,5 });
	deadBomber.anim.PushBack({ 334,172,34,21 });
	deadBomber.anim.PushBack({ 553,26,5,5 });
	deadBomber.anim.PushBack({ 334,172,34,21 });
	deadBomber.anim.PushBack({ 553,26,5,5 });
	deadBomber.anim.loop = false;
	deadBomber.anim.speed = 0.1f;

	deadWindowSniperLeft.anim.PushBack({58,225,18,14});
	deadWindowSniperLeft.anim.PushBack({ 102,224,14,15 });
	deadWindowSniperLeft.anim.PushBack({ 139,222,17,15 });
	deadWindowSniperLeft.anim.PushBack({ 178,222,18,14 });	
	deadWindowSniperLeft.anim.PushBack({ 553,26,5,5 });
	deadWindowSniperLeft.anim.PushBack({ 178,222,18,14 });
	deadWindowSniperLeft.anim.PushBack({ 553,26,5,5 });
	deadWindowSniperLeft.anim.PushBack({ 178,222,18,14 });
	deadWindowSniperLeft.anim.PushBack({ 553,26,5,5 });
	deadWindowSniperLeft.anim.loop = false;
	deadWindowSniperLeft.anim.speed = 0.1f;

	deadBackStabber.anim.PushBack({417,161,23,26});
	deadBackStabber.anim.PushBack({458,161,22,25});
	deadBackStabber.anim.PushBack({491,167,25,24});
	deadBackStabber.anim.PushBack({530,173,34,16});
	deadBackStabber.anim.PushBack({ 553,26,5,5 });
	deadBackStabber.anim.PushBack({ 530,173,34,16 });
	deadBackStabber.anim.PushBack({ 553,26,5,5 });
	deadBackStabber.anim.PushBack({ 530,173,34,16 });
	deadBackStabber.anim.PushBack({ 553,26,5,5 });
	deadBackStabber.anim.loop = false;
	deadBackStabber.anim.speed = 0.1f;
	
	enemysimplebullet.anim.PushBack({ 350,16,10,10});
	enemysimplebullet.anim.loop = false;
	enemysimplebullet.anim.speed -= 1;
	enemysimplebullet.speed.y = 1;

	enemysimplebulletdead.anim.PushBack({372,15,6,6});
	enemysimplebulletdead.anim.PushBack({395,14,9,8});
	enemysimplebulletdead.anim.PushBack({418,13,12,10});
	enemysimplebulletdead.anim.speed = 0.1f;
	enemysimplebulletdead.anim.loop = false;

	deadBarrel.anim.PushBack({ 81,59,15,15 });
	deadBarrel.anim.PushBack({ 104,59,15,15 });
	deadBarrel.anim.PushBack({ 128,60,16,14 });
	deadBarrel.anim.PushBack({ 152,61,16,13 });
	deadBarrel.anim.PushBack({ 176,60,16,14 });
	deadBarrel.anim.PushBack({ 202,63,14,11 });
	deadBarrel.anim.PushBack({ 81,59,15,15 });
	deadBarrel.anim.PushBack({ 104,59,15,15 });
	deadBarrel.anim.PushBack({ 128,60,16,14 });
	deadBarrel.anim.PushBack({ 152,61,16,13 });
	deadBarrel.anim.PushBack({ 176,60,16,14 });
	deadBarrel.anim.PushBack({ 202,63,14,11 });
	deadBarrel.anim.loop = false;
	deadBarrel.anim.speed = 0.1f;
}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("Gunsmoke/particles.png");

	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(graphics);

	// Unload fx

	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if(active[i] != nullptr)
		{
			delete active[i];
			active[i] = nullptr;
		}
	}

	return true;
}

// Update: draw background
update_status ModuleParticles::Update()
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* p = active[i];

		if(p == nullptr)
			continue;

		if(p->Update() == false)
		{
			delete p;
			active[i] = nullptr;
		}
		else if(SDL_GetTicks() >= p->born)
		{
			App->render->Blit(graphics, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
			if(p->fx_played == false)
			{
				p->fx_played = true;
				// play the audio SFX
			}
		}
	}

	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type, Uint32 delay)
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if(active[i] == nullptr)
		{
			Particle* p = new Particle(particle);
			p->born = SDL_GetTicks() + delay;
			p->position.x = x;
			p->position.y = y;
			if(collider_type != COLLIDER_NONE)
				p->collider = App->collision->AddCollider(p->anim.GetCurrentFrame(), collider_type, this);
			active[i] = p;
			break;
		}
	}
}

void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		// Always destroy particles that collide
		if(active[i] != nullptr && active[i]->collider == c1)
		{
			
			delete active[i];
			active[i] = nullptr;
			break;
		}
	}
}

// -------------------------------------------------------------
// -------------------------------------------------------------

Particle::Particle()
{
	position.SetToZero();
	speed.SetToZero();
}

Particle::Particle(const Particle& p) : 
anim(p.anim), position(p.position), speed(p.speed),
fx(p.fx), born(p.born), life(p.life)
{}

Particle::~Particle()
{
	if(collider != nullptr)
		App->collision->EraseCollider(collider);
}

bool Particle::Update()
{
	bool ret = true;

	if(life > 0)
	{
		if((SDL_GetTicks() - born) > life)
			ret = false;
	}
	else
		if(anim.Finished())
			ret = false;

	position.x += speed.x;
	position.y += speed.y;

	if(collider != nullptr)
		collider->SetPos(position.x, position.y);

	return ret;
}

