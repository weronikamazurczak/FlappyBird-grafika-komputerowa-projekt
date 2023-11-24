#include "Engine.hpp"

/**
 * @brief Konstruktor obiektu Circle ustawiający promień koła.
 *
 * @param radius Promień koła.
 */
Engine::Circle::Circle(float radius) {
	this->circle.setRadius(radius);
}

/**
 * @brief Rysuje obiekt Circle na ekranie.
 *
 * Metoda ta korzysta z głównego okna aplikacji do narysowania koła.
 */
void Engine::Circle::draw() {

}

/**
 * @brief Przesuwa koło do podanej pozycji.
 *
 * @param position Nowa pozycja koła.
 */
void Engine::Circle::translate(sf::Vector2f position) {
	this->circle.setPosition(position);
}

/**
 * @brief Obraca koło o podany kąt.
 *
 * @param angle Kąt rotacji.
 */
void Engine::Circle::rotate(float angle) {
	this->circle.rotate(angle);
}

/**
 * @brief Skaluje koło na podstawie podanego wektora skali.
 *
 * @param scale Wektor skali.
 */
void Engine::Circle::scale(sf::Vector2f scale) {
	this->circle.setScale(scale);
}


