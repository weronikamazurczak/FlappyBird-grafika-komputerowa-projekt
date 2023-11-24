#include "Rury.hpp"

using namespace std;

/**
 * @brief Konstruktor klasy Rury. Inicjalizuje tekstury rur.
 */
Rury::Rury()
{
    if (ruraGoraTexture.loadFromFile("INNE/img/PipeUp.png"))
    {
        ruraGoraSprite.setTexture(ruraGoraTexture);
        for (int i = 0; i < 3; i++)
        {

            int wysokoscRuraGora = 523;
            ruraGoraSprite.setPosition(i * 320.0f, wysokoscRuraGora);
            ruraGoraVektor.push_back(ruraGoraSprite);
        }
    }
    else
    {
        std::cout << "Blad wczytania tekstury rura gor w aplikacji!" << std::endl;
    }

    if (ruraDolTexture.loadFromFile("INNE/img/PipeDown.png"))
    {
        ruraDolSprite.setTexture(ruraDolTexture);
        for (int i = 0; i < 3; i++)
        {
            int wysokosRURAdol = 0 - rand() % 50;

            while (((763 - ruraGoraVektor.at(i).getPosition().y + wysokosRURAdol) > 220) &&
                ruraGoraVektor.at(i).getPosition().y >= 523) {
                wysokosRURAdol = 0 - rand() % 100;
            }
            ruraDolSprite.setPosition(i * 320.0f, wysokosRURAdol);
            ruraDolVektor.push_back(ruraDolSprite);
        }

    }
    else
    {
        std::cout << "Blad wczytania tekstury rura dol w aplikacji!" << std::endl;
    }


    if (ruraPunktowaTexture.loadFromFile("INNE/img/InvisibleScoringPipe.png"))
    {
        ruraPunktowaSprite.setTexture(ruraPunktowaTexture);
    }
    else
    {
        std::cout << "Blad wczytania tekstury rura punktowa w aplikacji!" << std::endl;
    }
}

/**
 * @brief Resetuje rury do stanu początkowego.
 */
void Rury::resetRury() {
    for (int i = 0; i < 3; i++)
    {
        int wysokosRURAdol = 0 - rand() % 50;

        while (((763 - ruraGoraVektor.at(i).getPosition().y + wysokosRURAdol) > 220) &&
            ruraGoraVektor.at(i).getPosition().y >= 523) {
            wysokosRURAdol = 0 - rand() % 100;
        }
        ruraDolSprite.setPosition(i * 320.0f, wysokosRURAdol);
        ruraDolVektor.push_back(ruraDolSprite);
    }
}

/**
 * @brief Porusza rury w grze.
 *
 * @param okno Wskaźnik na okno gry.
 */
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
            ruraGoraVektor.at(i).setPosition(pozycja);
        }
        if (ruraDolVektor.at(i).getPosition().x < 0 - ruraDolVektor.at(i).getLocalBounds().width)
        {
            sf::Vector2f pozycja2(okno->getSize().x, ruraDolVektor.at(i).getPosition().y);
            ruraDolVektor.at(i).setPosition(pozycja2);
        }

    }
}

/**
 * @brief Wyświetla rury na ekranie.
 *
 * @param okno Wskaźnik na okno gry.
 */
void Rury::wyswietlRury(sf::RenderWindow* okno)
{
    for (unsigned short int i = 0; i < ruraGoraVektor.size(); i++)
    {
        okno->draw(ruraGoraVektor.at(i));
        okno->draw(ruraDolVektor.at(i));
    }
}

/**
 * @brief Zwraca wektor sprite'ów dolnych rur.
 *
 * @return Wektor sprite'ów dolnych rur.
 */
std::vector<sf::Sprite> Rury::getRuraDolVektor()
{
    return ruraDolVektor;
}

/**
 * @brief Zwraca wektor sprite'ów górnych rur.
 *
 * @return Wektor sprite'ów górnych rur.
 */
std::vector<sf::Sprite> Rury::getRuraGoraVektor()
{
    return ruraGoraVektor;
}
