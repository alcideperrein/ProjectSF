#include "structure.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

void affichage(SDL_Texture* texture, SDL_Texture* textureSprite, SDL_Texture* textureSpriteDebout2, SDL_Texture* avancer1, SDL_Texture* avancer2, SDL_Texture* avancer3, SDL_Texture* avancer4, SDL_Texture* avancer5, SDL_Texture*  accroupis ,SDL_Renderer* renderer, SDL_Rect* barreDeVie, SDL_Rect* barreDeVieDroite, SDL_Rect* barreDeVieRed, SDL_Rect* barreDeVieRedDroite, SDL_Rect* rectangle, SDL_Rect* destRect1, SDL_Rect* destRect2, SDL_Rect* destRect3, SDL_Rect* rectangleCoup,int *psnick,int *pcoup, int *pcompteur,int *pavancer,int *pcompteurAvancer,SDL_Rect* rectanglePunchingBall)// est définie pour dessiner les éléments du jeu sur la fenêtre. Elle prend en paramètre la texture à afficher, le renderer, les rectangles de base et de coup, et le coup choisit.
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderCopy(renderer, texture, NULL, destRect1);
    if (*pavancer == 1 && *psnick == 0)
    {
        if (*pcompteurAvancer < 20) {
            SDL_RenderCopy(renderer, avancer1, NULL, destRect2);
            *pcompteurAvancer += 1;
        }
        else if (*pcompteurAvancer < 40) {
            SDL_RenderCopy(renderer, avancer2, NULL, destRect2);
            *pcompteurAvancer += 1;
        }
        else if (*pcompteurAvancer < 60) {
            SDL_RenderCopy(renderer, avancer3, NULL, destRect2);
            *pcompteurAvancer += 1;
        }
        else if (*pcompteurAvancer < 80) {
            SDL_RenderCopy(renderer, avancer4, NULL, destRect2);
            *pcompteurAvancer += 1;
        }
        else if (*pcompteurAvancer < 120) {
            SDL_RenderCopy(renderer, avancer5, NULL, destRect2);
            *pcompteurAvancer += 1;
            if (*pcompteurAvancer == 120) {
                *pcompteurAvancer = 0;
            }
        }
    }
    else if (*psnick == 1) {
        SDL_RenderCopy(renderer, accroupis, NULL, destRect3);
    }
    else {
        if (*pcompteur < 80) {
            SDL_RenderCopy(renderer, textureSprite, NULL, destRect2);
            *pcompteur += 1;
        }
        else {
            SDL_RenderCopy(renderer, textureSpriteDebout2, NULL, destRect2);
            *pcompteur += 1;
            if (*pcompteur == 160) {
                *pcompteur = 0;
            }
        }
    }
    
    
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(renderer, rectangle);
    SDL_RenderDrawRect(renderer, rectanglePunchingBall);
    if (*pcoup != 0) {
        SDL_RenderDrawRect(renderer, rectangleCoup);
    }
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, barreDeVieRed);
    SDL_RenderFillRect(renderer, barreDeVieRedDroite);
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, barreDeVie);
    SDL_RenderFillRect(renderer, barreDeVieDroite);
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
    SDL_Rect barreDeVie = { 80, 80, 680, 40 };
    SDL_Rect barreDeVieRed = { 80, 80, 700,40 };
    SDL_Rect barreDeVieDroite = { 1180 , 80, 680,40 };
    SDL_Rect barreDeVieRedDroite = { 1160, 80, 700,40 };
    SDL_Rect destRect1;
    SDL_Rect destRect2;
    SDL_Rect destRect3;
    SDL_Texture* texture;
    SDL_Texture* textureSprite;
    SDL_Texture* textureSpriteDebout2;
    SDL_Texture* avancer1;
    SDL_Texture* avancer2;
    SDL_Texture* avancer3;
    SDL_Texture* avancer4;
    SDL_Texture* avancer5;
    SDL_Texture* accroupis;
    int jeu = 0;
    int saut = 0;
    int snick = 0;
    int coup = 0;
    int retour=0;
    int coupLent = 0;
    int compteur = 0;
    int avancer = 0;
    int compteurAvancer = 0;
  

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
    texture = IMG_LoadTexture(renderer, "C:/Users/Public/SFBackground.bmp");
    textureSprite = IMG_LoadTexture(renderer, "C:/Users/Public/try.png");
    textureSpriteDebout2= IMG_LoadTexture(renderer, "C:/Users/Public/Debout2.png");
    avancer1= IMG_LoadTexture(renderer, "C:/Users/Public/avancer1.png");
    avancer2 = IMG_LoadTexture(renderer, "C:/Users/Public/avancer2.png");
    avancer3 = IMG_LoadTexture(renderer, "C:/Users/Public/avancer3.png");
    avancer4 = IMG_LoadTexture(renderer, "C:/Users/Public/avancer4.png");
    avancer5 = IMG_LoadTexture(renderer, "C:/Users/Public/avancer5.png");
    accroupis= IMG_LoadTexture(renderer, "C:/Users/Public/accroupis.png");

    
    destRect1.x = 0;
    destRect1.y = 0;
    destRect1.w = 1920;
    destRect1.h = 1080;


    
    destRect2.x = rectangle.x;
    destRect2.y = rectangle.y;
    destRect3.x = rectangle.x;
    destRect3.y = rectangle.y;
    SDL_QueryTexture(textureSprite, NULL, NULL, &destRect2.w, &destRect2.h);
    SDL_QueryTexture(accroupis, NULL, NULL, &destRect3.w, &destRect3.h);

    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, texture, NULL, &destRect1);
    SDL_RenderCopy(renderer, textureSprite, NULL, &destRect2);

    SDL_RenderPresent(renderer);



    while (jeu == 0)
    {

        touche = SDL_GetKeyboardState(NULL); // récupérer l'état des touches du clavier
        
        if (touche[SDL_SCANCODE_D] && (coup==0) && snick==0){
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
            if (rectangle.x > 1500) {
                side = 0;
            }
            avancer = 1;
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
            avancer = 1;

        }

        if ((touche[SDL_SCANCODE_S]) && (saut == 0) && (coup == 0)) {
            rectangle.y = 700;
            rectangle.h = 300;
            snick = 1;
        }
        if ((touche[SDL_SCANCODE_W]) && (saut == 0) && (snick == 0) && (coup==0))
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


        if ((touche[SDL_SCANCODE_S] == 0) && (snick == 1) && (saut == 0) && (coup == 0)) {
            rectangle.y = 500;
            rectangle.h = 500;
            snick = 0;
            avancer = 0;
            compteurAvancer = 0;
        }


        if (((touche[SDL_SCANCODE_C]) || (touche[SDL_SCANCODE_Q]) || (touche[SDL_SCANCODE_E]) )&& (saut==0)) {
            if (touche[SDL_SCANCODE_Q]) {
                coupLent = 1;
            }
            if (touche[SDL_SCANCODE_E]) {
                coupLent=2; // correspond a coup moyen
            }

            if ((side == 1) && (snick == 0) ) {
                coup = 1;
                side = 3;// Pour pas qu'il repasse a coup 1
            }
            if ((side == 2) && (snick == 0)) {
                coup = 3;
                side = 3; // Pour pas qu'il repasse a coup 3
            }

            if ((side == 1) && (snick == 1)) {
                coup = 5;
                side = 3; // Pour pas qu'il repasse a coup 5
            }

            if ((side == 2) && (snick == 1)) {
                coup = 7;
                side = 3; // Pour pas qu'il repasse a coup 7
            }
        }

        /*if ((touche[SDL_SCANCODE_C]) && (snick == 0) && (retour == 0)) {
            if ((side == 1) && (saut != 0)) {
                coup = 9;
                side = 3;
                
            }

            if ((side == 2) && (saut != 0)) {
                coup = 11;
                side = 3;

            }
        }*/

         

        if ((coup == 1) && (saut==0)) { // coup de poing droit
            rectangleCoup.h = 100;
            rectangleCoup.x = rectangle.x + rectangle.w;
            rectangleCoup.y =rectangle.y+ 100;
            if (rectangleCoup.w > 220) {
                coup = 2;
            }
            if (coupLent == 1) {
                rectangleCoup.w += 2;
            }
            else if (coupLent == 2) {
                rectangleCoup.w += 3;
            }
            else { 
                rectangleCoup.w += 4; 
            }

        } 
        if ((coup == 2) && (saut == 0)) { // retour coup de point gauche 
            if (coupLent == 1) {
                rectangleCoup.w -= 2;
            }
            else if (coupLent == 2) {
                rectangleCoup.w -= 3;
            }
            else {
                rectangleCoup.w -= 4;
            }
            if (rectangleCoup.w <= 0) {
                coup = 0;
                side = 1;
                coupLent = 0;
            }
        }
        if ((coup == 3) && (saut == 0)) {// coup de poing gauche
            rectangleCoup.h = 100;
            rectangleCoup.x = rectangle.x;
            rectangleCoup.y = rectangle.y + 100;
            if (rectangleCoup.w < -220) {
                coup = 4;
            }
            if (coupLent == 1) {
                rectangleCoup.w -= 2;
            }
            else if (coupLent == 2) {
                rectangleCoup.w -= 3;
            }
            
            else
            {
                rectangleCoup.w -= 4;
            }
        }

        if ((coup == 4) && (saut == 0)) { // retour coup de point gauche
            if (coupLent == 1) {
                rectangleCoup.w += 2;
            }
            else if (coupLent == 2) {
                rectangleCoup.w += 3;
            }
            else {
                rectangleCoup.w += 4;
            }
            
            if (rectangleCoup.w >= 0) {
                coup = 0;
                side = 2;
                coupLent = 0;
            }
        }

        if ((coup == 5) && (saut == 0)) {  // coup de pied bas droit
            rectangleCoup.h = 100;
            rectangleCoup.x = rectangle.x+rectangle.w;
            rectangleCoup.y = rectangle.y+100;
            if (rectangleCoup.w > 180) {
                coup = 6;
            }
            if (coupLent == 1) {
                rectangleCoup.w += 2;
            }
            else if (coupLent == 2) {
                rectangleCoup.w += 3;
            }
            else {
                rectangleCoup.w += 4;
            }
            
        }

        if ((coup == 6) && (saut == 0)) { // retour coup de pied bas 
            if (rectangleCoup.w <= 0) {
                coup = 0;
                side = 1;
                coupLent = 0;
            }
            if (coupLent == 1) {
                rectangleCoup.w -= 2;
            }
            else if (coupLent == 2) {
                rectangleCoup.w -= 3;
            }
            else {
                rectangleCoup.w -= 4;
            }
            
        }

        if ((coup == 7) && (saut == 0)) { // coup de pied bas gauche
            rectangleCoup.h = 100;
            rectangleCoup.x = rectangle.x;
            rectangleCoup.y = rectangle.y + 100;
            if (rectangleCoup.w < -180) {
                coup = 8;
            }
            if (coupLent == 1) {
                rectangleCoup.w -= 2;
            }
            else if (coupLent == 2) {
                rectangleCoup.w -= 3;
            }
            else {
                rectangleCoup.w -= 4;
            }
            

        }

        if ((coup == 8) && (saut == 0)) { // retour coup de pied bas gauche
            
            if (rectangleCoup.w >= 0) {
                coup = 0;
                side = 2;
                coupLent = 0;
            }
            if (coupLent == 1) {
                rectangleCoup.w += 2;
            }
            else if (coupLent == 2) {
                rectangleCoup.w += 3;
            }
            else {
                rectangleCoup.w += 4;
            }
            
        }


        /*if ((coup == 9)) { // coup saut
            rectangleCoup.h = 100;
            rectangleCoup.x = rectangle.x + rectangle.w;
            rectangleCoup.y = rectangle.y + 100;
            if (rectangleCoup.w >= 180) {
                coup = 10;
                retour = 1;
            }
            rectangleCoup.w += 2;

        }

        if ((coup == 10)) { // retour coup saut
            rectangleCoup.h = 100;
            rectangleCoup.x = rectangle.x + rectangle.w;
            rectangleCoup.y = rectangle.y + 100;
            rectangleCoup.w -= 2;
            if (rectangleCoup.w == 0) {
                coup = 0;
                side = 1;
                retour = 0;
            }
        }

         if ((coup == 11)) { // coup saut gauche
            rectangleCoup.h = 100;
            rectangleCoup.x = rectangle.x;
            rectangleCoup.y = rectangle.y + 100;
            if (rectangleCoup.w <= -180) {
                coup = 12;
                retour = 2;
                }
            rectangleCoup.w -= 2;

            }

        if ((coup == 12)) { // retour coup saut
            rectangleCoup.h = 100;
            rectangleCoup.x = rectangle.x;
            rectangleCoup.y = rectangle.y + 100;
            rectangleCoup.w += 2;
            if (rectangleCoup.w <= 0) {
                coup = 0;
                side = 2;
                retour = 0;
            }

        }

        */
        if ((touche[SDL_SCANCODE_D] == 0 && touche[SDL_SCANCODE_A] == 0 && saut == 0 && snick == 0)|| (touche[SDL_SCANCODE_D] && touche[SDL_SCANCODE_A]&& saut == 0 && snick == 0)) {
            avancer = 0;
            compteurAvancer = 0;
        }
        destRect2.x = rectangle.x;
        destRect2.y = rectangle.y;
        destRect3.x = rectangle.x;
        destRect3.y = rectangle.y;
        
        affichage(texture, textureSprite, textureSpriteDebout2,avancer1, avancer2, avancer3, avancer4, avancer5,accroupis, renderer, &barreDeVie,&barreDeVieDroite,&barreDeVieRed,&barreDeVieRedDroite,&rectangle, &destRect1, &destRect2, &destRect3, &rectangleCoup,&snick ,&coup,&compteur,&avancer,&compteurAvancer, &rectanglePunchingBall);
        SDL_PollEvent(&touche2);// Récupération des actions de l'utilisateur
        switch (touche2.type)
        {
        case SDL_KEYUP:
            switch (touche2.key.keysym.sym)
            {
            case SDLK_ESCAPE:// Regarde si == touche ESC
                SDL_DestroyTexture(textureSpriteDebout2);
                SDL_DestroyTexture(textureSprite);
                SDL_DestroyTexture(texture);// detruit la texture
                SDL_DestroyRenderer(renderer);// detruit le rendu
                SDL_DestroyWindow(pwindow); // Detruit la fenetre
                jeu = 1;
                break;

            }
            break;
        }
        
    }


    SDL_Quit();
    return 0;
}



/* modifier pour les touches
liens:
https://wiki.libsdl.org/SDL2/SDL_GetKeyboardState
https://wiki.libsdl.org/SDL2/SDL_Scancode
https://www.remove.bg/fr/upload
*/


/*

difficulté :

    avoir le meme temps pour faire la boucle pour tout le monde


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
