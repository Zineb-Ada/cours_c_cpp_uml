#include "ville/villes.h"
#include <algorithm>
#include "ville/ville.h"
#include <iostream>

Villes::Villes()
{
    size = 0;
}

Villes::Villes(Villes *Villes)
{
    size = 0;
    for(size_t i = 0; i < Villes->getSize(); i++)
    {
        villes.push_back(Villes->villes[i]);
        size++;
    }
}

void Villes::addVille(const std::string name)
{
    if(find(name) == nullptr)
    {
        villes.push_back(new Ville(name));
        size++;
    }
}

void Villes::addVille(Ville *ville)
{
    villes.push_back(ville);
    size++;
}

void Villes::removeLastVille()
{
    villes.pop_back();
    size--;
}

size_t Villes::getSize()
{
    return size;
}

Ville *Villes::find(const std::string name)
{
    for(size_t i = 0; i < size; i++)
    {
        if(villes[i]->getName() == name)
        {
            return villes[i];
        }
    }
    return nullptr;
}

void Villes::display()
{
    for(size_t i = 0; i < size; i++)
    {
        std::cout << villes[i]->getName() << ' ';
    }
    std::cout << std::endl;
}

void Villes::free()
{
    for(size_t i = 0; i < size; i++)
    {
        delete villes[i];
    }
}