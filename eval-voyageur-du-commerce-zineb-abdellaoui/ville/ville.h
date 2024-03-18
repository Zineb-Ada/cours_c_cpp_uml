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
    // Vecteur de paires pour stocker les voisins et leurs distances
    std::vector<std::pair<Ville*, int> > voisins; 
    int distance;
public:
    Ville(const std::string&);
    const std::string getName();
    void addVoisin(Ville *, int);
    void display(int, std::vector<Ville*> *);
    Ville *findVoisin(const std::string);
    int getDistance();
    // Pour modifier le type de retour
    std::vector<std::pair<Ville*, int> > getVoisins(); 
    ~Ville();
};

#endif
