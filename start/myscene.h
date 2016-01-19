/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>
#include "spaceship.h"
#include "myentity.h"
#include "bullet.h"
#include "astroid.h"

/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
	/// @brief Constructor
	MyScene();
	/// @brief Destructor
	virtual ~MyScene();
	Spaceship* s;
	std::vector<Bullet*> bullets;
	std::vector<Astroid*> astroids;
	float timer;
	float spawnTimer;
	float randomPosTimer;

	float randomPosx1;
	float randomPosx2;
	float randomPosx3;


	float randomPosy1;
	float randomPosy2;
	float randomPosy3;

	float spaceshipPos;



	float posa;
	float posb;
	float posa2;
	float posb2;
	float distance1;
	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	Bullet* b;
	Astroid* a;
	/// @brief the rotating square in the middle of the screen
	MyEntity* myentity;
	/// @brief a Timer to rotate the color every n seconds
	Timer t;
};

#endif /* SCENE00_H */
