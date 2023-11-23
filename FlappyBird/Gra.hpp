#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include "Ptak.hpp";
#include "Grunt.hpp";




class Gra
{
public:
	Gra();
	void wyswietl(sf::RenderWindow* okno);
	void otworzOknoGry();
	void obslugaKolizji();
	enum gameState {
		GAME_STATE = 0,
		GAME_OVER_STATE = 1
	};
	void zapisywaniePunktow(int punkty);
private:
	int stanGry = GAME_STATE;
	int punktyKoncowe = 0;
	sf::Clock clock;
	sf::Texture tloTexture;
	sf::Sprite tloSprite;
	sf::Font font;
	sf::Text tekstPrzegranaGra;
	sf::Texture koniecTexture;
	sf::Sprite koniecSprite;
	int punkty = 0;
	sf::Text textPunkty;
	void inneParametry(sf::RenderWindow* okno);
	Ptak ptak;
	Grunt grunt;
	Rury rury;
	sf::Music muzyka;
};