#include"structure.h"
#include "deplacement.c"
#include<stdio.h>

int main()
{
    int i=0;
    Coordonees point;
    point.x=0;
    gauche(&point);
    printf("%d",point.x);


    return 0;
}
