#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
//#include <vector>

class Ptak {
public:
	Ptak();
	void wyswietlPtaka(sf::RenderWindow* okno);
private:
	sf::Sprite ptakSprite;
	//std::vector<sf::Texture > ramkaAnimacji;

	unsigned int iteratorAminacji;

	sf::Texture ptak1Texture;
	sf::Sprite ptak1Sprite;

	sf::Texture ptak2Texture;

	sf::Texture ptak3Texture;

	sf::Texture ptak4Texture;
};