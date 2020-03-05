#pragma once
#include "Framework/GameObject.h"
class AABB : public GameObject
{
public:

	AABB();
	~AABB();

	void update(float dt);
	void collisionResponse(GameObject* collider);
};

