#pragma once
#include <SFML/Graphics.hpp>
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

private:
	sf::Texture tloTexture;
	sf::Sprite tloSprite;

	void inneParametry(sf::RenderWindow* okno);
	Ptak ptak;
	Grunt grunt;
	Rury rury;
};