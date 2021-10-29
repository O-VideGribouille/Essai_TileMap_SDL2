#pragma once
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

#include<map>

//AJOUT INCLUDE


using namespace std;

class CTextureManager {




public:



	CTextureManager();
	~CTextureManager();

	bool load(string strg_fileName, string strg_id, SDL_Renderer* pRenderer);
	//fonction DRAW
	void draw(string strg_id, int n_x, int n_y, int n_w, int n_h, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);//avec flip
	
	void drawTile(string strg_id, int n_x, int n_y, int n_w, int n_h, int num_cell, SDL_Renderer* pRenderer, SDL_RendererFlip flip);

	//Fonction DrawFrame
	//void drawFrame(string strg_id, int n_x, int n_y, int n_w, int n_h, int n_currentRow, int n_CurrentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);




private:

	map<string, SDL_Texture*> m_textureMap;


};