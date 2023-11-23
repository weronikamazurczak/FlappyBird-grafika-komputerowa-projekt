#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>

class MenuGry
{
public: 
	MenuGry();
	void wyswietl(sf::RenderWindow* okno);
	void obsluga(sf::RenderWindow* okno);
	void otworzInstrukcje();
	bool czyInstrukcjaOtwarta;
private:
	sf::Texture tloTexture;
	sf::Sprite tloSprite;


	sf::Texture tloTextureInstr;
	sf::Sprite tloInstrSprite;

	sf::Texture tloTextureGetReady;
	sf::Sprite tloGetReadySprite;


	sf::Texture tytulTexture;
	sf::Sprite tytulSprite;

	sf::Texture przyciskStartTexture;
	sf::Sprite przyciskStartSprite;

	sf::Text przyciskInstrukcja;
	std::string instrukcja;
	sf::Text tekstInstrukcji;

	sf::Font font;
	sf::Font font2;

	sf::RectangleShape zaInstrukcja;
	sf::RectangleShape zaGra;
};