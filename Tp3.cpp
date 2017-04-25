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
	int posX;			// D�finit la position horizontal d'un vaiseau 
	int posY;			// D�finit la position verticale d'un vaiseau

	sf::Texture img;	// D�finit l'image d'un vaiseau
};

/* Protocole
=========================*/

/* Programme principale
=========================*/
int main()
{
	// C�ration de la fen�tre
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

	// on fait tourner le programme jusqu'� ce que la fen�tre soit ferm�e
	while (window.isOpen()) 
	{
		// on inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente it�ration
		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed) // �v�nement "fermeture demand�e" : on ferme la fen�tre
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
		
		// Dessine dans la fen�tre
		window.draw(sprtBackground);	
		window.draw(sprtPlayer);
		
		// Affiche ce qui est dessin�
		window.display();
	}

	return 0;
}

/* Fonction
========================*/