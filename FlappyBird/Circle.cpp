#include "Engine.hpp"

/**
 * @brief Konstruktor obiektu Circle ustawiaj¹cy promieñ ko³a.
 *
 * @param radius Promieñ ko³a.
 */
Engine::Circle::Circle(float radius) {
	this->circle.setRadius(radius);
}

/**
 * @brief Rysuje obiekt Circle na ekranie.
 *
 * Metoda ta korzysta z g³ównego okna aplikacji do narysowania ko³a.
 */
void Engine::Circle::draw() {

}

/**
 * @brief Przesuwa ko³o do podanej pozycji.
 *
 * @param position Nowa pozycja ko³a.
 */
void Engine::Circle::translate(sf::Vector2f position) {
	this->circle.setPosition(position);
}

/**
 * @brief Obraca ko³o o podany k¹t.
 *
 * @param angle K¹t rotacji.
 */
void Engine::Circle::rotate(float angle) {
	this->circle.rotate(angle);
}

/**
 * @brief Skaluje ko³o na podstawie podanego wektora skali.
 *
 * @param scale Wektor skali.
 */
void Engine::Circle::scale(sf::Vector2f scale) {
	this->circle.setScale(scale);
}


