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

	/**
	* @brief Klasa reprezentuj�ca obiekt gry.
	*/
	class GameObject {
	public:
		/**
		* @brief Ustawia warto�� x pozycji obiektu.
		* @param x Warto�� x do ustawienia.
		*/
		void setX(float x);
		/**
		* @brief Ustawia warto�� y pozycji obiektu.
		* @param y Warto�� y do ustawienia.
		*/
		void setY(float y);
		/**
		* @brief Pobiera warto�� x pozycji obiektu.
		* @return Warto�� x pozycji obiektu.
		*/
		float getX();
		/**
		* @brief Pobiera warto�� y pozycji obiektu.
		* @return Warto�� y pozycji obiektu.
		*/
		float getY();
	private:
		sf::Vector2f actualPosition;
	};

	/**
	* @brief Klasa reprezentuj�ca obiekt, kt�ry mo�na narysowa�.
	*/
	class DrawableObject : public virtual GameObject {
	public:
		/**
		* @brief Rysuje obiekt.
		*/
		void draw(void);
	};

	/**
	* @brief Klasa reprezentuj�ca obiekt, kt�ry mo�na przekszta�ci�.
	*/
	class TransformableObject : public virtual GameObject {
	public:
		/**
		* @brief Przesuwa obiekt o dan� pozycj�.
		* @param position Pozycja, o kt�r� obiekt ma by� przesuni�ty.
		*/
		void translate(sf::Vector2f position);
		/**
		* @brief Obraca obiekt o dany k�t.
		* @param angle K�t, o kt�ry obiekt ma by� obr�cony.
		*/
		void rotate(float angle);
		/**
		* @brief Skaluje obiekt o dan� skal�.
		* @param scale Skala, o kt�r� obiekt ma by� przeskalowany.
		*/
		void scale(sf::Vector2f scale);
	};

	/**
	* @brief Klasa reprezentuj�ca obiekt kszta�tu, kt�ry mo�na narysowa� i przekszta�ci�.
	*/
	class ShapeObject : public DrawableObject, TransformableObject {
	public:
		virtual void draw() {};
		virtual void translate(sf::Vector2f position) {};
		virtual void rotate(float angle) {};
		virtual void scale(sf::Vector2f scale) {};
	};

	/**
	* @brief Klasa reprezentuj�ca okr�g.
	*/
	class Circle : public ShapeObject {
	public:
		/**
		* @brief Konstruktor klasy Circle. Inicjalizuje okr�g o podanym promieniu.
		* @param radius Promie� okr�gu.
		*/
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



