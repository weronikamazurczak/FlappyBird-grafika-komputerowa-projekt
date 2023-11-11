#include "Ptak.hpp"

Ptak::Ptak()
{
    //iteratorAminacji = 0;

    if (ptak1Texture.loadFromFile("INNE/img/bird-01.png"))
    {
        ptak1Sprite.setTexture(ptak1Texture);
    }
    else
    {
        std::cout << "Blad wczytania tekstury ptaka 1 w aplikacji!" << std::endl;
    }

    //ptakSprite.setTexture(ramkaAnimacji.at(iteratorAminacji));

}

void Ptak::wyswietlPtaka(sf::RenderWindow* okno)
{
    okno->draw(ptak1Sprite);
    ptak1Sprite.setPosition(sf::Vector2f((okno->getSize().x - ptak1Sprite.getGlobalBounds().width) / 5, okno->getSize().y - ptak1Sprite.getGlobalBounds().height - 125 * 4));

}
