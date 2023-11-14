#include "Rury.hpp"

using namespace std;

Rury::Rury()
{
    if (ruraGoraTexture.loadFromFile("INNE/img/PipeUp.png"))
    {
        ruraGoraSprite.setTexture(ruraGoraTexture);
        ruraGoraVektor.push_back(ruraGoraSprite);
    }
    else
    {
        std::cout << "Blad wczytania tekstury rura gor w aplikacji!" << std::endl;
    }

    if (ruraDolTexture.loadFromFile("INNE/img/PipeDown.png"))
    {
        ruraDolSprite.setTexture(ruraDolTexture);
        ruraDolVektor.push_back(ruraDolSprite);
    }
    else
    {
        std::cout << "Blad wczytania tekstury rura dol w aplikacji!" << std::endl;
    }

    // rura do punktow ale nie wiem czy bedzie potrzebna, niech bedzie na razie
    if (ruraPunktowaTexture.loadFromFile("INNE/img/InvisibleScoringPipe.png"))
    {
        ruraPunktowaSprite.setTexture(ruraPunktowaTexture);
        //ruraPunktowaVektor.push_back(ruraPunktowaSprite);
    }
    else
    {
        std::cout << "Blad wczytania tekstury rura punktowa w aplikacji!" << std::endl;
    }
    
}

void Rury::poruszanieRur(sf::RenderWindow* okno)
{
    const float dt = 1.0f / 100.0f;
    float ruch = 100.0f * dt;

    for (unsigned short int i = 0; i < ruraGoraVektor.size(); i++)
    {
        sf::Vector2f pozycja = ruraGoraVektor.at(i).getPosition();
        sf::Vector2f pozycja2 = ruraDolVektor.at(i).getPosition();
        ruraGoraVektor.at(i).move(-ruch, 0.0f);
        ruraDolVektor.at(i).move(-ruch, 0.0f);

        if (ruraGoraVektor.at(i).getPosition().x < 0 - ruraGoraVektor.at(i).getLocalBounds().width)
        {
            sf::Vector2f pozycja(okno->getSize().x, ruraGoraVektor.at(i).getPosition().y);

            // Dodajemy losow¹ wartoœæ do pozycji y, aby uzyskaæ ró¿ne wysokoœci rur
            pozycja.y = 502 + rand() % 262;

            ruraGoraVektor.at(i).setPosition(pozycja);
        }
        if (ruraDolVektor.at(i).getPosition().x < 0 - ruraDolVektor.at(i).getLocalBounds().width)
        {
            sf::Vector2f pozycja2(okno->getSize().x, ruraDolVektor.at(i).getPosition().y);

            // Dodajemy losow¹ wartoœæ do pozycji y, aby uzyskaæ ró¿ne wysokoœci rur
            pozycja2.y = 0 - rand() % 369; 

            ruraDolVektor.at(i).setPosition(pozycja2);
        }
    }
}

void Rury::wyswietlRury(sf::RenderWindow* okno)
{
    for (unsigned short int i = 0; i < ruraGoraVektor.size(); i++)
    {
        okno->draw(ruraGoraVektor.at(i));
        okno->draw(ruraDolVektor.at(i));
    }
}

