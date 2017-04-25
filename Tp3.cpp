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
	int posX;			// Définit la position horizontal d'un vaiseau 
	int posY;			// Définit la position verticale d'un vaiseau

	sf::Texture img;	// Définit l'image d'un vaiseau
};

/* Protocole
=========================*/

/* Programme principale
=========================*/
int main()
{
	// Cération de la fenêtre
	sf::RenderWindow window(sf::VideoMode(1000, 800), "DEFENDERS OF THE GALAZY");
	
	// Variable

	sf::Event event;				// Evenement de la fenetre			

	sf::RenderTexture background;	// RenderTexture du background
	background.create(1000, 800);
	sf::RenderTexture player;		// RenderTexture du player
	player.create(100, 100);
	
	sf::Texture texBackground;		// Texture du background
	texBackground.loadFromFile("img/BG2.jpg");	
	sf::Texture texPlayer;			// Texture du joueur -> Going to be in class
	texPlayer.loadFromFile("img/FM4.png");

	sf::Sprite sprtBackground;		// Sprite du background
	sprtBackground.setTexture(texBackground);
	sf::Sprite sprtPlayer;			// Sprite du player
	sprtPlayer.setTexture(texPlayer);

	// on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
	while (window.isOpen()) 
	{
		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed) // évènement "fermeture demandée" : on ferme la fenêtre
				window.close();
		}
		
		// Efface la fenetre
		window.clear(sf::Color::Black); 
		
		background.clear();
		player.clear();
		background.draw(sprtBackground);
		player.draw(sprtPlayer);
		background.display();
		player.display();
		
		// Dessine dans la fenêtre
		window.draw(sprtBackground);	
		window.draw(sprtPlayer);
		
		// Affiche ce qui est dessiné
		window.display();
	}

	return 0;
}

/* Fonction
========================*/