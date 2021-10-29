#include "CTextureManager.h"
#include "CGame.h"

CTextureManager::CTextureManager()
{
}


CTextureManager::~CTextureManager()
{
}

bool CTextureManager::load(string strg_fileName, string strg_id, SDL_Renderer* pRenderer)
{
	SDL_Surface* pTempSurface = SDL_LoadBMP(strg_fileName.c_str());

	if (pTempSurface == 0) {
		return false;
	}

	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);// Nouvelles textures

	SDL_FreeSurface(pTempSurface);

	//Quand tout est ok, ajouter la texture dans la liste
	if (pTempSurface != 0) {
		m_textureMap[strg_id] = pTexture;
		return true;
	}

	//recherche quelque chose de faux
	return false;
}

void CTextureManager::draw(string strg_id, int n_x, int n_y, int n_w, int n_h, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect; // le premier rectangle
	SDL_Rect destRect;//les autres rectangles

	//deplace l'interieur de l'image
	srcRect.x = 0;
	srcRect.y = 0;

	//Taille de l'image interne du TileMap
	//srcRect.w = destRect.w = n_w;
	//srcRect.h = destRect.h = n_h;

	srcRect.w = n_w;
	srcRect.h = n_h;


	//deplace l'image selectionner
	destRect.x = n_x;
	destRect.y = n_y;

	//Taille du sprite final
	destRect.w = n_w;
	destRect.h = n_h;

	SDL_RenderCopyEx(pRenderer, m_textureMap[strg_id], NULL, &destRect, 0, 0, flip);

}


void CTextureManager::drawTile(string strg_id, int n_x, int n_y, int n_w, int n_h, int num_cell, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect; // le premier rectangle
	SDL_Rect destRect;//les autres rectangles

	//deplace l'interieur de l'image
	srcRect.x = num_cell % 8 * T_W;
	srcRect.y = num_cell / 8 * T_H;

	//Taille de l'image interne du TileMap
	srcRect.w = n_w;
	srcRect.h = n_h;


	//deplace l'image selectionner
	destRect.x = n_x;
	destRect.y = n_y;

	//Taille du sprite final
	destRect.w = n_w;
	destRect.h = n_h;

	SDL_RenderCopyEx(pRenderer, m_textureMap[strg_id], &srcRect, &destRect, 0, 0, flip);

}
