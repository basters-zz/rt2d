#ifndef ASTROID_H
#define ASTROID_H

#include <rt2d/entity.h>
#include <vector>
#include <deque>
#include <rt2d/timer.h>


class Astroid : public Entity
{
public:



	Astroid();
	virtual ~Astroid();
	Vector2 velocityAstroid;
	Vector2 speedAstroid;
	Polar polarAstroid;

	virtual void update(float deltaTime);

private:

	Timer t;
	Timer timer;

};








































#endif // !ASTROID_H
