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
using namespace sf;

/* Classe
=========================*/
class ships
{
private:
	int _posX;							// Définit la position horizontal d'un vaiseau 
	int _posY;							// Définit la position verticale d'un vaiseau

	RenderTexture _renderTexture;	// Espace d'un vaiseau
	
	Texture _texture;				// Image d'un vaiseau

	Sprite _sprite;					// Sprite d'un vaiseau

public:

	void init(int x, int y,string img)
	{
		_renderTexture.create(x, y);
		_texture.loadFromFile(img);
		_sprite.setTexture(_texture);
	}

	void afficher(RenderWindow &window)
	{
		_renderTexture.clear();
		_renderTexture.draw(_sprite);
		_renderTexture.display();
	
		window.draw(_sprite);
	}

	void setX(int x)
	{
		// array largeur fenetre
		x = _posX;
	}

	void setY(int y)
	{
		// array grandeur fenetre
		y = _posY;
	}

	int getX()
	{
		return _posX;
	}

	int getY()
	{
		return _posY;
	}

	void initPosition(int x, int y)
	{
		setX(x);
		setY(y);

		_sprite.setPosition(x, y);
	}
};


/* Programme principale
=========================*/
int main()
{
	// Cération de la fenêtre
	RenderWindow window(VideoMode(1000, 800), "DEFENDERS OF THE GALAZY");
	
	// Variable

	Event event;				// Evenement de la fenetre			

	ships player;				// Vaiseau du joueur
	player.init(100, 100, "img/FM4.png");
	
	RenderTexture background;	// RenderTexture du background
	background.create(1000, 800);
	
	Texture texBackground;		// Texture du background
	texBackground.loadFromFile("img/BG2.jpg");	

	Sprite sprtBackground;		// Sprite du background
	sprtBackground.setTexture(texBackground);

	// on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
	while (window.isOpen()) 
	{
		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		while (window.pollEvent(event))
		{
			
			if (event.type == Event::Closed) // évènement "fermeture demandée" : on ferme la fenêtre
				window.close();
		}
		
		// Efface la fenetre
		window.clear(Color::Black); 
		
		background.clear();
		background.draw(sprtBackground);
		background.display();

		// Dessine dans la fenêtre
		window.draw(sprtBackground);
		player.afficher(window);
		
		// Affiche ce qui est dessiné
		window.display();
	}

	return 0;
}

/* Fonction
========================*/