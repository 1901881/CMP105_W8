#pragma once
#include "Framework/GameObject.h"
#include "Framework/Collision.h"
class CircleCollision : public GameObject
{
public:
	CircleCollision();
	~CircleCollision();
	void update(float dt);
	void collisionResponse(GameObject* collider);
};

