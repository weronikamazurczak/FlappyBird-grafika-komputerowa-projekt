#include "Engine.hpp"

/**
 * @brief Rysuje okr¹g o podanym promieniu, pozycji i kolorze.
 *
 * @param radius Promieñ okrêgu.
 * @param position Pozycja okrêgu na ekranie.
 * @param color Kolor okrêgu.
 */
void Engine::PrimitiveRenderer::rysujOkrag(float radius, sf::Vector2f position, sf::Color color) {
	Engine::Circle okrag(radius);
	okrag.translate(position);
	okrag.draw();
}