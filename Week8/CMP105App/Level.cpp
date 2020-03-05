#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	textureBall1.loadFromFile("gfx/Beach_Ball.png");
	ball1.setTexture(&textureBall1);
	ball1.setSize(sf::Vector2f(50, 50));
	ball1.setPosition(0, 200);
	ball1.setVelocity(50, 0);

	textureBall2.loadFromFile("gfx/Beach_Ball.png");
	ball2.setTexture(&textureBall2);
	ball2.setSize(sf::Vector2f(50, 50));
	ball2.setPosition(100, 200);
	ball2.setVelocity(50, 0);

	square1.setSize(sf::Vector2f(50, 50));
	square1.setCollisionBox(sf::FloatRect(0, 0, 50, 50));
	square1.setPosition(0, 200);
	square1.setVelocity(50, 0);
	square1.setFillColor(sf::Color::Blue);

	square2.setSize(sf::Vector2f(50, 50));
	square2.setCollisionBox(sf::FloatRect(0, 0, 50, 50));
	square2.setPosition(750, 200);
	square2.setVelocity(-50, 0);
	square2.setFillColor(sf::Color::Blue);

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	ball1.update(dt);
	ball2.update(dt);
	if (Collision::checkBoundingCircle(&ball1, &ball2)) {
		ball1.collisionResponse(NULL);
		ball2.collisionResponse(NULL);
	}

	square1.update(dt);
	square2.update(dt);
	if (Collision::checkBoundingCircle(&ball1, &ball2)) {
		square1.collisionResponse(NULL);
		square2.collisionResponse(NULL);
	}
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ball1);
	window->draw(ball2);

	window->draw(square1);
	window->draw(square2);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}