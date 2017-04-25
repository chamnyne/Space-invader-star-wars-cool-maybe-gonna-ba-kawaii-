/* En-tête du programme
==========================
Programme :			tp3.cpp
Acteur :            Pierre-Olivier Boucher
Date de création:	2017/04/25
Description :		Jeux dans le style d'un Space invader a thème de star wars

/* Directive au pré-processeur
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
	int posX;	// Définit la position horizontal d'un vaiseau 
	int posY;	// Définit la position verticale d'un vaiseau

};

/* Programme principale
=========================*/
int main()
{
	// Variable

	sf::RenderWindow window(sf::VideoMode(1000, 800), "DEFENDERS OF THE GALAZY");

	// on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
	while (window.isOpen()) 
	{
		
		sf::Event event;   // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed) // évènement "fermeture demandée" : on ferme la fenêtre
				window.close();
		}

		window.clear(sf::Color::Black); // Logiquement efface la fenetre

		sf::RenderTexture background;
		if (!background.create(1000, 800))
		{
			cout << " La fenetre que vous tenter de généré est disidente ! Veuillez la dompter !"; // Affiche des instruction
		}

		// Création du background

		sf::Texture texBackground;		// Texture du background
		if (!texBackground.loadFromFile("BG2.jpg"))
		{
			cout << " La fenetre que vous tenter de généré est disidente ! Veuillez la dompter !"; // Affiche des instruction
		}

		sf::Sprite sprtBackground;		// sprite du background
		sprtBackground.setTexture(texBackground);

		background.clear();
		background.draw(sprtBackground);
		background.display();

		// Récupération de la texture du background
		const sf::Texture& texture = background.getTexture();

		// on la dessine dans la fenêtre
		sf::Sprite sprite(texture);
		window.draw(sprite);

		// Création d'un vaiseau du vaiseau du joueur
		
		sf::Texture texPlayer;		// Texture du player
		if (!texBackground.loadFromFile("FM2.jpg"))
		{
			cout << " La fenetre que vous tenter de généré est disidente ! Veuillez la dompter !"; // Affiche des instruction
		}

		sf::Sprite sprtPlayer;		// sprite du player
		sprtBackground.setTexture(texBackground);

		background.clear();
		background.draw(sprtBackground);
		background.display();

		// Récupération de la texture du background
		const sf::Texture& texture = background.getTexture();

		// on la dessine dans la fenêtre
		sf::Sprite sprite(texture);
		window.draw(sprite);

		window.display(); // Affiche ce qui est dessiné
	}

	return 0;
}

/* Fonction
========================*/
