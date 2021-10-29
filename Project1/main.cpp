#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>



#include "CGame.h"

using namespace std;


CGame* g_game = 0;

int main(int argc, char* argv[]) {



   g_game = new CGame();

    g_game->init("Casse Briques", 400, 100, 640, 736, 0);


    while (g_game->running())
    {
        //HANDLEEVENTS
        g_game->handleEvents();
        //UPDATE
        g_game->update();

        //AFFICHAGE
        g_game->render();


        SDL_Delay(1000 / 60); //ajout d'un délais - animation
    }

    //LIBERATION MEMOIRE
    g_game->clean();
    


    return 0;
}