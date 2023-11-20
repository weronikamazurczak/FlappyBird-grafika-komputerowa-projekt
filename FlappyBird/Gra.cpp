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

void Gra::inneParametry(sf::RenderWindow* glowneOkno)
{
    glowneOkno->setFramerateLimit(60);
    ptak.ptakInit(glowneOkno);
}



void Gra::obslugaKolizji()
{
    // Tutaj mo¿esz dodaæ kod obs³ugi kolizji, np. zatrzymanie gry, reset pozycji ptaka itp.
    std::cout << "Kolizja! Gra zatrzymana lub resetuj pozycjê ptaka.\n";
    // Przyk³adowy kod:
    // gameState = GameState::GameOver;
    // ptak.resetPosition();
}
void Gra::otworzOknoGry()
{
    sf::RenderWindow oknoGry(sf::VideoMode(768, 1024), "Gra", sf::Style::Titlebar | sf::Style::Close);

    sf::Clock clock;
    inneParametry(&oknoGry);

    while (oknoGry.isOpen())
    {
        float currentTime = clock.restart().asSeconds();
        float fps = 1.f / (currentTime);

        // std::cout << "FPS: " << fps << std::endl;

        sf::Event event;

        while (oknoGry.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                oknoGry.close();
            }

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            ptak.skacz(&oknoGry);

        }
        oknoGry.clear();
        oknoGry.draw(tloSprite);
        if (ptak.kolizja(rury)) {
            obslugaKolizji();
        }

        ptak.przemiescPtakaDoPrzodu(&oknoGry);
        ptak.grawitacjaPtak();
        ptak.draw(&oknoGry);

        rury.poruszanieRur(&oknoGry);
        rury.wyswietlRury(&oknoGry);


        grunt.poruszanieGruntu(&oknoGry);
        grunt.wyswietlgrunt(&oknoGry);


        oknoGry.display();
    }
}