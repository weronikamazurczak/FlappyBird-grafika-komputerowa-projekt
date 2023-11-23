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

void Ptak::ptakInit(sf::RenderWindow* okno) {
    x = (okno->getSize().x - ptak1Sprite.getGlobalBounds().width) / 5;
    y = okno->getSize().y - ptak1Sprite.getGlobalBounds().height - 115 * 5;

}

void Ptak::przemiescPtakaDoPrzodu(sf::RenderWindow* okno)
{

    ptak1Sprite.setPosition(x, y);

}
void Ptak::draw(sf::RenderWindow* okno) {
    okno->draw(ptak1Sprite);
}
void Ptak::skacz(sf::RenderWindow* okno) {

    ptak1Sprite.setPosition(x, y - SKOKPTAKA);
    y -= SKOKPTAKA;

}
void Ptak::grawitacjaPtak() {
    ptak1Sprite.setPosition(x, y + GRAWITACJAPTAKA);
    y += GRAWITACJAPTAKA;
    if (y < 10)
        y = 10;
    if (y > 700)
        y = 700;
}

sf::Sprite Ptak::getPtakSprite()
{
    return ptakSprite;
}

bool Ptak::kolizja(Rury rury)
{
    const sf::FloatRect ptakRect = ptak1Sprite.getGlobalBounds();

    for (auto& element : rury.getRuraGoraVektor())
    {
        if (ptakRect.intersects(element.getGlobalBounds()))
        {
            return true;
        }
    }


    for (auto& element : rury.getRuraDolVektor())
    {
        if (ptakRect.intersects(element.getGlobalBounds()))
        {
            return true;
        }
    }
    if (y < 10)
    {
        return true;
    }

    if (y >= 695)
    {
        return true;
    }

    return false;
}

int Ptak::zliczPunkty()
{
    punktyLicznik += 0.005;
    return punktyLicznik;
}

