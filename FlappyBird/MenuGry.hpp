#pragma once
#include <SFML/Graphics.hpp>

class MenuGry
{
public: 
	MenuGry();
	void wyswietl(sf::RenderWindow* okno);
	void obsluga(sf::RenderWindow* okno);
	void otworzInstrukcje();
private:
	sf::Texture tloTexture;
	sf::Sprite tloSprite;

	sf::Texture tytulTexture;
	sf::Sprite tytulSprite;

	sf::Texture przyciskStartTexture;
	sf::Sprite przyciskStartSprite;

	sf::Text przyciskInstrukcja;
	std::string instrukcja;


	sf::Font font;
};