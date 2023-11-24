#include "Engine.hpp"

/**
 * @brief Rysuje okr�g o podanym promieniu, pozycji i kolorze.
 *
 * @param radius Promie� okr�gu.
 * @param position Pozycja okr�gu na ekranie.
 * @param color Kolor okr�gu.
 */
void Engine::PrimitiveRenderer::rysujOkrag(float radius, sf::Vector2f position, sf::Color color) {
	Engine::Circle okrag(radius);
	okrag.translate(position);
	okrag.draw();
}