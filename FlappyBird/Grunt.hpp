#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


class Grunt
{
public:
	Grunt();

	void poruszanieGruntu(sf::RenderWindow* okno);
	void wyswietlgrunt(sf::RenderWindow* okno);
private:
	int wyrenderowane = 0;
	sf::Texture gruntTexture;
	sf::Sprite gruntSprite;
	sf::Sprite nowyGruntSprite;
	std::vector<sf::Sprite> gruntVektor;
};