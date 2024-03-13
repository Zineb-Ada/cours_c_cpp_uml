#include "procheVoisin/voisin.h"
#include "ville/ville.h"

Voisin::Voisin(Ville *_ville, int _distance)
{
    ville = _ville;
    distance = _distance;
    isVisited = false;
}

int Voisin::getDistance()
{
    return distance;
}

Ville *Voisin::getVille()
{
    return ville;
}