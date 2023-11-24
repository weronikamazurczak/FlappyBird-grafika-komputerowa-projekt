#include "Gra.hpp"

/**
 * @brief Konstruktor klasy Gra. Inicjalizuje tekstury, muzykê i inne elementy gry.
 */
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

    if (!muzyka.openFromFile("INNE/sound/Schnappi_mit_Untertitel.wav"))
    {
        std::cout << "Blad wczytania pliku muzycznego!" << std::endl;
    }
    else
    {
        muzyka.play();
    }

    if (koniecTexture.loadFromFile("INNE/img/gameover.png"))
    {
        koniecTexture.setSmooth(true);
        koniecSprite.setTexture(koniecTexture);
        koniecSprite.setScale(2.0f, 2.0f);
    }
    else
    {
        std::cout << "Blad wczytania tekstury!" << std::endl;
    }

}

/**
 * @brief Wyœwietla grê na ekranie.
 * @param okno WskaŸnik na okno gry.
 */
void Gra::wyswietl(sf::RenderWindow* okno)
{
    okno->clear();
    okno->draw(tloSprite);
    okno->display();
}

/**
 * @brief Ustawia inne parametry dla gry.
 * @param glowneOkno WskaŸnik na g³ówne okno gry.
 */
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
    textPunkty.setFillColor(sf::Color::White);
    textPunkty.setString(std::to_string(punkty));
}

/**
 * @brief Obs³uguje kolizje w grze.
 */
void Gra::obslugaKolizji()
{
    std::cout << "Kolizja! Gra zatrzymana lub resetuj pozycjê ptaka.\n";
    stanGry = GAME_OVER_STATE;
}

/**
 * @brief Otwiera okno gry i zarz¹dza logik¹ gry.
 *
 * Ta funkcja tworzy okno gry, obs³uguje zdarzenia i zarz¹dza stanem gry.
 * W zale¿noœci od stanu gry, funkcja wywo³uje odpowiednie funkcje do rysowania i aktualizacji obiektów gry.
 */
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
                koniecSprite.setOrigin(koniecSprite.getLocalBounds().width / 2.0f, koniecSprite.getLocalBounds().height / 2.0f);
                koniecSprite.setPosition(sf::Vector2f(oknoGry.getSize().x / 2.0f, oknoGry.getSize().y / 2.0f - 55.0f));
                oknoGry.draw(tloSprite);
                rury.wyswietlRury(&oknoGry);
                ptak.draw(&oknoGry);
                grunt.wyswietlgrunt(&oknoGry);
                oknoGry.draw(koniecSprite);
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

/**
 * @brief Zapisuje wynik koñcowy gry do pliku.
 *
 * Ta funkcja otwiera plik "punkty.txt" w trybie do³¹czania (append) i zapisuje do niego wynik koñcowy gry.
 *
 * @param punktyKoncowe Wynik koñcowy gry do zapisania.
 */
void Gra::zapisywaniePunktow(int punktyKoncowe) {
    std::fstream plik;
    plik.open("punkty.txt", std::ios::app);
    plik << "Ilosc punktow : " << punktyKoncowe << std::endl;
    plik.close();
}