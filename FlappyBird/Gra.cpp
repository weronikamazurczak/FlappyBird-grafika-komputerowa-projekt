#include "Gra.hpp"

Gra::Gra()
{
    if (tloTexture.loadFromFile("INNE/img/sky.png"))
    {
        tloSprite.setTexture(tloTexture);
    }
    else
    {
        std::cout << "Blad wczytania tekstury tla aplikacji!" << std::endl;
    }
}

void Gra::wyswietl(sf::RenderWindow* okno)
{
    okno->clear();
    okno->draw(tloSprite);
    okno->display();
}

void Gra::otworzOknoGry()
{
    sf::RenderWindow oknoGry(sf::VideoMode(768, 1024), "Gra", sf::Style::Titlebar | sf::Style::Close);

    while (oknoGry.isOpen())
    {
        sf::Event event;

        while (oknoGry.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                oknoGry.close();
            }
        }
        oknoGry.clear();
        oknoGry.draw(tloSprite);
        ptak.wyswietlPtaka(&oknoGry);
        rury.poruszanieRur(&oknoGry);
        rury.wyswietlRury(&oknoGry);
        grunt.poruszanieGruntu(&oknoGry);
        grunt.wyswietlgrunt(&oknoGry);
        oknoGry.display();
    }
}