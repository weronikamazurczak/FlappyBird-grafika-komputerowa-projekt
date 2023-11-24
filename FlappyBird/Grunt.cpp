#include "Grunt.hpp"

using namespace std;

/**
 * @brief Konstruktor klasy Grunt. Inicjalizuje teksturê gruntu.
 */
Grunt::Grunt()
{
    if (gruntTexture.loadFromFile("INNE/img/land.png"))
    {
        gruntSprite.setTexture(gruntTexture);
        gruntVektor.push_back(gruntSprite);
    }
    else
    {
        std::cout << "Blad wczytania tekstury gruntu w aplikacji!" << std::endl;
    }
}

/**
 * @brief Porusza gruntem w grze.
 *
 * Ta funkcja przesuwa grunt w lewo z okreœlon¹ prêdkoœci¹. Gdy grunt opuœci ekran, jest on ponownie dodawany po prawej stronie ekranu.
 *
 * @param okno WskaŸnik na okno gry.
 */
void Grunt::poruszanieGruntu(sf::RenderWindow* okno)
{
    const float dt = 1.0f / 100.0f;
    float ruch = 100.0f * dt;

    for (unsigned short int i = 0; i < gruntVektor.size(); i++)
    {
        sf::Vector2f pozycja = gruntVektor.at(i).getPosition();
        if (gruntVektor.at(i).getPosition().x < 0 && wyrenderowane!=1) {
            wyrenderowane = 1;
            nowyGruntSprite.setTexture(gruntTexture);
            nowyGruntSprite.setPosition(pozycja.x + gruntVektor.at(i).getLocalBounds().width, pozycja.y);
            gruntVektor.push_back(nowyGruntSprite);
            gruntVektor.at(i).setPosition(pozycja);
        }
        else if (pozycja.x + gruntVektor.at(i).getLocalBounds().width < 0 )
        {
            pozycja.x = okno->getSize().x;
            nowyGruntSprite.setTexture(gruntTexture);
            nowyGruntSprite.setPosition(pozycja.x + gruntVektor.at(i).getLocalBounds().width, pozycja.y);
            gruntVektor.push_back(nowyGruntSprite);
            gruntVektor.at(i).setPosition(pozycja);
        }

        gruntVektor.at(i).move(-ruch, 0.0f);
    }
}

/**
 * @brief Wyœwietla grunt na ekranie.
 *
 * Ta funkcja rysuje grunt na ekranie w okreœlonej pozycji.
 *
 * @param okno WskaŸnik na okno gry.
 */
void Grunt::wyswietlgrunt(sf::RenderWindow* okno)
{
    for (unsigned short int i = 0; i < gruntVektor.size(); i++)
    {
        sf::Vector2f spritePosition = gruntVektor.at(i).getPosition();
        spritePosition.y = okno->getSize().y - gruntVektor.at(i).getLocalBounds().height;
        gruntVektor.at(i).setPosition(spritePosition);
        okno->draw(gruntVektor.at(i));
    }
}