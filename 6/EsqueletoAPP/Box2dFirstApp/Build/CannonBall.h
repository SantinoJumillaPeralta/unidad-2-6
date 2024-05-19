// CannonBall.h
#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "CannonBall.h"

class CannonBall {
private:
    b2Body* body;
    sf::CircleShape shape;
    b2World* world;

public:
    CannonBall(b2World* world, sf::Vector2f position, sf::Vector2f initialVelocity);
    ~CannonBall();

    void Draw(sf::RenderWindow* wnd);
    void Update();
};
