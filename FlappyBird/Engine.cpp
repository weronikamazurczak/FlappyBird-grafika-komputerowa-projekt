// FlappyBird.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

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
        window.display();
    }
}


int main()
{
    Engine engine;
    engine.ustawRozdzielczosc(1024, 768);
    engine.petlaGry();
    engine.zapisywanieDoPliku("gowno");
    return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
