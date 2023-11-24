#include "Engine.hpp";


/**
 * @brief Ustawia rozdzielczość silnika gry.
 * @param szerokosc Szerokość okna gry.
 * @param wysokosc Wysokość okna gry.
 */
void Engine::ustawRozdzielczosc(int szerokosc, int wysokosc)
{
    this->szerokosc = szerokosc;
    this->wysokosc = wysokosc;
}

/**
 * @brief Ustawia inne parametry dla głównego okna gry.
 * @param glowneOkno Wskaźnik na główne okno gry.
 */
void Engine::inneParametry(sf::RenderWindow* glowneOkno)
{
    glowneOkno->setFramerateLimit(60);
}

/**
 * @brief Czyści okno gry.
 * @param okno Wskaźnik na okno gry.
 * @param kolor Kolor, którym ma być wyczyszczone okno.
 */
void Engine::czyszczenieOkna(sf::RenderWindow* okno, sf::Color kolor)
{
    okno->clear(kolor);
}

/**
 * @brief Czyści bitmapę.
 * @param bitmapa Wskaźnik na bitmapę.
 * @param kolor Kolor, którym ma być wyczyszczona bitmapa.
 */
void Engine::czyszczenieBitmapy(sf::Sprite* bitmapa, sf::Color kolor)
{
    bitmapa->setColor(kolor);
}

/**
 * @brief Zapisuje treść loga do pliku.
 * @param trescLoga Treść loga do zapisania.
 */
void Engine::zapisywanieDoPliku(string trescLoga)
{
    fstream strumienpliku;
    strumienpliku.open("Logi.txt", ios::app);
    strumienpliku << trescLoga << endl;
    strumienpliku.close();
}

/**
 * @brief Główna pętla gry.
 */
void Engine::petlaGry()
{
    sf::RenderWindow window(sf::VideoMode(szerokosc, wysokosc), "FlappyBirdPro++!", sf::Style::Titlebar | sf::Style::Close);
    sf::Clock czasomierz;
    
    //czyszczenieBitmapy();
    while (window.isOpen())
    {
        czyszczenieOkna(&window, sf::Color::Blue);
        sf::Event event;
        while (window.pollEvent(event))
        {
            //mCzas - miniony czas
            if (event.type == sf::Event::KeyPressed)
                czasomierz.restart();
            float mCzas = czasomierz.getElapsedTime().asSeconds();
            if (mCzas > 60 || event.type == sf::Event::Closed)
                window.close();

        }

        window.clear(sf::Color::Blue);

        menu.wyswietl(&window);
        menu.obsluga(&window);
    }
}

/**
 * @brief Główna funkcja programu.
 * @return Zwraca 0 po poprawnym zakończeniu programu.
 */
int main()
{
    Engine engine;
    engine.ustawRozdzielczosc(768, 1024);
    engine.petlaGry();
    engine.zapisywanieDoPliku("FlappyBird");
    return 0;
}