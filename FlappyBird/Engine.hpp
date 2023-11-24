#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "MenuGry.hpp";

using namespace std;

class Engine
{
public:
	void ustawRozdzielczosc(int, int);
	void inneParametry(sf::RenderWindow*);
	void petlaGry();
	void czyszczenieOkna(sf::RenderWindow*, sf::Color);
	void czyszczenieBitmapy(sf::Sprite*, sf::Color);
	void zapisywanieDoPliku(string);


	class GameObject {
	public:
		void setX(float x);
		void setY(float y);
		float getX();
		float getY();
	private:
		sf::Vector2f actualPosition;
	};

	class DrawableObject : public virtual GameObject {
	public:
		void draw(void);
	};

	class TransformableObject : public virtual GameObject {
	public:
		void translate(sf::Vector2f position);
		void rotate(float angle);
		void scale(sf::Vector2f scale);
	};

	class ShapeObject : public DrawableObject, TransformableObject {
	public:
		virtual void draw() {};
		virtual void translate(sf::Vector2f position) {};
		virtual void rotate(float angle) {};
		virtual void scale(sf::Vector2f scale) {};
	};


	class Circle : public ShapeObject {
	public:
		Circle(float radius);
		virtual void draw();
		virtual void translate(sf::Vector2f position);
		virtual void rotate(float angle);
		virtual void scale(sf::Vector2f scale);
		sf::CircleShape circle;
	};

	class PrimitiveRenderer {
	public:
		void rysujOkrag(float radius, sf::Vector2f position, sf::Color color);
		//void rysujSymetrycznyOkrag(float radius, sf::Color color);
	};


private:
	int szerokosc, wysokosc;
	MenuGry menu; 
};



