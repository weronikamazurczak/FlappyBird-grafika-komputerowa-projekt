#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>

class Rury
{
public:
	Rury();

	void poruszanieRur(sf::RenderWindow* okno);
	void resetRury();
	void wyswietlRury(sf::RenderWindow* okno);
	std::vector<sf::Sprite> getRuraDolVektor();
	std::vector<sf::Sprite> getRuraGoraVektor();

private:
	sf::Texture ruraGoraTexture;
	sf::Sprite ruraGoraSprite;
	std::vector<sf::Sprite> ruraGoraVektor;

	sf::Texture ruraDolTexture;
	sf::Sprite ruraDolSprite;
	std::vector<sf::Sprite> ruraDolVektor;

	std::vector<sf::Sprite> ruryVektor;

	sf::Texture ruraPunktowaTexture;
	sf::Sprite ruraPunktowaSprite;
	std::vector<sf::Sprite> ruraPunktowaVektor;
};