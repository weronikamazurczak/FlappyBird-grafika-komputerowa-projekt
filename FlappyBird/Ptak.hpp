#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Rury.hpp"

//#include <vector>
#define GRAWITACJAPTAKA 3.0
#define SKOKPTAKA 12.0
class Ptak {
public:
	Ptak();
	void przemiescPtakaDoPrzodu(sf::RenderWindow* okno);
	void draw(sf::RenderWindow* okno);
	void skacz(sf::RenderWindow* okno);
	void ptakInit(sf::RenderWindow* okno);
	void grawitacjaPtak();
	bool kolizja(Rury rury);
	float punktyLicznik = 0.f;
	int zliczPunkty();
	sf::Sprite getPtakSprite();
	void resetLicznik();
private:
	float x=0;
	float y=0;
	sf::Sprite ptakSprite;
	//std::vector<sf::Texture > ramkaAnimacji;

	unsigned int iteratorAminacji;

	sf::Texture ptak1Texture;
	sf::Sprite ptak1Sprite;

	sf::Texture ptak2Texture;

	sf::Texture ptak3Texture;

	sf::Texture ptak4Texture;
};