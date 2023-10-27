#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
using namespace std;
class Engine
{
public:
	void ustawRozdzielczosc(int, int);
	void inneParametry(sf::RenderWindow*);
	void petlaGry();
	void czyszczenieOkna(sf::RenderWindow*, sf::Color);
	void czyszczenieBitmapy(sf::Sprite*, sf::Color);
	void zapisywanieDoPliku(string);
private:
	int szerokosc, wysokosc;
};