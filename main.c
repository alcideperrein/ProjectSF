

#include "structure.h"
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

void gauche(Coordonees* point)
{
    (*point).x = 1;
    (*point).y = 0;
}

void droit(Coordonees* point)
{
    (*point).x = 0;
    (*point).y = 0;
}

void bas(Coordonees* point)
{
    (*point).x = 0;
    (*point).y = 0;
}

void haut(Coordonees* point)
{
    (*point).x = 0;
    (*point).y = 0;
}

int main(int argc, char **argv) {
    Coordonees point;
    SDL_Window* pwindow;
    SDL_Event touche;
    int jeu = 0;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_version nb;
    SDL_VERSION(&nb);

    point.x = 0;
    point.y = 0;
    point.h = 30;
    point.w = 10;

    pwindow=SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1920,
        1080,
        SDL_WINDOW_FULLSCREEN);// Cree la fenêtre de dimension 1920px par 1080px en fullscreen

    while (jeu==0) 
    {
        SDL_PollEvent(&touche);// Récupération des actions de l'utilisateur
        switch (touche.type)
        {
            case SDL_KEYUP:
                if (touche.key.keysym.sym == SDLK_ESCAPE)// Regarde si == touche ESC
                {
                    SDL_DestroyWindow(pwindow); // Detruit la fenetre
                    jeu = 1;
                }break;
        }
    }


    

    printf("bienvenue sur la sdl %d.%d.%d !\n", nb.major, nb.minor, nb.patch);
    gauche(&point);
    printf("%d", point.x);


    SDL_Quit();
    return 0;
}



