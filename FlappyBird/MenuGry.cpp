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
        std::cout << "B³ad wczytania tekstury t³a aplikacji!" << std::endl;
    }


    if (tytulTexture.loadFromFile("INNE/img/title.png"))
    {
        tytulSprite.setTexture(tytulTexture);
    }
    else
    {
        std::cout << "B³ad wczytania tekstury tytu³u!" << std::endl;
    }


    if (przyciskStartTexture.loadFromFile("INNE/img/PlayButton.png"))
    {
        przyciskStartSprite.setTexture(przyciskStartTexture);
    }
    else 
    {
        std::cout << "B³ad wczytania tekstury przycisku!" << std::endl;
    }
     
    
    if (font.loadFromFile("INNE/fonts.FlappyBirdy.ttf"))
    {
        przyciskInstrukcja.setFont(font);
    }
    else
    {
        std::cout << "B³ad wczytania czcionki" << std::endl;
    } 

}


void MenuGry::wyswietl(sf::RenderWindow* okno)
{
    int margines = 100;

    okno->draw(tloSprite);


    okno->draw(tytulSprite);
    tytulSprite.setPosition(sf::Vector2f((okno->getSize().x - tytulSprite.getGlobalBounds().width) / 2, margines));


    okno->draw(przyciskStartSprite);
    przyciskStartSprite.setPosition(sf::Vector2f((okno->getSize().x - przyciskStartSprite.getGlobalBounds().width) / 2, okno->getSize().y - przyciskStartSprite.getGlobalBounds().height - margines * 3));

    okno->draw(przyciskInstrukcja);
    przyciskInstrukcja.setString("INSTRUKCJA");
    przyciskInstrukcja.setCharacterSize(150);
    przyciskInstrukcja.setFillColor(sf::Color::Red);
    przyciskInstrukcja.setPosition(100, 200);
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
        }
        else if (przyciskInstrukcja.getGlobalBounds().contains(pozycjaMyszy.x, pozycjaMyszy.y))
        {
            otworzInstrukcje();
        }
    }
}

void MenuGry::otworzInstrukcje()
{
    std::ifstream plik("instrukcja.txt");
    if (plik.is_open()) {
        std::string instr;
        while (std::getline(plik, instr))
        {
            std::cout << instr << std::endl;
        }
        plik.close();
    }
    else
    {
        std::cout << "B³ad otwarcia instukcji gry" << std::endl;
    }
}