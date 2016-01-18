/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "myscene.h"

MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();

	//spawn spaceship
	s = new Spaceship;
	s->position.x = 500;
	s->position.y = 500;
	addChild(s);
	timer = 0;
}


MyScene::~MyScene()
{

}

void MyScene::update(float deltaTime)
{
	timer -= deltaTime;
	if (input()->getKey(GLFW_KEY_SPACE)) {
		if (timer <= 0) {
			Bullet* b = new Bullet();
			addChild(b);
			bullets.push_back(b);
			b->position = s->position;
			b->polar.angle = s->polar.angle;
			timer = 1;
		}
	}

	if (input()->getKey(GLFW_KEY_UP)) {
		s->velocity += s->polar.cartesian() * 0.4 * deltaTime; // thrust
	}
	if (input()->getKey(GLFW_KEY_RIGHT)) {
		s->polar.angle += s->rotspeed * deltaTime; // rotate right
	}
	if (input()->getKey(GLFW_KEY_LEFT)) {
		s->polar.angle -= s->rotspeed * deltaTime; // rotate left

	}

	s->rotation = s->polar.angle;
	s->position += s->velocity * deltaTime;

	if (s->position.x < 0) { s->position.x = SWIDTH; }
	if (s->position.x > SWIDTH) { s->position.x = 0; }
	if (s->position.y < 0) { s->position.y = SHEIGHT; }
	if (s->position.y > SHEIGHT) { s->position.y = 0; }

}
