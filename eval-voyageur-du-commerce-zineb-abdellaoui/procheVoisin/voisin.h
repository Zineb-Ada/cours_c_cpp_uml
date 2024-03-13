#ifndef __NEIGHBOR_H
#define __NEIGHBOR_H

class Ville;

class Voisin
{
private:
    Ville *ville;
    int distance;
    bool isVisited;
public:
    Voisin(Ville *, int);
    Ville *getVille();
    int getDistance();
};

#endif