#include "structure.h"
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

void affichage(SDL_Texture* texture, SDL_Renderer* renderer, SDL_Rect* rectangle, SDL_Rect* rectangleCoup, int* pcoup, SDL_Rect* rectanglePunchingBall)// est définie pour dessiner les éléments du jeu sur la fenêtre. Elle prend en paramètre la texture à afficher, le renderer, les rectangles de base et de coup, et le coup choisit.
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(renderer, rectangle);
    SDL_RenderDrawRect(renderer, rectanglePunchingBall);
    if (*pcoup != 0) {
        SDL_RenderDrawRect(renderer, rectangleCoup);
    }
    SDL_RenderPresent(renderer);
}

int main(int argc, char** argv) {
    SDL_Window* pwindow;
    SDL_Renderer* renderer;
    Uint8 const* touche;
    SDL_Event touche2;
    SDL_Rect rectangle = { 20, 500, 220, 500 };
    SDL_Rect rectangleCoup = { 0, 0, 0, 100 };
    SDL_Rect rectanglePunchingBall = { 1600, 500, 220, 500 };
    SDL_Rect source = { 0,0,24,38 };
    SDL_Surface* sprites;
    SDL_Surface* fond;
    SDL_Texture* perso1;
    SDL_Texture* texture;
    int jeu = 0;
    int saut = 0;
    int snick = 0;
    int coup = 0;
    int retour = 0;
    int coupLent = 0;


    int side = 1;

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

    sprites = SDL_LoadBMP("C:/Users/Public/imageonline-co-transparentimage.bmp");
    perso1 = SDL_CreateTextureFromSurface(renderer, sprites);
    SDL_FreeSurface(sprites);


    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderCopy(renderer, perso1, NULL, NULL);
    SDL_RenderPresent(renderer);// met a jour le renderer



    while (jeu == 0)
    {
        touche = SDL_GetKeyboardState(NULL); // récupérer l'état des touches du clavier


        if (touche[SDL_SCANCODE_D] && (coup == 0) && snick == 0) {
            if (rectangle.x < 1680)
            {
                if (snick == 0) {
                    rectangle.x += 2;
                }
                else {
                    rectangle.x += 1;
                }
                side = 1;
            }
            source.x += 15;
            if (rectangle.x > 1500) {
                side = 0;
            }
        }

        if (touche[SDL_SCANCODE_A] && (coup == 0) && snick == 0) {

            if (rectangle.x > 20)
            {
                if (snick == 0) {
                    rectangle.x -= 2;
                }
                else {
                    rectangle.x -= 1;
                }
                side = 2;
            }
            if (rectangle.x < 200) {
                side = 0;
            }

        }

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
        affichage(texture, renderer, &rectangle, &rectangleCoup, &coup, &rectanglePunchingBall);
    }



    SDL_Quit();
    return 0;
}
