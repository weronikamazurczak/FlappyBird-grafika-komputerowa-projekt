#include "Engine.hpp";

void Engine::ustawRozdzielczosc(int szerokosc, int wysokosc)
{
    this->szerokosc = szerokosc;
    this->wysokosc = wysokosc;
}

void Engine::inneParametry(sf::RenderWindow* glowneOkno)
{
    glowneOkno->setFramerateLimit(60);
}

void Engine::czyszczenieOkna(sf::RenderWindow* okno, sf::Color kolor)
{
    okno->clear(kolor);
}

void Engine::czyszczenieBitmapy(sf::Sprite* bitmapa, sf::Color kolor)
{
    bitmapa->setColor(kolor);
}

void Engine::zapisywanieDoPliku(string trescLoga)
{
    fstream strumienpliku;
    strumienpliku.open("Logi.txt", ios::app);
    strumienpliku << trescLoga << endl;
    strumienpliku.close();
}

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
            if (mCzas > 30 || event.type == sf::Event::Closed)
                window.close();

        }

        window.clear(sf::Color::Blue);

        menu.wyswietl(&window);
        menu.obsluga(&window);


        window.display();
    }
}

int main()
{
    Engine engine;
    engine.ustawRozdzielczosc(768, 1024);
    engine.petlaGry();
    engine.zapisywanieDoPliku("FlappyBird");
    return 0;
}