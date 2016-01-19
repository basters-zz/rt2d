#include "astroid.h"
Astroid::Astroid()
{
	this->scale.x = 0.35;
	this->scale.y = 0.35;
	this->addSprite("assets/astroid.tga");
	Vector2 velocityAstroid = Vector2((rand() % 100) - 90, (rand() % 100) - 90);
	Vector2 speedAstroid = Vector2((rand() % 100) - 99, (rand() % 100) - 99);
	Polar polarAstroid = Polar(((2) % 360) * DEG_TO_RAD, 900.0f);

}

Astroid::~Astroid()
{

}

void Astroid::update(float deltaTime)
{
	
	bool stop = false;
	velocityAstroid += polarAstroid.cartesian() * deltaTime * 10; // thrust
	this->polarAstroid.angle = this->rotation;
	this->position += this->velocityAstroid * deltaTime * 10;
	velocityAstroid.limit(50);


	
	if (this->position.x < -100) { this->position.x = 2020; }
	if (this->position.x > 2020) { this->position.x = -100; }
	if (this->position.y < -100) { this->position.y = 1180; }
	if (this->position.y > 1180) { this->position.y = -100; }
	




}

