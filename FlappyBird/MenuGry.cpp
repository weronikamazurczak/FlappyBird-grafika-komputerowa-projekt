#include "MenuGry.hpp"
#include <iostream>
#include <fstream>
#include <string>


MenuGry::MenuGry()
{
    if (tloTexture.loadFromFile("INNE/img/sky.png"))
    {
        tloSprite.setTexture(tloTexture);
    }
    else 
    {
        std::cout << "Blad wczytania tekstury tla aplikacji!" << std::endl;
    }


    if (tytulTexture.loadFromFile("INNE/img/title.png"))
    {
        tytulSprite.setTexture(tytulTexture);
    }
    else
    {
        std::cout << "Blad wczytania tekstury tytulu!" << std::endl;
    }


    if (przyciskStartTexture.loadFromFile("INNE/img/PlayButton.png"))
    {
        przyciskStartSprite.setTexture(przyciskStartTexture);
    }
    else 
    {
        std::cout << "Blad wczytania tekstury przycisku!" << std::endl;
    }
     
    
    if (font.loadFromFile("INNE/fonts/FlappyBirdy.ttf"))
    {
        przyciskInstrukcja.setFont(font);
    }
    else
    {
        std::cout << "Blad wczytania czcionki" << std::endl;
    } 


    if (font2.loadFromFile("INNE/fonts/Aleo-Regular.otf"))
    {
        tekstInstrukcji.setFont(font2);
    }
    else
    {
        std::cout << "Blad wczytania czcionki" << std::endl;
    }
}

void MenuGry::wyswietl(sf::RenderWindow* okno)
{
    int margines = 100;
    int margines2 = 700;

    okno->draw(tloSprite);


    okno->draw(tytulSprite);
    tytulSprite.setPosition(sf::Vector2f((okno->getSize().x - tytulSprite.getGlobalBounds().width) / 2, margines));


    okno->draw(przyciskStartSprite);
    przyciskStartSprite.setPosition(sf::Vector2f((okno->getSize().x - przyciskStartSprite.getGlobalBounds().width) / 2, okno->getSize().y - przyciskStartSprite.getGlobalBounds().height - margines * 4));

    okno->draw(przyciskInstrukcja);
    przyciskInstrukcja.setString("INSTRUKCJA");
    przyciskInstrukcja.setCharacterSize(150);
    przyciskInstrukcja.setFillColor(sf::Color::Black);
    przyciskInstrukcja.setPosition(sf::Vector2f((okno->getSize().x - przyciskInstrukcja.getGlobalBounds().width)/2, margines2));


}

void MenuGry::obsluga(sf::RenderWindow* okno)
{
    sf::Event event;
    sf::Vector2i pozycjaMyszy;
    

    while (okno->pollEvent(event))
    {
        if (event.type == sf::Event::MouseButtonPressed)
        {
            //sf::Vector2i pozycjaMyszy = sf::Mouse::getPosition(*okno);
            pozycjaMyszy = sf::Mouse::getPosition(*okno);

            if (przyciskStartSprite.getGlobalBounds().contains(pozycjaMyszy.x, pozycjaMyszy.y))
            {
                // TU BEDZUIE TRZEBA DODAC ZE JAK SIE KLIKNIE TO SIE PLANSZA GRY OTWIERA !!!!!!!!!!!!!!!!!!!
            }

            else if (przyciskInstrukcja.getGlobalBounds().contains(pozycjaMyszy.x, pozycjaMyszy.y))
            {
                czyInstrukcjaOtwarta = true;
                if (czyInstrukcjaOtwarta)
                {
                    otworzInstrukcje();
                    czyInstrukcjaOtwarta = false;
                }
            }
        }
    }
}


void MenuGry::otworzInstrukcje()
{
    std::ifstream plik("INNE/instrukcja.txt");
    std::string trescInstrukcji;

    if (plik.is_open()) {
        std::string instr;
        
        while (std::getline(plik, instr))
        {
            trescInstrukcji += instr + "\n";
        }
        plik.close();
    }
    else
    {
        std::cout << "Blad otwarcia instukcji gry" << std::endl;
    }

    tekstInstrukcji.setFont(font2);
    tekstInstrukcji.setString(trescInstrukcji);
    tekstInstrukcji.setCharacterSize(24);  
    tekstInstrukcji.setFillColor(sf::Color::White);

    //okna isntr
    sf::RenderWindow oknoInstrukcji(sf::VideoMode(800, 600), "Instrukcja");

    while (oknoInstrukcji.isOpen())
    {
        sf::Event event;
        while (oknoInstrukcji.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                oknoInstrukcji.close();
            }
        }
        oknoInstrukcji.clear();
        oknoInstrukcji.draw(tekstInstrukcji);
        oknoInstrukcji.display();
    }
}