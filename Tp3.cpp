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
using namespace sf;

/* Classe
=========================*/
class ships
{
private:
	int _posX;							// D�finit la position horizontal d'un vaiseau 
	int _posY;							// D�finit la position verticale d'un vaiseau

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
	// C�ration de la fen�tre
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

	// on fait tourner le programme jusqu'� ce que la fen�tre soit ferm�e
	while (window.isOpen()) 
	{
		// on inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente it�ration
		while (window.pollEvent(event))
		{
			
			if (event.type == Event::Closed) // �v�nement "fermeture demand�e" : on ferme la fen�tre
				window.close();
		}
		
		// Efface la fenetre
		window.clear(Color::Black); 
		
		background.clear();
		background.draw(sprtBackground);
		background.display();

		// Dessine dans la fen�tre
		window.draw(sprtBackground);
		player.afficher(window);
		
		// Affiche ce qui est dessin�
		window.display();
	}

	return 0;
}

/* Fonction
========================*/