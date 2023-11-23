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

    sf::Music muzyka;
    muzyka.openFromFile("INNE/sound/Schnappi_mit_Untertitel.wav");
    muzyka.play();
    std::cout << "jhksjdf" << std::endl;
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
    if (font.loadFromFile("INNE/fonts/ArialBold.ttf"))
    {
        textPunkty.setFont(font);
    }
    else
    {
        std::cout << "Blad wczytania czcionki" << std::endl;
    }
    if (font.loadFromFile("INNE/fonts/ArialBold.ttf"))
    {
        tekstPrzegranaGra.setFont(font);
    }
    else
    {
        std::cout << "Blad wczytania czcionki" << std::endl;
    }
    textPunkty.setCharacterSize(80);
    textPunkty.setPosition(20,20);
    textPunkty.setFillColor(sf::Color::Red);
    textPunkty.setString(std::to_string(punkty));

    tekstPrzegranaGra.setCharacterSize(26);
    tekstPrzegranaGra.setPosition(100, 120);
    tekstPrzegranaGra.setFillColor(sf::Color::Red);
    tekstPrzegranaGra.setString("Przegrano gre!!!, nacisnij spacje aby zaczac gre");
}



void Gra::obslugaKolizji()
{
    std::cout << "Kolizja! Gra zatrzymana lub resetuj pozycjê ptaka.\n";
    stanGry = GAME_OVER_STATE;
}
void Gra::otworzOknoGry()
{
    sf::RenderWindow oknoGry(sf::VideoMode(768, 1024), "Gra", sf::Style::Titlebar | sf::Style::Close);
    sf::Event event;

    inneParametry(&oknoGry);
    
    while (oknoGry.isOpen())
    {
        while (oknoGry.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                oknoGry.close();
            }

        }
        if (stanGry == GAME_STATE) {
            float currentTime = clock.restart().asSeconds();
            float fps = 1.f / (currentTime);

            // std::cout << "FPS: " << fps << std::endl;




            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                ptak.skacz(&oknoGry);

            }

            punktyKoncowe = ptak.zliczPunkty();
            textPunkty.setString(std::to_string(ptak.zliczPunkty()));
            oknoGry.clear();
            oknoGry.draw(tloSprite);



            ptak.przemiescPtakaDoPrzodu(&oknoGry);
            ptak.grawitacjaPtak();
            ptak.draw(&oknoGry);

            rury.poruszanieRur(&oknoGry);
            rury.wyswietlRury(&oknoGry);


            grunt.poruszanieGruntu(&oknoGry);
            grunt.wyswietlgrunt(&oknoGry);
            if (ptak.kolizja(rury)) {
                obslugaKolizji();
            }
            oknoGry.draw(textPunkty);
            oknoGry.display();
        }
           
            if (stanGry == GAME_OVER_STATE) {
                oknoGry.clear();
                oknoGry.draw(tloSprite);
                rury.wyswietlRury(&oknoGry);
                ptak.draw(&oknoGry);
                grunt.wyswietlgrunt(&oknoGry);
                oknoGry.draw(tekstPrzegranaGra);
                oknoGry.draw(textPunkty);
                oknoGry.display();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    zapisywaniePunktow(punktyKoncowe);
                    ptak.ptakInit(&oknoGry);
                    rury.resetRury();
                    punkty = 0;
                    ptak.resetLicznik();
                    stanGry = GAME_STATE;
                    oknoGry.close();
                    otworzOknoGry();
                }
            }
    }
}

void Gra::zapisywaniePunktow(int punktyKoncowe) {
    std::fstream plik;
    plik.open("punkty.txt", std::ios::app);
    plik << "Ilosc punktow : " << punktyKoncowe << std::endl;
    plik.close();
}