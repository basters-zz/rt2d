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
	spawnTimer = 1;
	randomPosTimer = 3;

	randomPosx1 = -25;
	randomPosx2 = 900;
	randomPosx3 = 1945;
	randomPosy1 = -25;
	randomPosy2 = 500;
	randomPosy3 = 2005;

	posa = 0;
	posb = 0;
	posa2 = 0;
	posb2 = 0;
	distance1 = 0;

	spaceshipPos = NULL;
}


MyScene::~MyScene()
{

}

void MyScene::update(float deltaTime)
{
	timer -= deltaTime;
	if (input()->getKey(GLFW_KEY_SPACE)) {
		if (timer <= 0) {
			b = new Bullet();
			addChild(b);
			bullets.push_back(b);
			b->position = s->position;
			b->polar.angle = s->polar.angle;
			timer = 0.6;
		}
	}
	randomPosTimer -= deltaTime;
	spawnTimer -= deltaTime;

	spaceshipPos = (float)atan2(s->position.y, s->position.x);

	if (spawnTimer <= 0) {


		a = new Astroid();
		a->rotation = spaceshipPos;
		addChild(a);
		astroids.push_back(a);
		

		if (randomPosTimer <= 0) {
			randomPosTimer = 3;

		}
		if (randomPosTimer <= 0) {
			a->position.x = randomPosx1;
			a->position.y = randomPosy2;
		}
		if (randomPosTimer == 1) {
			a->position.x = randomPosx2;
			a->position.y = randomPosy1;
		}
		if (randomPosTimer == 2) {
			a->position.x = randomPosx3;
			a->position.y = randomPosy2;

		}
		if (randomPosTimer == 3) {
			a->position.x = randomPosx2;
			a->position.y = randomPosy3;
		}

		spawnTimer = 3;

	}

	


	for (int i = 1; i < bullets.size(); i++) {
		for (int j = 1; j < astroids.size(); j++) {
			posa = astroids[j]->position.x - bullets[i]->position.x;
			posb = astroids[j]->position.y - bullets[i]->position.y;
			posa2 = posa * posa;
			posb2 = posb * posb;
			distance1 = sqrt(posa2 + posb2);

			if (distance1 <= 75) {
				std::cout << "Hit" << std::endl;

			}

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
