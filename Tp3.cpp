/* En-t�te du programme
==========================
Programme :			tp3.cpp
Acteur :            Pierre-Olivier Boucher
Date de cr�ation:	2017/04/25
Description :		Jeux dans le style d'un Space invader a th�me de star wars

/* Directive au pr�-processeur
=============================== */
#include <iostream>
#include <locale>
#include <SFML/Graphics.hpp>
using namespace std;

/* Classe
=========================*/
class ships
{
private:
	int posX;	// D�finit la position horizontal d'un vaiseau 
	int posY;	// D�finit la position verticale d'un vaiseau

};

/* Programme principale
=========================*/
int main()
{
	// Variable

	sf::RenderWindow window(sf::VideoMode(1000, 800), "DEFENDERS OF THE GALAZY");

	// on fait tourner le programme jusqu'� ce que la fen�tre soit ferm�e
	while (window.isOpen()) 
	{
		
		sf::Event event;   // on inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente it�ration
		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed) // �v�nement "fermeture demand�e" : on ferme la fen�tre
				window.close();
		}

		window.clear(sf::Color::Black); // Logiquement efface la fenetre

		sf::RenderTexture background;
		if (!background.create(1000, 800))
		{
			cout << " La fenetre que vous tenter de g�n�r� est disidente ! Veuillez la dompter !"; // Affiche des instruction
		}

		// Cr�ation du background

		sf::Texture texBackground;		// Texture du background
		if (!texBackground.loadFromFile("BG2.jpg"))
		{
			cout << " La fenetre que vous tenter de g�n�r� est disidente ! Veuillez la dompter !"; // Affiche des instruction
		}

		sf::Sprite sprtBackground;		// sprite du background
		sprtBackground.setTexture(texBackground);

		background.clear();
		background.draw(sprtBackground);
		background.display();

		// R�cup�ration de la texture du background
		const sf::Texture& texture = background.getTexture();

		// on la dessine dans la fen�tre
		sf::Sprite sprite(texture);
		window.draw(sprite);

		// Cr�ation d'un vaiseau du vaiseau du joueur
		
		sf::Texture texPlayer;		// Texture du player
		if (!texBackground.loadFromFile("FM2.jpg"))
		{
			cout << " La fenetre que vous tenter de g�n�r� est disidente ! Veuillez la dompter !"; // Affiche des instruction
		}

		sf::Sprite sprtPlayer;		// sprite du player
		sprtBackground.setTexture(texBackground);

		background.clear();
		background.draw(sprtBackground);
		background.display();

		// R�cup�ration de la texture du background
		const sf::Texture& texture = background.getTexture();

		// on la dessine dans la fen�tre
		sf::Sprite sprite(texture);
		window.draw(sprite);

		window.display(); // Affiche ce qui est dessin�
	}

	return 0;
}

/* Fonction
========================*/
