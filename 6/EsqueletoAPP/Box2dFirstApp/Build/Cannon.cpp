// Cannon.cpp

#include "Cannon.h"
#include "CannonBall.h"
#include "Game.h" // Asumiendo que hay una clase Game para agregar la bola al juego
#include <cstdlib> // Para la función rand()
#include <ctime> // Para inicializar la semilla del generador de números aleatorios

Cannon::Cannon(sf::Vector2f startPosition) : position(startPosition), isLoaded(true) {
    // Inicializar la semilla del generador de números aleatorios
    srand(time(nullptr));
}

void Cannon::shoot() {
    if (isLoaded) {
        // Generar un ángulo aleatorio entre 30 y 60 grados
        float angleDegrees = rand() % 31 + 30; // Rango entre 30 y 60 grados

        // Convertir el ángulo de grados a radianes
        float angleRadians = angleDegrees * (3.14159f / 180.0f);

        // Calcular las componentes x e y de la velocidad inicial utilizando trigonometría
        float speed = 50.0f; // Velocidad inicial fija (puedes ajustarla según sea necesario)
        float initialVelocityX = std::cos(angleRadians) * speed;
        float initialVelocityY = std::sin(angleRadians) * speed;

        // Crear el objeto CannonBall con la posición actual del cañón y la velocidad inicial calculada
        CannonBall ball(position, sf::Vector2f(initialVelocityX, initialVelocityY));

        // Agregar el objeto al juego:
        Game::getInstance().addCannonBall(ball);

        isLoaded = false; // El cañón se descarga después de disparar
    }
}
