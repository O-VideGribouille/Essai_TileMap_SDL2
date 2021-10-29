#include "CGame.h"
#include "CTextureManager.h"

//#include "CPlayer.h"


using namespace std;



CGame::CGame()
{
	this->m_pWindow = 0;
	this->m_pRenderer = 0;

	this->m_CurrentFrame = 0; // pour l'animation d'un sprite

	//this->m_ptexture = 0;
	//this->m_sourceRect = 0;
	//this->m_destinationRect = 0;

	this->m_bRunning = true;
}

CGame::CGame(SDL_Window* m_pWindow, SDL_Renderer* m_pRenderer, int m_CurrentFrame, bool m_bRunning, SDL_Texture* m_pTexture, SDL_Rect m_sourceRect, SDL_Rect m_destinationRect)
{
	this->m_pWindow = m_pWindow;
	this->m_pRenderer = m_pRenderer;

	this->m_CurrentFrame = m_CurrentFrame;

	//this->m_ptexture = m_pTexture;




	this->m_bRunning = m_bRunning;


}


CGame ::~CGame()
{
}



//INITIALISATION
bool CGame::init(const char* chr_title, int n_x, int n_y, int n_h, int n_w, int n_flags) {

	//Initialisation SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		cout << "SDl Init Succes \n";

		//Inititalisation de la fenetre;
		m_pWindow = SDL_CreateWindow(chr_title, n_x, n_y, n_w, n_h, n_flags);

		if (m_pWindow != 0) { //Créer car Init Successs

			cout << "window creation success\n";

			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0) {
				cout << "renderer creation success\n";

				//Couleur Background
				SDL_SetRenderDrawColor(m_pRenderer, 0, 27, 27, 27);

				ifstream stream_minMap;

				m_ptexture.load("./Sprite/TileMap.bmp", "TileMap", m_pRenderer);

				stream_minMap.open("./Sprite/Tile_lvl_floor.txt");

				for (int i = 0; i < NOMBRE_BLOCS_H; i++) {
					for (int j = 0; j < NOMBRE_BLOCS_W; j++) {
						
						stream_minMap >> t_tab[i][j];
						
					}
				}

				stream_minMap.close();

				ifstream stream_minMap2;

				m_ptexture.load("./Sprite/TileMap.bmp", "TileDec", m_pRenderer);

				stream_minMap.open("./Sprite/Tile_lvl_deco.txt");

				for (int i = 0; i < NOMBRE_BLOCS_H; i++) {
					for (int j = 0; j < NOMBRE_BLOCS_W; j++) {

						stream_minMap >> t_tabDeco[i][j];

					}
				}

				stream_minMap2.close();


			}
			else
			{
				cout << "renderer init fail\n";
				return false; // L'inititalisation à échoué
			}
		}
		else
		{
			cout << "window init fail\n";
			return false; // Echec Init de la fenetre
		}
	}

	else
	{
		cout << "SDL init fail\n";
		return false; //Echec initialisation SDL
	}


	cout << "init success\n";
	m_bRunning = true; // Tout est ok et s'initialise


	return true;
}


//HANDLEEVENT
void CGame::handleEvents()
{

	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{

		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}



//UPDATE
void CGame::update()
{

	m_CurrentFrame = int(((SDL_GetTicks() / 100) % 6)); // animation Sprite


}



//AFFICHAGE
void CGame::render()
{
	SDL_RenderClear(m_pRenderer); //Effacer le Render DRAW COLORS

	m_ptexture.draw("Table", 0, 0, 32, 32, m_pRenderer);
	//SDL_RenderCopy(m_pRenderer, m_pTexture2, &m_sourceRect2, &m_destinationRect2);

	for (int i = 0; i < NOMBRE_BLOCS_H; i++) {
		for (int j = 0; j < NOMBRE_BLOCS_W; j++) {

			m_ptexture.drawTile("TileMap", j* T_W, i* T_H, T_W, T_H, t_tab[i][j],  m_pRenderer, SDL_FLIP_NONE);

		}
	}

	for (int i = 0; i < NOMBRE_BLOCS_H; i++) {
		for (int j = 0; j < NOMBRE_BLOCS_W; j++) {

			m_ptexture.drawTile("TileDec", j * T_W, i * T_H, T_W, T_H, t_tabDeco[i][j], m_pRenderer, SDL_FLIP_NONE);

		}
	}

	SDL_RenderPresent(m_pRenderer); // Met en place les dessins sur l'écran

}





//LIBERATION MEMOIRE
void CGame::clean()
{

	cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow); // Détruit la fenêtre
	SDL_DestroyRenderer(m_pRenderer); // Détruit le Renderer
	SDL_Quit();

}
