// Game.h
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "SFMLRenderer.h"
#include "Box2DHelper.h"
#include "CannonBall.h"

class Game {
private:
    int alto;
    int ancho;
    sf::RenderWindow* wnd;
    sf::Color clearColor;
    b2World* phyWorld;
    SFMLRenderer* debugRender;
    float frameTime;
    int fps;
    b2Body* controlBody;
    std::vector<CannonBall> cannonBalls; // Vector para almacenar los objetos disparados

public:
    Game(int ancho, int alto, std::string titulo);
    ~Game();

    void Loop();
    void CheckCollitions();
    void CreateEnemy(int x, int y);
    void InitPhysics();
    void DrawGame();
    void UpdatePhysics();
    void DoEvents();
    void SetZoom();
    void addCannonBall(sf::Vector2f startPos, sf::Vector2f initialVelocity);
};
