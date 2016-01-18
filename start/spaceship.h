
#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <rt2d/entity.h>
#include <vector>
#include "input.h"
#include <deque>
#include <rt2d/timer.h>



class Spaceship: public Entity
{
public:
	Spaceship();
	virtual ~Spaceship();
	float rotspeed = 3.14f;
	
	Vector2 velocity = Vector2((rand() % 100) - 50, (rand() % 100) - 50);
	Vector2 speed = Vector2((rand() % 100) - 50, (rand() % 100) - 50);
	Polar polar = Polar((rand() % 360) * DEG_TO_RAD, 400.0f);
	virtual void update(float deltaTime);


};
#endif // !SPACESHIP_H


