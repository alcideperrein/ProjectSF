#include"structure.h"
#include "deplacement.c"
#include<stdio.h>
#include <SDL.h>

int main(int argc, char **argv)
{
    int i=0;
    Coordonees point;
    point.x=0;
    gauche(&point);
    printf("%d",point.x);


    return 0;
}
