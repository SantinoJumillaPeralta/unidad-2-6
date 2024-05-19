// CannonBall.cpp
#include "CannonBall.h"

CannonBall::CannonBall(b2World* world, sf::Vector2f position, sf::Vector2f initialVelocity) : world(world) {
    // Definir cuerpo de Box2D
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(position.x, position.y);
    body = world->CreateBody(&bodyDef);

    // Definir forma
    b2CircleShape circleShape;
    circleShape.m_radius = 1.0f;

    // Definir fixture
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    fixtureDef.restitution = 0.5f;

    body->CreateFixture(&fixtureDef);

    // Inicializar forma de SFML
    shape.setRadius(10);
    shape.setOrigin(10, 10);
    shape.setPosition(position);
    shape.setFillColor(sf::Color::Red);

    // Aplicar velocidad inicial
    body->SetLinearVelocity(b2Vec2(initialVelocity.x, initialVelocity.y));
}

CannonBall::~CannonBall() {
    world->DestroyBody(body);
}

void CannonBall::Draw(sf::RenderWindow* wnd) {
    sf::Vector2f position = sf::Vector2f(body->GetPosition().x, body->GetPosition().y);
    shape.setPosition(position);
    wnd->draw(shape);
}

void CannonBall::Update() {
    // No se necesita actualización específica para una bola de cañón,
    // ya que su movimiento es manejado por el mundo físico de Box2D.
}
