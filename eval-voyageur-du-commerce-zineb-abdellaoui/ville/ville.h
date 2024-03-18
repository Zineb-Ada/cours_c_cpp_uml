#ifndef __VILLE_H
#define __VILLE_H
#include <vector>
#include <string>

class Voisin;
class villes;

class Ville
{
private:
    std::string name;
    std::vector<std::pair<Ville*, int> > voisins; // Vecteur de paires pour stocker les voisins et leurs distances
    //std::vector<Voisin*> voisins;
    int distance;
public:
    Ville(const std::string&);
    const std::string getName();
    void addVoisin(Ville *, int);
    void display(int, std::vector<Ville*> *);
    Ville *findVoisin(const std::string);
    int getDistance();
    std::vector<std::pair<Ville*, int> > getVoisins(); // Modifier le type de retour
    ~Ville();
};

#endif
