#include "ville/ville.h"
#include <iostream>
#include <algorithm>


Ville::Ville(const std::string& _name)
{
    name =_name;
    distance = 0; // distance = 0; // Cette distance est-elle nécessaire ici ?
}

const std::string Ville::getName()
{
    return name;
}

void Ville::addVoisin(Ville *_ville, int _distance)
{
    if(findVoisin(_ville->getName()) == nullptr)
    {
        voisins.push_back(std::make_pair(_ville, _distance)); // Ajouter la paire de ville et de distance
        _ville->voisins.push_back(std::make_pair(this, _distance)); // Ajouter la paire de la ville actuelle et de la distance à la ville voisine
    }
}

void Ville::display(int indent, std::vector<Ville*> *already_displayed)
{
    already_displayed->push_back(this);
    std::cout << name << std::endl;
    for(size_t i = 0; i < voisins.size(); i++)
    {
        Ville *_ville = voisins[i].first;
        for(int _i = 0; _i < indent; _i++)
        {
            std::cout << "  ";
        }
        std::cout << "  -> " << voisins[i].second << ": ";
        auto it = std::find(already_displayed->begin(), already_displayed->end(), _ville);
        if (it != already_displayed->end())
            std::cout << _ville->getName() << std::endl;
        else
            _ville->display(indent + 1,  already_displayed);
    }
}

Ville *Ville::findVoisin(const std::string name)
{
    for(size_t i = 0; i < voisins.size(); i++)
    {
        if(voisins[i].first->getName() == name)
        {
            return voisins[i].first;
        }
    }
    return nullptr;
}

std::vector<std::pair<Ville*, int>> Ville::getVoisins()
{
    return voisins;
}

int Ville::getDistance()
{
    return distance;
}

// Ville::~Ville()
// {
//     for(size_t i = 0; i < voisins.size(); i++)
//     {
//         delete voisins[i];
//     }
// }
    
// Le destructeur doit-il être mis à jour en conséquence ?

