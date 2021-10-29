#pragma once
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

#include <fstream> // lire les fichiers textes

#include "CTextureManager.h"

using namespace std;


#define T_H  32 // hauteurs et largeur des tuiles
#define T_W  32

#define NOMBRE_BLOCS_W 23 //nombre a afficher en x et y
#define NOMBRE_BLOCS_H 20


#ifndef __Game__
#define __Game__



class CGame {
public:
	CGame();
	CGame(SDL_Window* m_pWindow, SDL_Renderer* m_pRenderer, int m_CurrentFrame, bool m_bRunning, SDL_Texture* m_pTexture, SDL_Rect m_sourceRect, SDL_Rect m_destinationRect);
	~CGame();
	//INITIALISATION
	bool init(const char* chr_title, int n_x, int n_y, int n_h, int n_w, int n_flags);

	//AFFICHAGE
	void render();

	//UPDATE
	void update();

	//HANDLEEVENT
	void handleEvents();

	//LIBERATION MEMOIRE
	void clean();

	bool running() { return m_bRunning; }




private:

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	int m_CurrentFrame; // pour l'animation d'un sprite
	CTextureManager m_ptexture;

	

	//Tableaux

	int t_tab[640/T_H][736/T_W];

	int t_tabDeco[640 / T_H][736 / T_W];


	bool m_bRunning;

};


#endif // !__Game__
