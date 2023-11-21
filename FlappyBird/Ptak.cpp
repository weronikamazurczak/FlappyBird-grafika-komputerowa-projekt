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
    y = okno->getSize().y - ptak1Sprite.getGlobalBounds().height - 125 * 4;

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
    const sf::FloatRect ptakRect = ptakSprite.getGlobalBounds();


    if (y < 10)
        return true;
    if (y >= 695)
        return true;

    for (auto& ruraGora : rury.getRuraGoraVektor())
        return ptakRect.intersects(ruraGora.getGlobalBounds());


    for (auto& ruraDol : rury.getRuraDolVektor())
        return ptakRect.intersects(ruraDol.getGlobalBounds());

    return false;
}

int Ptak::zliczPunkty()
{
    punktyLicznik += 0.005;
    return punktyLicznik;
}

