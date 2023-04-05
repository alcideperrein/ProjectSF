
#include "deplacement.c"
#include "structure.h"
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    Coordonees point;

    SDL_version nb;
    SDL_VERSION(&nb);


    point.x = 0;
    point.y = 0;

    printf("bienvenue sur la sdl %d.%d.%d !\n", nb.major, nb.minor, nb.patch);
    gauche(&point);
    printf("%d", point.x);

    return 0;
}

// gcc ProjectSF/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2

/*#include <SDL.h>
#include"structure.h"
#include "deplacement.c"
#include<stdio.h>


int main(int argc, char **argv)
{
    Coordonees point;

    SDL_version nb;
    SDL_VERSION(&nb);

    printf("bienvenue sur la sdl %d.%d.%d !\n", nb.major, nb.minor, nb.patch);


    return 0;
}*/
// gcc ProjectSF/src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
