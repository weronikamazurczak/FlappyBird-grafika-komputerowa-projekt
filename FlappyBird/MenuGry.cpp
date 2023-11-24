#include "MenuGry.hpp"
#include "Gra.hpp"

/**
 * @brief Konstruktor klasy MenuGry. Inicjalizuje tekstury, muzykê i inne elementy menu gry.
 */
MenuGry::MenuGry()
{
    
    sf::Music muzyka;
    muzyka.openFromFile("INNE/sound/Schnappi_mit_Untertitel.wav");
    muzyka.play();

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

    if (tloTextureInstr.loadFromFile("INNE/img/BackgroundNight.png"))
    {
        tloTextureInstr.setSmooth(true);
        tloInstrSprite.setTexture(tloTextureInstr);
        tloInstrSprite.setScale(2.0f, 2.0f);
    }
    else
    {
        std::cout << "Blad wczytania tekstury tla!" << std::endl;
    }

    if (tloTextureGetReady.loadFromFile("INNE/img/GetReady.png"))
    {
        tloTextureGetReady.setSmooth(true);
        tloGetReadySprite.setTexture(tloTextureGetReady);
        tloGetReadySprite.setScale(2.0f, 2.0f);
    }
    else
    {
        std::cout << "Blad wczytania tekstury!" << std::endl;
    }
    
    if (tloTextureHowToPlay.loadFromFile("INNE/img/howToPlay.png"))
    {
        tloTextureHowToPlay.setSmooth(true);
        tloSpriteHowToPlay.setTexture(tloTextureHowToPlay);
        tloSpriteHowToPlay.setScale(2.5f, 2.5f);
    }
    else
    {
        std::cout << "Blad wczytania tekstury!" << std::endl;
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

/**
 * @brief Wyœwietla menu gry.
 *
 * @param okno WskaŸnik na okno, w którym ma byæ wyœwietlone menu.
 */
void MenuGry::wyswietl(sf::RenderWindow* okno)
{
    int margines = 100;
    int margines2 = 700;
    int margines3 = 750;
    tytulSprite.setPosition(sf::Vector2f((okno->getSize().x - tytulSprite.getGlobalBounds().width) / 2, margines));
    przyciskStartSprite.setPosition(sf::Vector2f((okno->getSize().x - przyciskStartSprite.getGlobalBounds().width) / 2, okno->getSize().y - przyciskStartSprite.getGlobalBounds().height - margines * 4));
    przyciskInstrukcja.setString("INSTRUKCJA");
    przyciskInstrukcja.setCharacterSize(150);
    przyciskInstrukcja.setFillColor(sf::Color::Black);
    przyciskInstrukcja.setPosition(sf::Vector2f((okno->getSize().x - przyciskInstrukcja.getGlobalBounds().width) / 2, margines2));
    zaInstrukcja.setSize(sf::Vector2f(435, 100));
    zaInstrukcja.setFillColor(sf::Color::Transparent);
    zaInstrukcja.setPosition(sf::Vector2f((okno->getSize().x - przyciskInstrukcja.getGlobalBounds().width) / 2, margines3));
    zaGra.setSize(sf::Vector2f(280, 155));
    zaGra.setFillColor(sf::Color::Red);
    zaGra.setPosition(sf::Vector2f((okno->getSize().x - przyciskStartSprite.getGlobalBounds().width) / 2, okno->getSize().y - przyciskStartSprite.getGlobalBounds().height - margines * 4));
    okno->clear();
    okno->draw(zaInstrukcja);
    okno->draw(zaGra);
    okno->draw(tloSprite);
    okno->draw(tytulSprite);
    okno->draw(przyciskStartSprite);
    okno->draw(przyciskInstrukcja);
    okno->display();
}

/**
 * @brief Obs³uguje interakcje u¿ytkownika z menu gry.
 *
 * @param okno WskaŸnik na okno, w którym jest wyœwietlane menu.
 */
void MenuGry::obsluga(sf::RenderWindow* okno)
{
    sf::Event event;
    sf::Vector2i pozycjaMyszy;
    pozycjaMyszy = sf::Mouse::getPosition(*okno);
    while (okno->pollEvent(event))
    {
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (zaInstrukcja.getGlobalBounds().contains(pozycjaMyszy.x, pozycjaMyszy.y))
                {
                    otworzInstrukcje();
                    
                }
                if (zaGra.getGlobalBounds().contains(pozycjaMyszy.x, pozycjaMyszy.y))
                {
                    okno->close();
                    Gra gra;
                    gra.otworzOknoGry();
                }
            }
        }
    }
}

/**
 * @brief Otwiera instrukcje gry.
 */
void MenuGry::otworzInstrukcje()
{
    //okna isntr
    sf::RenderWindow oknoInstrukcji(sf::VideoMode(550, 600), "Instrukcja");
    

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

    tloGetReadySprite.setPosition(oknoInstrukcji.getSize().x / 2 - tloGetReadySprite.getGlobalBounds().width / 2, tloGetReadySprite.getGlobalBounds().height / 2);
    tloSpriteHowToPlay.setPosition(oknoInstrukcji.getSize().x / 2 - tloSpriteHowToPlay.getGlobalBounds().width / 2, oknoInstrukcji.getSize().y / 2 - tloSpriteHowToPlay.getGlobalBounds().height / 3.6f);

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
        oknoInstrukcji.draw(tloInstrSprite);
        oknoInstrukcji.draw(tloGetReadySprite);
        oknoInstrukcji.draw(tloSpriteHowToPlay);
        oknoInstrukcji.display();
    }
}

