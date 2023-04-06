

#include "structure.h"
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>




int main(int argc, char **argv) {
    SDL_Window* pwindow;
    SDL_Renderer* renderer;
    Uint8 const* touche;
    SDL_Event touche2;
    SDL_Rect rectangle;
    int jeu = 0;
    int temps = 1;
    int saut=0;
    int snick = 0;

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
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);// choisis la coucleur 
    SDL_RenderDrawRect(renderer,&rectangle);// fait un rectangle
    SDL_RenderPresent(renderer);// met a jour le renderer

    
    while (jeu==0) 
    {
        touche = SDL_GetKeyboardState(NULL);

        if (touche[SDL_SCANCODE_D] && (snick == 0)) {
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
        if (touche[SDL_SCANCODE_A] && (snick==0)) {

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
        if ((touche[SDL_SCANCODE_S]) && (saut==0)) {
            rectangle.y = 750;
            rectangle.h = 250;
            snick = 1;
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawRect(renderer, &rectangle);
            SDL_RenderPresent(renderer);
        }
        if ((touche[SDL_SCANCODE_W])&&(saut==0))
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
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawRect(renderer, &rectangle);
            SDL_RenderPresent(renderer);
        }
        if (saut == 2) {
            if (rectangle.y < 500) {
                rectangle.y += 2;
            }
            else if (rectangle.y == 500) {
                saut = 0;
            }
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawRect(renderer, &rectangle);
            SDL_RenderPresent(renderer);
        }

        if ((touche[SDL_SCANCODE_S]==0) && (snick==1) && (saut==0)) {
            rectangle.y = 500;
            rectangle.h = 500;
            snick = 0;
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