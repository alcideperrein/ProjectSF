#include "structure.h"

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
