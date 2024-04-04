#include "ville/ville.h"
#include <iostream>
#include <algorithm>


Ville::Ville(const std::string& _name)
{
    name =_name;
    distance = 0;
}

const std::string Ville::getName()
{
    return name;
}

void Ville::addVoisin(Ville *_ville, int _distance)
{
    if(findVoisin(_ville->getName()) == nullptr)
    {
        voisins.push_back(std::make_pair(_ville, _distance));
        _ville->voisins.push_back(std::make_pair(this, _distance));
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

