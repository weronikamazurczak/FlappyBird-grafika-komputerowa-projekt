#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
//#include <vector>
#define GRAWITACJAPTAKA 5.0
#define SKOKPTAKA 20.0
class Ptak {
public:
	Ptak();
	void przemiescPtakaDoPrzodu(sf::RenderWindow* okno);
	void draw(sf::RenderWindow* okno);
	void skacz(sf::RenderWindow* okno);
	void ptakInit(sf::RenderWindow* okno);
	void grawitacjaPtak();
private:
	float x;
	float y;
	sf::Sprite ptakSprite;
	//std::vector<sf::Texture > ramkaAnimacji;

	unsigned int iteratorAminacji;

	sf::Texture ptak1Texture;
	sf::Sprite ptak1Sprite;

	sf::Texture ptak2Texture;

	sf::Texture ptak3Texture;

	sf::Texture ptak4Texture;
};