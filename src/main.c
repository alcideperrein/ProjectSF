#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    SDL_version nb;
    SDL_VERSION(&nb);

    printf("bienvenue sur la sdl %d.%d.%d !\n", nb.major, nb.minor, nb.patch);


    return 0;
}

// gcc ProjectSF/src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2