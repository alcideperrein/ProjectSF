

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
    SDL_Renderer* renderer;
    SDL_Event touche;
    SDL_Rect rectangle;
    int jeu = 0;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_version nb;
    SDL_VERSION(&nb);

    pwindow=SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1920,
        1080,
        SDL_WINDOW_FULLSCREEN);// Cree la fenêtre de dimension 1920px par 1080px en fullscreen

    renderer = SDL_CreateRenderer(pwindow, -1, SDL_RENDERER_SOFTWARE);

    rectangle.x =20;
    rectangle.y = 500;
    rectangle.h = 480;
    rectangle.w = 220;
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(renderer,&rectangle);
    SDL_RenderPresent(renderer);

    
    while (jeu==0) 
    {
        SDL_PollEvent(&touche);// Récupération des actions de l'utilisateur
        switch (touche.type)
        {
            case SDL_KEYUP:
                if (touche.key.keysym.sym == SDLK_ESCAPE)// Regarde si == touche ESC
                {
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyWindow(pwindow); // Detruit la fenetre
                    jeu = 1;
                }
                break;
            case SDL_KEYDOWN:
                if (touche.key.keysym.sym == SDLK_d)
                {
                    if (rectangle.x < 1680)
                    {
                        rectangle.x += 20;
                    }
                    SDL_RenderDrawRect(renderer, &rectangle);
                    SDL_RenderPresent(renderer);
                }
                else if (touche.key.keysym.sym == SDLK_q)
                {
                    if (rectangle.x > 20)
                    {
                        rectangle.x -= 20;
                    }
                    SDL_RenderDrawRect(renderer, &rectangle);
                    SDL_RenderPresent(renderer);
                }
        }
    }


    

    printf("bienvenue sur la sdl %d.%d.%d !\n", nb.major, nb.minor, nb.patch);



    SDL_Quit();
    return 0;
}



