#include "MenuGry.hpp"
#include "Gra.hpp"


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
    int margines3 = 750;

    okno->clear();

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

    okno->draw(zaInstrukcja);
    zaInstrukcja.setSize(sf::Vector2f(435, 100));
    zaInstrukcja.setFillColor(sf::Color::Transparent);
    zaInstrukcja.setPosition(sf::Vector2f((okno->getSize().x - przyciskInstrukcja.getGlobalBounds().width) / 2, margines3));

}

void MenuGry::obsluga(sf::RenderWindow* okno)
{
    sf::Event event;
    sf::Vector2i pozycjaMyszy;

    pozycjaMyszy = sf::Mouse::getPosition(*okno);




    while (okno->pollEvent(event))
    {
        if (event.type == sf::Event::MouseButtonPressed)
        {
            std::cout << przyciskInstrukcja.getGlobalBounds().getPosition().x << std::endl;
            std::cout << przyciskInstrukcja.getGlobalBounds().getPosition().y << std::endl;
            std::cout << pozycjaMyszy.x << "mysz" << std::endl;
            std::cout << pozycjaMyszy.y << "kshdhhfjsd" << std::endl;
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (zaInstrukcja.getGlobalBounds().contains(pozycjaMyszy.x, pozycjaMyszy.y))
                {
                    otworzInstrukcje();
                    
                }
                if (przyciskStartSprite.getGlobalBounds().contains(pozycjaMyszy.x, pozycjaMyszy.y))
                {
                    Gra gra;
                    gra.otworzOknoGry();
                }

            }
            

            /*if (przyciskStartSprite.getGlobalBounds().contains(pozycjaMyszy.x, pozycjaMyszy.y))
            {
                Gra gra;
                gra.otworzOknoGry();
            }*/
            
        }
    }
}


void MenuGry::otworzInstrukcje()
{
    //okna isntr
    sf::RenderWindow oknoInstrukcji(sf::VideoMode(800, 600), "Instrukcja");

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

