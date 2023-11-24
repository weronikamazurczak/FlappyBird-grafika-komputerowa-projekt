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
	* @brief Klasa reprezentuj¹ca obiekt gry.
	*/
	class GameObject {
	public:
		/**
		* @brief Ustawia wartoœæ x pozycji obiektu.
		* @param x Wartoœæ x do ustawienia.
		*/
		void setX(float x);
		/**
		* @brief Ustawia wartoœæ y pozycji obiektu.
		* @param y Wartoœæ y do ustawienia.
		*/
		void setY(float y);
		/**
		* @brief Pobiera wartoœæ x pozycji obiektu.
		* @return Wartoœæ x pozycji obiektu.
		*/
		float getX();
		/**
		* @brief Pobiera wartoœæ y pozycji obiektu.
		* @return Wartoœæ y pozycji obiektu.
		*/
		float getY();
	private:
		sf::Vector2f actualPosition;
	};

	/**
	* @brief Klasa reprezentuj¹ca obiekt, który mo¿na narysowaæ.
	*/
	class DrawableObject : public virtual GameObject {
	public:
		/**
		* @brief Rysuje obiekt.
		*/
		void draw(void);
	};

	/**
	* @brief Klasa reprezentuj¹ca obiekt, który mo¿na przekszta³ciæ.
	*/
	class TransformableObject : public virtual GameObject {
	public:
		/**
		* @brief Przesuwa obiekt o dan¹ pozycjê.
		* @param position Pozycja, o któr¹ obiekt ma byæ przesuniêty.
		*/
		void translate(sf::Vector2f position);
		/**
		* @brief Obraca obiekt o dany k¹t.
		* @param angle K¹t, o który obiekt ma byæ obrócony.
		*/
		void rotate(float angle);
		/**
		* @brief Skaluje obiekt o dan¹ skalê.
		* @param scale Skala, o któr¹ obiekt ma byæ przeskalowany.
		*/
		void scale(sf::Vector2f scale);
	};

	/**
	* @brief Klasa reprezentuj¹ca obiekt kszta³tu, który mo¿na narysowaæ i przekszta³ciæ.
	*/
	class ShapeObject : public DrawableObject, TransformableObject {
	public:
		virtual void draw() {};
		virtual void translate(sf::Vector2f position) {};
		virtual void rotate(float angle) {};
		virtual void scale(sf::Vector2f scale) {};
	};

	/**
	* @brief Klasa reprezentuj¹ca okr¹g.
	*/
	class Circle : public ShapeObject {
	public:
		/**
		* @brief Konstruktor klasy Circle. Inicjalizuje okr¹g o podanym promieniu.
		* @param radius Promieñ okrêgu.
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



