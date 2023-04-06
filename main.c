

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
    SDL_Window* pwindow;
    SDL_Renderer* renderer;
    Uint8 const* touche;
    SDL_Event touche2;
    SDL_Rect rectangle;
    int jeu = 0;
    int temps = 1;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_version nb;
    SDL_VERSION(&nb);

    pwindow=SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1920,
        1080,
        SDL_WINDOW_FULLSCREEN);// Cree la fenêtre de dimension 1920px par 1080px en fullscreen

    renderer = SDL_CreateRenderer(pwindow, -1, SDL_RENDERER_SOFTWARE);

    rectangle.x = 20;
    rectangle.y = 500;
    rectangle.h = 500;
    rectangle.w = 220;
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(renderer,&rectangle);
    SDL_RenderPresent(renderer);

    
    while (jeu==0) 
    {
        touche = SDL_GetKeyboardState(NULL);

        if (touche[SDL_SCANCODE_D] && touche[SDL_SCANCODE_S]==0) {
            if (rectangle.x < 1680)
            {
                rectangle.x += 1;
            }
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawRect(renderer, &rectangle);
            SDL_RenderPresent(renderer);
        }
        if (touche[SDL_SCANCODE_A] && touche[SDL_SCANCODE_S]==0) {

                if (rectangle.x > 20)
                {
                    rectangle.x -= 1;
                }
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderDrawRect(renderer, &rectangle);
                SDL_RenderPresent(renderer);
            }
        if (touche[SDL_SCANCODE_S]) {
            rectangle.y = 750;
            rectangle.h = 250;
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawRect(renderer, &rectangle);
            SDL_RenderPresent(renderer);
        }

        if (touche[SDL_SCANCODE_S]==0) {
            rectangle.y = 500;
            rectangle.h = 500;
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawRect(renderer, &rectangle);
            SDL_RenderPresent(renderer);
        }


       SDL_PollEvent(&touche2);// Récupération des actions de l'utilisateur
        switch (touche2.type)
        {
            case SDL_KEYUP:
                switch (touche2.key.keysym.sym)
                { 
                    case SDLK_ESCAPE:// Regarde si == touche ESC
                        SDL_DestroyRenderer(renderer);
                        SDL_DestroyWindow(pwindow); // Detruit la fenetre
                        jeu = 1;
                        break;

                    /*case SDLK_s:
                        rectangle.y = 500;
                        rectangle.h = 500;
                        temps = 1;
                        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                        SDL_RenderClear(renderer);
                        SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
                        SDL_RenderDrawRect(renderer, &rectangle);
                        SDL_RenderPresent(renderer);
                        break;*/

                }
                break;
                /*

            case SDL_KEYDOWN:
                switch (touche.key.keysym.sym)
                {
                    case SDLK_d:
                        if (rectangle.x < 1680 && temps == 1)
                        {
                            rectangle.x += 20;
                        }
                        else if (rectangle.x < 1680 && temps == 0)
                        {
                            rectangle.x += 5;
                        }
                        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                        SDL_RenderClear(renderer);
                        SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
                        SDL_RenderDrawRect(renderer, &rectangle);
                        SDL_RenderPresent(renderer);
                        break;

                    case SDLK_q:
                       if (rectangle.x > 20 && temps==1)
                        {
                            rectangle.x -= 20;
                        }
                       else if (rectangle.x > 20 && temps == 0)
                       {
                           rectangle.x -= 5;
                       }
                        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                        SDL_RenderClear(renderer);
                        SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
                        SDL_RenderDrawRect(renderer, &rectangle);
                        SDL_RenderPresent(renderer);
                        break;


                    case SDLK_s:
                        rectangle.y = 750;
                        rectangle.h = 250;
                        temps = 0;
                        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                        SDL_RenderClear(renderer);
                        SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
                        SDL_RenderDrawRect(renderer, &rectangle);
                        SDL_RenderPresent(renderer);
                        break;

                        
                }*/
        } 
    }
    

    //printf("bienvenue sur la sdl %d.%d.%d !\n", nb.major, nb.minor, nb.patch);



    SDL_Quit();
    return 0;
}



/* modifier pour les touches 
liens:
https://wiki.libsdl.org/SDL2/SDL_GetKeyboardState
https://wiki.libsdl.org/SDL2/SDL_Scancode
*/