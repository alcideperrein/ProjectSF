#include "structure.h"
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

void affichage(SDL_Texture* texture, SDL_Renderer* renderer, SDL_Rect* rectangle)
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(renderer, rectangle);
    SDL_RenderPresent(renderer);
}

int main(int argc, char** argv) {
    SDL_Window* pwindow;
    SDL_Renderer* renderer;
    Uint8 const* touche;
    SDL_Event touche2;
    SDL_Rect rectangle = { 20, 500, 220, 500 };
    SDL_Surface* fond;
    SDL_Texture* texture;
    int jeu = 0;
    int saut = 0;
    int snick = 0;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_version nb;
    SDL_VERSION(&nb);

    pwindow = SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1920,
        1080,
        SDL_WINDOW_FULLSCREEN);// Cree la fenêtre de dimension 1920px par 1080px en fullscreen

    renderer = SDL_CreateRenderer(pwindow, -1, SDL_RENDERER_SOFTWARE);
    fond = SDL_LoadBMP("C:/Users/Public/SFBackground.bmp");//recupere image de fond
    texture = SDL_CreateTextureFromSurface(renderer, fond);
    SDL_FreeSurface(fond);


    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);// met a jour le 
    SDL_RenderPresent(renderer);// met a jour le renderer



    while (jeu == 0)
    {
        touche = SDL_GetKeyboardState(NULL);


        if (touche[SDL_SCANCODE_D]) {
            if (rectangle.x < 1680)
            {
                if (snick == 0) {
                    rectangle.x += 2;
                }
                else {
                    rectangle.x += 1;
                }
                
            }
        }

        if (touche[SDL_SCANCODE_A] ) {

            if (rectangle.x > 20)
            {
                if (snick == 0) {
                    rectangle.x -= 2;
                }
                else {
                    rectangle.x -= 1;
                }
                
            }

        }

        if ((touche[SDL_SCANCODE_S]) && (saut == 0)) {
            rectangle.y = 750;
            rectangle.h = 250;
            snick = 1;
        }
        if ((touche[SDL_SCANCODE_W]) && (saut == 0) && (snick == 0))
        {
            if (rectangle.y > 150) {
                saut = 1;
            }
            else {
                saut = 2;
            }

        }


        if (saut == 1) {
            if (rectangle.y < 150) {
                saut = 2;
            }
            rectangle.y -= 2;
        }
        if (saut == 2) {
            if (rectangle.y < 500) {
                rectangle.y += 2;
            }
            else if (rectangle.y == 500) {
                saut = 0;
            }
        }


        if ((touche[SDL_SCANCODE_S] == 0) && (snick == 1) && (saut == 0)) {
            rectangle.y = 500;
            rectangle.h = 500;
            snick = 0;
        }
        affichage(texture, renderer, &rectangle);


        SDL_PollEvent(&touche2);// Récupération des actions de l'utilisateur
        switch (touche2.type)
        {
        case SDL_KEYUP:
            switch (touche2.key.keysym.sym)
            {
            case SDLK_ESCAPE:// Regarde si == touche ESC
                SDL_DestroyTexture(texture);// detruit la texture
                SDL_DestroyRenderer(renderer);// detruit le rendu
                SDL_DestroyWindow(pwindow); // Detruit la fenetre
                jeu = 1;
                break;

            }
            break;
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


/*

difficulté :


*/


/*
/*case SDLK_s:
                    rectangle.y = 500;
                    rectangle.h = 500;
                    temps = 1;
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                    SDL_RenderClear(renderer);
                    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
                    SDL_RenderDrawRect(renderer, &rectangle);
                    SDL_RenderPresent(renderer);
                    break;


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
