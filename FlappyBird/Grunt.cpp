#include "Grunt.hpp"

using namespace std;

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

//problem z pierwszym przejsciem tektury pozniej jest ciagla linia
void Grunt::poruszanieGruntu(sf::RenderWindow* okno)
{
    const float dt = 1.0f / 100.0f;
    float ruch = 100.0f * dt;

    for (unsigned short int i = 0; i < gruntVektor.size(); i++)
    {
        sf::Vector2f pozycja = gruntVektor.at(i).getPosition();
       // cout << gruntVektor.at(i).getPosition().x << endl;
        //cout << "okno rozmiar " << okno->getSize().x << endl;
        // Jeœli sprite dotknie lewej strony ekranu, przenieœ go na koniec wektora
        if (gruntVektor.at(i).getPosition().x < 0 && wyrenderowane!=1) {
            wyrenderowane = 1;
            nowyGruntSprite.setTexture(gruntTexture);
            nowyGruntSprite.setPosition(pozycja.x + gruntVektor.at(i).getLocalBounds().width, pozycja.y);
            gruntVektor.push_back(nowyGruntSprite);
            gruntVektor.at(i).setPosition(pozycja);
        }
        else if (pozycja.x + gruntVektor.at(i).getLocalBounds().width < 0 /* || gruntVektor.at(i).getPosition().x < 0 */)
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