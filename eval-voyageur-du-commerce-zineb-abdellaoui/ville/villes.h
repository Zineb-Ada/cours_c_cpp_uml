#ifndef __CITIES_H
#define __CITIES_H

#include <vector>
#include <string>

class Ville;

class Villes
{
private:
    size_t size;
    std::vector<Ville*> villes;
public:
    Villes();
    Villes(Villes *);
    size_t getSize();
    void addVille(const std::string);
    void addVille(Ville *);
    void removeLastVille();
    Ville *find(const std::string);
    void display();
    void free();
};

#endif