#include "structure.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

void affichage(SDL_Texture* texture, SDL_Texture* textureSprite, SDL_Texture* textureSpriteDebout2, SDL_Texture* avancer1, SDL_Texture* avancer2, SDL_Texture* avancer3, SDL_Texture* avancer4,
    SDL_Texture* avancer5, SDL_Texture* accroupis, SDL_Texture* saut1, SDL_Texture* saut2, SDL_Texture* saut3, SDL_Texture* saut4, SDL_Texture* saut5, SDL_Texture* saut6,
    SDL_Texture* coupDebout1, SDL_Texture* coupDebout2, SDL_Texture* coupDebout3, SDL_Texture* coupAccroupis1, SDL_Texture* coupAccroupis2, SDL_Texture* coupAccroupis3, SDL_Texture* coupPied1,
    SDL_Texture* coupPied2, SDL_Texture* coupPied3, SDL_Texture* deboutBot, SDL_Renderer* renderer, SDL_Rect* barreDeVie, SDL_Rect* barreDeVieDroite, SDL_Rect* barreDeVieRed,
    SDL_Rect* barreDeVieRedDroite, SDL_Rect* rectangle, SDL_Rect* destRect1, SDL_Rect* destRect2, SDL_Rect* destRect3, SDL_Rect* destRect4, SDL_Rect* destRect5, SDL_Rect* destRectBot1,
    SDL_Rect* rectangleCoup, int* psnick, int* pcoup, int* pcoupPied, int* pcompteur, int* pavancer, int* pcompteurAvancer, int* pcompteursaut, int* psaut, SDL_Rect* rectanglePunchingBall)// est définie pour dessiner les éléments du jeu sur la fenêtre. Elle prend en paramètre la texture à afficher, le renderer, les rectangles de base et de coup, et le coup choisit.
{
    SDL_RenderClear(renderer); // efface le rendu
    SDL_RenderCopy(renderer, texture, NULL, NULL); // charge la texture sur le rendu
    SDL_RenderCopy(renderer, deboutBot, NULL, destRectBot1);// charge la texture qui sera mise aux coordonée de destRectBot1
    if (*psaut == 1 || *psaut == 2)
    {
        if (*pcompteursaut < 10) // permet de gerer l'animation compte le nombre de fois ou rentre dans la fonction pour gérer affichage 
        {
            SDL_RenderCopy(renderer, saut1, NULL, destRect2);// charge la texture qui sera mise aux coordonée de destRect2
            *pcompteursaut += 1;
        }
        else if (*pcompteursaut < 40)
        {
            SDL_RenderCopy(renderer, saut2, NULL, destRect2);
            *pcompteursaut += 1;
        }
        else if (*pcompteursaut < 80)
        {
            SDL_RenderCopy(renderer, saut3, NULL, destRect2);
            *pcompteursaut += 1;
        }
        else if (*pcompteursaut < 100)
        {
            SDL_RenderCopy(renderer, saut4, NULL, destRect2);
            *pcompteursaut += 1;
        }
        else if (*pcompteursaut < 140)
        {
            SDL_RenderCopy(renderer, saut5, NULL, destRect2);
            *pcompteursaut += 1;
        }
        else if (*pcompteursaut < 200)
        {
            SDL_RenderCopy(renderer, saut6, NULL, destRect2);
            *pcompteursaut += 1;
        }
        else if (*pcompteursaut < 240)
        {
            SDL_RenderCopy(renderer, saut1, NULL, destRect2);
            *pcompteursaut += 1;
        }
    }


    else if (*pcoup != 0 && *psnick == 0)
    {
        if (rectangleCoup->w < 50)//rectangleCoup->w = rectangleCoup.w pour les pointeurs
        {
            SDL_RenderCopy(renderer, coupDebout1, NULL, destRect2);
        }
        else if (rectangleCoup->w > 160)
        {
            SDL_RenderCopy(renderer, coupDebout3, NULL, destRect4);
        }
        else if (rectangleCoup->w > 30)
        {
            SDL_RenderCopy(renderer, coupDebout2, NULL, destRect2);
        }

    }
    else if (*pcoupPied != 0)
    {
        if (rectangleCoup->w < 50)
        {
            SDL_RenderCopy(renderer, coupPied1, NULL, destRect2);
        }
        else if (rectangleCoup->w > 160)
        {
            SDL_RenderCopy(renderer, coupPied3, NULL, destRect4);
        }
        else if (rectangleCoup->w > 30)
        {
            SDL_RenderCopy(renderer, coupPied2, NULL, destRect2);
        }

    }
    else if (*pcoup != 0 && *psnick == 1)
    {
        if (rectangleCoup->w < 50)
        {
            SDL_RenderCopy(renderer, coupAccroupis1, NULL, destRect3);
        }
        else if (rectangleCoup->w > 140)
        {
            SDL_RenderCopy(renderer, coupAccroupis3, NULL, destRect5);
        }
        else if (rectangleCoup->w > 30)
        {
            SDL_RenderCopy(renderer, coupAccroupis2, NULL, destRect3);
        }
    }

    else if (*pavancer == 1 && *psnick == 0)
    {
        if (*pcompteurAvancer < 20) // permet de gerer l'animation compte le nombre de fois ou rentre dans la fonction pour gérer affichage 
        {
            SDL_RenderCopy(renderer, avancer1, NULL, destRect2);
            *pcompteurAvancer += 1;
        }
        else if (*pcompteurAvancer < 40)
        {
            SDL_RenderCopy(renderer, avancer2, NULL, destRect2);
            *pcompteurAvancer += 1;
        }
        else if (*pcompteurAvancer < 60)
        {
            SDL_RenderCopy(renderer, avancer3, NULL, destRect2);
            *pcompteurAvancer += 1;
        }
        else if (*pcompteurAvancer < 80)
        {
            SDL_RenderCopy(renderer, avancer4, NULL, destRect2);
            *pcompteurAvancer += 1;
        }
        else if (*pcompteurAvancer < 120)
        {
            SDL_RenderCopy(renderer, avancer5, NULL, destRect2);
            *pcompteurAvancer += 1;
            if (*pcompteurAvancer == 120)
            {
                *pcompteurAvancer = 0;
            }
        }
    }
    else if (*psnick == 1)
    {
        SDL_RenderCopy(renderer, accroupis, NULL, destRect3);
    }
    else
    {
        if (*pcompteur < 80)
        {
            SDL_RenderCopy(renderer, textureSprite, NULL, destRect2);
            *pcompteur += 1;
        }
        else
        {
            SDL_RenderCopy(renderer, textureSpriteDebout2, NULL, destRect2);
            *pcompteur += 1;
            if (*pcompteur == 160)
            {
                *pcompteur = 0;
            }
        }
    }

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);// choisit la couleur
    SDL_RenderDrawRect(renderer, rectangle);// dessine le rectangle pour la couleur choisit (SDL_RenderDrawRect rectangle vide,SDL_RenderFillRect rectangle plein)
    SDL_RenderDrawRect(renderer, rectanglePunchingBall);
    if ((*pcoup != 0) || (*pcoupPied != 0))
    {
        SDL_RenderDrawRect(renderer, rectangleCoup);
    }
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);// choisit la couleur
    SDL_RenderFillRect(renderer, barreDeVieRed);// dessine le rectangle en plein pour la couleur choisit ( SDL_RenderDrawRect rectangle vide,SDL_RenderFillRect rectangle plein)
    SDL_RenderFillRect(renderer, barreDeVieRedDroite);
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, barreDeVie);
    SDL_RenderFillRect(renderer, barreDeVieDroite);
    SDL_RenderPresent(renderer);// affiche le rendu
}


void hitCheck(int* pcoup, int* pstrikeSpeed, int* pcoupPied, int* pdegat, SDL_Rect* rectanglePunchingBall, SDL_Rect* rectangleCoup, SDL_Rect* barreDeVieDroite) {
    if ((*pcoup == 1 || *pcoup == 5 || *pcoupPied == 1) && ((rectangleCoup->x + rectangleCoup->w) >= rectanglePunchingBall->x) && *pstrikeSpeed == 0 && *pdegat == 0) {
        barreDeVieDroite->x += 15;
        barreDeVieDroite->w -= 15;
        *pdegat = 1;// permet de mettre une seul fois le degat par coup touche
    }
    else if ((*pstrikeSpeed == 2) && ((rectangleCoup->x + rectangleCoup->w) >= rectanglePunchingBall->x) && *pdegat == 0) {

        barreDeVieDroite->x += 20;
        barreDeVieDroite->w -= 20;
        *pdegat = 1;
    }
    else if ((*pstrikeSpeed == 1) && ((rectangleCoup->x + rectangleCoup->w) >= rectanglePunchingBall->x) && *pdegat == 0) {

        barreDeVieDroite->x += 40;
        barreDeVieDroite->w -= 40;
        *pdegat = 1;
    }
}

void win(SDL_Rect* rectangle, SDL_Texture* texture, SDL_Texture* win1, SDL_Texture* win2, SDL_Texture* win3, SDL_Renderer* renderer, SDL_Rect* destRect2, SDL_Rect* destRectwin3
    , int* petapeWin, int* pcompteurWin) {
    if (rectangle->y != 500) { // rectangle->y == rectangle.y different car pointeur
        rectangle->y = 500;
        rectangle->h = 500;

    }
    SDL_RenderClear(renderer);// efface le rendu 
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    if (*petapeWin == 0) {
        SDL_RenderCopy(renderer, win1, NULL, destRect2);// charge la texture qui sera mise aux coordonée de destRect2
        *pcompteurWin += 1;
        if (*pcompteurWin > 100) { // permet de gerer l'animation compte le nombre de fois ou rentre dans la fonction pour gérer affichage 
            *petapeWin = 1;
        }
    }
    else if (*petapeWin == 1) {
        SDL_RenderCopy(renderer, win2, NULL, destRect2);
        *pcompteurWin += 1;
        if (*pcompteurWin > 150) {
            *petapeWin = 2;
        }
    }
    else {
        SDL_RenderCopy(renderer, win3, NULL, destRectwin3);
    }
    SDL_RenderPresent(renderer);// affiche le rendu
}

void jeu(int* pjouer) {
    SDL_Window* pwindow;
    SDL_Renderer* renderer;
    Uint8 const* touche;
    SDL_Event touche2;
    SDL_Rect rectangle = { 20, 500, 220, 500 };// {x,y,w,h}
    SDL_Rect rectangleCoup = { 0, 0, 0, 100 };
    SDL_Rect rectanglePunchingBall = { 1600, 500, 220, 500 };
    SDL_Rect barreDeVie = { 80, 80, 700, 40 };
    SDL_Rect barreDeVieRed = { 80, 80, 700,40 };
    SDL_Rect barreDeVieDroite = { 1180, 80, 680,40 };
    SDL_Rect barreDeVieRedDroite = { 1180, 80, 680,40 };
    SDL_Rect destRect1;
    SDL_Rect destRect2;
    SDL_Rect destRect3;
    SDL_Rect destRect4;
    SDL_Rect destRect5;
    SDL_Rect destRectBot1;
    SDL_Rect destRectwin3;
    SDL_Texture* texture;
    SDL_Texture* textureSprite;
    SDL_Texture* textureSpriteDebout2;
    SDL_Texture* avancer1;
    SDL_Texture* avancer2;
    SDL_Texture* avancer3;
    SDL_Texture* avancer4;
    SDL_Texture* avancer5;
    SDL_Texture* accroupis;
    SDL_Texture* saut1;
    SDL_Texture* saut2;
    SDL_Texture* saut3;
    SDL_Texture* saut4;
    SDL_Texture* saut5;
    SDL_Texture* saut6;
    SDL_Texture* coupDebout1;
    SDL_Texture* coupDebout2;
    SDL_Texture* coupDebout3;
    SDL_Texture* coupAccroupis1;
    SDL_Texture* coupAccroupis2;
    SDL_Texture* coupAccroupis3;
    SDL_Texture* coupPied1;
    SDL_Texture* coupPied2;
    SDL_Texture* coupPied3;
    SDL_Texture* deboutBot;
    SDL_Texture* win1;
    SDL_Texture* win2;
    SDL_Texture* win3;

    int jeu = 0;
    int saut = 0;
    int snick = 0;
    int coup = 0;
    int coupPied = 0;
    int strikeSpeed = 0;
    int compteur = 0;
    int avancer = 0;
    int compteurAvancer = 0;
    int compteurSaut = 0;
    int side = 1;
    int degat = 0;
    int etape = 0;
    int compteurWin = 0;

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    SDL_version nb;
    SDL_VERSION(&nb);
    pwindow = SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1920,
        1080,
        SDL_WINDOW_FULLSCREEN);// Cree la fenêtre de dimension 1920px par 1080px en fullscreen

    renderer = SDL_CreateRenderer(pwindow, -1, SDL_RENDERER_SOFTWARE); // creer un rendu
    texture = IMG_LoadTexture(renderer, "C:/Users/Public/SFBackground.bmp"); // telecharger la texture (IMG_LoadTexture besoin de SLD_Image)
    textureSprite = IMG_LoadTexture(renderer, "C:/Users/Public/Debout.png");
    textureSpriteDebout2 = IMG_LoadTexture(renderer, "C:/Users/Public/Debout2.png");
    avancer1 = IMG_LoadTexture(renderer, "C:/Users/Public/avancer1.png");
    avancer2 = IMG_LoadTexture(renderer, "C:/Users/Public/avancer2.png");
    avancer3 = IMG_LoadTexture(renderer, "C:/Users/Public/avancer3.png");
    avancer4 = IMG_LoadTexture(renderer, "C:/Users/Public/avancer4.png");
    avancer5 = IMG_LoadTexture(renderer, "C:/Users/Public/avancer5.png");
    accroupis = IMG_LoadTexture(renderer, "C:/Users/Public/accroupis.png");
    saut1 = IMG_LoadTexture(renderer, "C:/Users/Public/saut1.png");
    saut2 = IMG_LoadTexture(renderer, "C:/Users/Public/saut2.png");
    saut3 = IMG_LoadTexture(renderer, "C:/Users/Public/saut3.png");
    saut4 = IMG_LoadTexture(renderer, "C:/Users/Public/saut4.png");
    saut5 = IMG_LoadTexture(renderer, "C:/Users/Public/saut5.png");
    saut6 = IMG_LoadTexture(renderer, "C:/Users/Public/saut6.png");
    coupDebout1 = IMG_LoadTexture(renderer, "C:/Users/Public/coupDebout1.png");
    coupDebout2 = IMG_LoadTexture(renderer, "C:/Users/Public/coupDebout2.png");
    coupDebout3 = IMG_LoadTexture(renderer, "C:/Users/Public/coupDebout3.png");
    coupAccroupis1 = IMG_LoadTexture(renderer, "C:/Users/Public/coupAccroupis1.png");
    coupAccroupis2 = IMG_LoadTexture(renderer, "C:/Users/Public/coupAccroupis2.png");
    coupAccroupis3 = IMG_LoadTexture(renderer, "C:/Users/Public/coupAccroupis3.png");
    coupPied1 = IMG_LoadTexture(renderer, "C:/Users/Public/coupPied1.png");
    coupPied2 = IMG_LoadTexture(renderer, "C:/Users/Public/coupPied2.png");
    coupPied3 = IMG_LoadTexture(renderer, "C:/Users/Public/coupPied3.png");
    deboutBot = IMG_LoadTexture(renderer, "C:/Users/Public/deboutBot.png");
    win1 = IMG_LoadTexture(renderer, "C:/Users/Public/win1.png");
    win2 = IMG_LoadTexture(renderer, "C:/Users/Public/win2.png");
    win3 = IMG_LoadTexture(renderer, "C:/Users/Public/win3.png");


    destRect2.x = rectangle.x;// le rectangle ou on va afficher le sprite prend la valeur du rectangle de la hitbox perso
    destRect2.y = rectangle.y;
    destRect3.x = rectangle.x;
    destRect3.y = rectangle.y;
    destRect4.x = rectangle.x;
    destRect4.y = rectangle.y;
    destRect5.x = rectangle.x;
    destRect5.y = rectangle.y;
    destRectwin3.x = rectangle.x;
    destRectwin3.y = rectangle.y;
    destRectBot1.x = rectanglePunchingBall.x;// le rectangle ou on va afficher le sprite prend la valeur du rectangle de la hitbox punchingball
    destRectBot1.y = rectanglePunchingBall.y;

    SDL_QueryTexture(textureSprite, NULL, NULL, &destRect2.w, &destRect2.h);// permet que la hauteur et la largeur du rectangle correspondent a celle du sprite
    SDL_QueryTexture(accroupis, NULL, NULL, &destRect3.w, &destRect3.h);
    SDL_QueryTexture(coupDebout3, NULL, NULL, &destRect4.w, &destRect4.h);
    SDL_QueryTexture(coupAccroupis3, NULL, NULL, &destRect5.w, &destRect5.h);
    SDL_QueryTexture(deboutBot, NULL, NULL, &destRectBot1.w, &destRectBot1.h);
    SDL_QueryTexture(win3, NULL, NULL, &destRectwin3.w, &destRectwin3.h);

    SDL_RenderClear(renderer); // efface le rendu 

    SDL_RenderCopy(renderer, texture, NULL, &destRect1);// charge la texture sur le rendu


    SDL_RenderPresent(renderer);//affiche un rendu 



    while (jeu == 0)
    {

        touche = SDL_GetKeyboardState(NULL); // récupérer l'état des touches du clavier

        if (touche[SDL_SCANCODE_D] && (coup == 0) && (coupPied == 0) && snick == 0 && compteurWin == 0) // aller a gauche
        {
            if (rectangle.x < 1680)
            {
                if (snick == 0)
                {
                    rectangle.x += 2;
                }
                if (saut == 1)
                {
                    rectangle.x += 1;
                }
                side = 1;
            }
            avancer = 1;
        }

        if (touche[SDL_SCANCODE_A] && (coup == 0) && (coupPied == 0) && snick == 0 && compteurWin == 0) // aller a gauche
        {

            if (rectangle.x > 20)
            {
                if (snick == 0)
                {
                    rectangle.x -= 2;
                }
                if (saut == 1)
                {
                    rectangle.x -= 1;
                }
            }
            avancer = 1;

        }

        if ((touche[SDL_SCANCODE_S]) && (saut == 0) && (coup == 0) && (coupPied == 0)) // quand on appui sur la touche pour se baisser
        {
            rectangle.y = 700;
            rectangle.h = 300;
            snick = 1;
        }
        if ((touche[SDL_SCANCODE_W]) && (saut == 0) && (snick == 0) && (coup == 0) && (coupPied == 0))// quand on appui sur la touche pour sauter
        {
            if (rectangle.y > 130)
            {
                saut = 1;
            }
            else
            {
                saut = 2;
            }

        }


        if (saut == 1)
        {
            if (rectangle.y < 130)
            {
                saut = 2;
            }
            rectangle.y -= 4;
        }
        if (saut == 2)
        {
            if (rectangle.y < 500)
            {
                rectangle.y += 4;
            }
            else if (rectangle.y == 500)
            {
                saut = 0;
                compteurSaut = 0;
            }
        }


        if ((touche[SDL_SCANCODE_S] == 0) && (snick == 1) && (saut == 0) && (coup == 0)) // quand on lache la touche pour se relever
        {
            rectangle.y = 500;
            rectangle.h = 500;
            snick = 0;
            avancer = 0;
            compteurAvancer = 0;
        }


        if (((touche[SDL_SCANCODE_C]) || (touche[SDL_SCANCODE_Q]) || (touche[SDL_SCANCODE_E]) || ((touche[SDL_SCANCODE_R] && snick == 0))) && (saut == 0))
        {

            if (touche[SDL_SCANCODE_Q])
            {
                strikeSpeed = 1; // correspond a coup lent
            }
            if (touche[SDL_SCANCODE_E])
            {
                strikeSpeed = 2; // correspond a coup moyen
            }
            if ((touche[SDL_SCANCODE_R]) && (side == 1) && (snick == 0))
            {
                coupPied = 1; // correspond a coup pied
                side = 3;
            }

            else if ((side == 1) && (snick == 0))
            {
                coup = 1;
                side = 3;// Pour pas qu'il repasse a coup 1
            }

            else if ((side == 1) && (snick == 1))
            {
                coup = 5;
                side = 3; // Pour pas qu'il repasse a coup 5
            }


        }



        if ((coup == 1) && (saut == 0))   // coup de poing droit
        {
            rectangleCoup.h = 80;
            rectangleCoup.x = rectangle.x + rectangle.w;// permet de commencer le rectangle coup sur la partie droite du rectangle
            rectangleCoup.y = rectangle.y + 80; // gerer la position du coup en fonction des ordonnées (inversé en SDL 0 en haut a gauche)
            if (rectangleCoup.w > 220)
            {
                coup = 2;
            }
            if (strikeSpeed == 1)
            {
                rectangleCoup.w += 2;
            }
            else if (strikeSpeed == 2)
            {
                rectangleCoup.w += 3;
            }
            else
            {
                rectangleCoup.w += 4;
            }

        }
        if ((coup == 2) && (saut == 0))   // retour coup de point gauche
        {
            if (strikeSpeed == 1)
            {
                rectangleCoup.w -= 2;
            }
            else if (strikeSpeed == 2)
            {
                rectangleCoup.w -= 3;
            }
            else
            {
                rectangleCoup.w -= 4;
            }
            if (rectangleCoup.w <= 0)
            {
                coup = 0;
                side = 1;
                strikeSpeed = 0;
                degat = 0;
            }
        }

        if ((coup == 5) && (saut == 0))    // coup de pied bas droit
        {
            rectangleCoup.h = 60;
            rectangleCoup.x = rectangle.x + rectangle.w;// permet de commencer le rectangle coup sur la partie droite du rectangle
            rectangleCoup.y = rectangle.y + 60;// gerer la position du coup en fonction des ordonnées (inversé en SDL 0 en haut a gauche)
            if (rectangleCoup.w > 180)
            {
                coup = 6;
            }
            if (strikeSpeed == 1)
            {
                rectangleCoup.w += 2;
            }
            else if (strikeSpeed == 2)
            {
                rectangleCoup.w += 3;
            }
            else
            {
                rectangleCoup.w += 4;
            }

        }

        if ((coup == 6) && (saut == 0))   // retour coup de pied bas
        {
            if (rectangleCoup.w <= 0)
            {
                coup = 0;
                side = 1;
                strikeSpeed = 0;
                degat = 0;
            }
            if (strikeSpeed == 1)
            {
                rectangleCoup.w -= 2;
            }
            else if (strikeSpeed == 2)
            {
                rectangleCoup.w -= 3;
            }
            else
            {
                rectangleCoup.w -= 4;
            }

        }

        if ((coupPied == 1) && (saut == 0))   // coup de pied
        {
            rectangleCoup.h = 130;
            rectangleCoup.x = rectangle.x + rectangle.w; // permet de commencer le rectangle coup sur la partie droite du rectangle
            rectangleCoup.y = rectangle.y + 250;// gerer la position du coup en fonction des ordonnées (inversé en SDL 0 en haut a gauche)
            if (rectangleCoup.w > 220)
            {
                coupPied = 2;
            }

            rectangleCoup.w += 4;


        }
        if ((coupPied == 2) && (saut == 0))   // retour coup de point gauche
        {
            rectangleCoup.w -= 4;
            if (rectangleCoup.w <= 0)
            {
                coupPied = 0;
                side = 1;
                degat = 0;
            }
        }



        if ((touche[SDL_SCANCODE_D] == 0 && touche[SDL_SCANCODE_A] == 0 && saut == 0 && snick == 0) || (touche[SDL_SCANCODE_D] && touche[SDL_SCANCODE_A] && saut == 0 && snick == 0))
        {
            avancer = 0;
            compteurAvancer = 0;
        }
        destRect2.x = rectangle.x;// permet de mettre le sprite aux coordonnées du rectangle de base car pas forcement même taille entre le rectangle et le sprite
        destRect2.y = rectangle.y;// permet de mettre le sprite aux coordonnées du rectangle de base car pas forcement même taille entre le rectangle et le sprite
        destRect3.x = rectangle.x;
        destRect3.y = rectangle.y;
        destRect4.x = rectangle.x;
        destRect4.y = rectangle.y;
        destRect5.x = rectangle.x;
        destRect5.y = rectangle.y;
        destRectwin3.x = rectangle.x;
        destRectwin3.y = rectangle.y;


        hitCheck(&coup, &strikeSpeed, &coupPied, &degat, &rectanglePunchingBall, &rectangleCoup, &barreDeVieDroite);// regarder si toucher ou non
        if (barreDeVieDroite.w <= 0) { // regarde si a gagner
            win(&rectangle, texture, win1, win2, win3, renderer, &destRect2, &destRectwin3, &etape, &compteurWin);// affichage si a gagner
        }
        else {
            affichage(texture, textureSprite, textureSpriteDebout2, avancer1, avancer2, avancer3, avancer4, avancer5, accroupis, saut1, saut2, saut3, saut4, saut5, saut6, coupDebout1, coupDebout2,
                coupDebout3, coupAccroupis1, coupAccroupis2, coupAccroupis3, coupPied1, coupPied2, coupPied3, deboutBot, renderer, &barreDeVie, &barreDeVieDroite, &barreDeVieRed, &barreDeVieRedDroite,
                &rectangle, &destRect1, &destRect2, &destRect3, &destRect4, &destRect5, &destRectBot1, &rectangleCoup, &snick, &coup, &coupPied, &compteur, &avancer, &compteurAvancer, &compteurSaut, &saut,
                &rectanglePunchingBall); // affichage si a gagner
        }


        SDL_PollEvent(&touche2);// Récupération des actions de l'utilisateur
        switch (touche2.type)
        {
        case SDL_KEYUP:
            switch (touche2.key.keysym.sym)
            {
            case SDLK_ESCAPE:// Regarde si == touche ESC
                SDL_DestroyTexture(textureSpriteDebout2);// detruit la texture
                SDL_DestroyTexture(textureSprite);
                SDL_DestroyTexture(avancer1);
                SDL_DestroyTexture(avancer2);
                SDL_DestroyTexture(avancer3);
                SDL_DestroyTexture(avancer4);
                SDL_DestroyTexture(avancer5);
                SDL_DestroyTexture(accroupis);
                SDL_DestroyTexture(saut1);
                SDL_DestroyTexture(saut2);
                SDL_DestroyTexture(saut3);
                SDL_DestroyTexture(saut4);
                SDL_DestroyTexture(saut5);
                SDL_DestroyTexture(saut6);
                SDL_DestroyTexture(coupDebout1);
                SDL_DestroyTexture(coupDebout2);
                SDL_DestroyTexture(coupDebout3);
                SDL_DestroyTexture(coupAccroupis1);
                SDL_DestroyTexture(coupAccroupis2);
                SDL_DestroyTexture(coupAccroupis3);
                SDL_DestroyTexture(coupPied1);
                SDL_DestroyTexture(coupPied2);
                SDL_DestroyTexture(coupPied3);
                SDL_DestroyTexture(deboutBot);
                SDL_DestroyTexture(win1);
                SDL_DestroyTexture(win2);
                SDL_DestroyTexture(win3);
                SDL_DestroyTexture(texture);
                SDL_DestroyRenderer(renderer);// detruit le rendu
                SDL_DestroyWindow(pwindow); // Detruit la fenetre
                jeu = 1;
                *pjouer = 1; // permet d'arreter le jeu 
                break;
            case SDLK_g:// Regarde si == touche g
                SDL_DestroyTexture(textureSpriteDebout2);// detruit la texture
                SDL_DestroyTexture(textureSprite);
                SDL_DestroyTexture(avancer1);
                SDL_DestroyTexture(avancer2);
                SDL_DestroyTexture(avancer3);
                SDL_DestroyTexture(avancer4);
                SDL_DestroyTexture(avancer5);
                SDL_DestroyTexture(accroupis);
                SDL_DestroyTexture(saut1);
                SDL_DestroyTexture(saut2);
                SDL_DestroyTexture(saut3);
                SDL_DestroyTexture(saut4);
                SDL_DestroyTexture(saut5);
                SDL_DestroyTexture(saut6);
                SDL_DestroyTexture(coupDebout1);
                SDL_DestroyTexture(coupDebout2);
                SDL_DestroyTexture(coupDebout3);
                SDL_DestroyTexture(coupAccroupis1);
                SDL_DestroyTexture(coupAccroupis2);
                SDL_DestroyTexture(coupAccroupis3);
                SDL_DestroyTexture(coupPied1);
                SDL_DestroyTexture(coupPied2);
                SDL_DestroyTexture(coupPied3);
                SDL_DestroyTexture(deboutBot);
                SDL_DestroyTexture(win1);
                SDL_DestroyTexture(win2);
                SDL_DestroyTexture(win3);
                SDL_DestroyTexture(texture);
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


int main(int argc, char** argv)
{
    int jouer = 0;
    while (jouer == 0) { // permet de pouvoir recommencer le jeu tant que jouer == 0
        jeu(&jouer);
    }


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

    Recuperer les sprites
    creer plusieuts textures en meme temps


*/

