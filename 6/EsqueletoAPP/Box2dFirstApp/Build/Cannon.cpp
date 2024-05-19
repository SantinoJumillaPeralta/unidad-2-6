// Cannon.cpp

#include "Cannon.h"
#include "CannonBall.h"
#include "Game.h" // Asumiendo que hay una clase Game para agregar la bola al juego
#include <cstdlib> // Para la funci�n rand()
#include <ctime> // Para inicializar la semilla del generador de n�meros aleatorios

Cannon::Cannon(sf::Vector2f startPosition) : position(startPosition), isLoaded(true) {
    // Inicializar la semilla del generador de n�meros aleatorios
    srand(time(nullptr));
}

void Cannon::shoot() {
    if (isLoaded) {
        // Generar un �ngulo aleatorio entre 30 y 60 grados
        float angleDegrees = rand() % 31 + 30; // Rango entre 30 y 60 grados

        // Convertir el �ngulo de grados a radianes
        float angleRadians = angleDegrees * (3.14159f / 180.0f);

        // Calcular las componentes x e y de la velocidad inicial utilizando trigonometr�a
        float speed = 50.0f; // Velocidad inicial fija (puedes ajustarla seg�n sea necesario)
        float initialVelocityX = std::cos(angleRadians) * speed;
        float initialVelocityY = std::sin(angleRadians) * speed;

        // Crear el objeto CannonBall con la posici�n actual del ca��n y la velocidad inicial calculada
        CannonBall ball(position, sf::Vector2f(initialVelocityX, initialVelocityY));

        // Agregar el objeto al juego:
        Game::getInstance().addCannonBall(ball);

        isLoaded = false; // El ca��n se descarga despu�s de disparar
    }
}
