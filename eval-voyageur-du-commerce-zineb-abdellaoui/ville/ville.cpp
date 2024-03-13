#include "ville/ville.h"
#include "procheVoisin/voisin.h"
#include <iostream>
#include <algorithm>

Ville::Ville(const std::string& _name)
{
    name =_name;
    distance = 0; // ajout
}

const std::string Ville::getName()
{
    return name;
}

void Ville::addVoisin(Ville *_ville, int _distance)
{
    if(findVoisin(_ville->getName()) == nullptr)
    {
        voisins.push_back(new Voisin(_ville, _distance));
        _ville->voisins.push_back(new Voisin(this, _distance));
    }
}

void Ville::display(int indent, std::vector<Ville*> *already_displayed)
{
    already_displayed->push_back(this);
    std::cout << name << std::endl;
    for(size_t i = 0; i < voisins.size(); i++)
    {
        Ville *_ville = voisins[i]->getVille();
        for(int _i = 0; _i < indent; _i++)
        {
            std::cout << "  ";
        }
        std::cout << "  -> " << voisins[i]->getDistance() << ": ";
        auto it = std::find(already_displayed->begin(), already_displayed->end(), _ville);
        if (it != already_displayed->end())
            std::cout << voisins[i]->getVille()->getName() << std::endl;
        else
            voisins[i]->getVille()->display(indent + 1,  already_displayed);
    }
}

Ville *Ville::findVoisin(const std::string name)
{
    for(size_t i = 0; i < voisins.size(); i++)
    {
        if(voisins[i]->getVille()->getName() == name)
        {
            return voisins[i]->getVille();
        }
    }
    return nullptr;
}

std::vector<Voisin*> Ville::getVoisins()
{
    return voisins;
}

int Ville::getDistance()
{
    return distance;
}

Ville::~Ville()
{
    for(size_t i = 0; i < voisins.size(); i++)
    {
        delete voisins[i];
    }
}