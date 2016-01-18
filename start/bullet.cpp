#include "bullet.h"

Bullet::Bullet()
{
	this->scale.x = 0.15;
	this->scale.y = 0.15;
	this->addSprite("assets/bullet.tga");
	velocity = Vector2((rand() % 100) - 50, (rand() % 100) - 50);
	speed = Vector2((rand() % 100) - 50, (rand() % 100) - 50);
	polar = Polar((rand() % 360) * DEG_TO_RAD, 400.0f);
}

Bullet::~Bullet()
{
}

void Bullet::update(float deltaTime)
{

	this->position += this->polar.cartesian() * 6 * deltaTime;
	this->rotation = this->polar.angle;
}