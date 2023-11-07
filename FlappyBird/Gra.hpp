#pragma once
#include <SFML/Graphics.hpp>

class Gra 
{
public:
	Gra();
	void wyswietl(sf::RenderWindow* okno);
	void otworzOknoGry();
private:
	sf::Texture tloTexture;
	sf::Sprite tloSprite;
};