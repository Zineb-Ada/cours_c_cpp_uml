#ifndef __CITY_H
#define __CITY_H

#include <vector>
#include <string>

class Voisin;
class villes;

class Ville
{
private:
    std::string name;
    std::vector<Voisin*> voisins;
    int distance;
public:
    Ville(const std::string&);
    const std::string getName();
    void addVoisin(Ville *, int);
    void display(int, std::vector<Ville*> *);
    Ville *findVoisin(const std::string);
    int getDistance();
    std::vector<Voisin*> getVoisins();
    ~Ville();
};

#endif