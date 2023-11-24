#include "Engine.hpp"


void Engine::PrimitiveRenderer::rysujOkrag(float radius, sf::Vector2f position, sf::Color color) {
	Engine::Circle okrag(radius);
	okrag.translate(position);
	okrag.draw();
}