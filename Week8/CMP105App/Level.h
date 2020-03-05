#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "CircleCollision.h"
#include "Framework/Collision.h"
#include "AABB.h"
#include <string>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	CircleCollision ball1;
	CircleCollision ball2;
	sf::Texture textureBall1;
	sf::Texture textureBall2;

	AABB square1;
	AABB square2;
};