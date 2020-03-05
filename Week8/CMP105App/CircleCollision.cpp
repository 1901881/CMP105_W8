#include "CircleCollision.h"

CircleCollision::CircleCollision()
{
}

CircleCollision::~CircleCollision()
{
}

void CircleCollision::update(float dt)
{
	move(velocity * dt);

	if (getPosition().x < 0) {
		setPosition(0, getPosition().y);
		velocity.x = -velocity.x;
	}
	if (getPosition().x < 750) {
		setPosition(750, getPosition().y);
		velocity.x = -velocity.x;
	}
}

void CircleCollision::collisionResponse(GameObject* collider)
{
	velocity.x = -velocity.x;
}


