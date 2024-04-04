#include <iostream>
#include <fstream>
#include <sstream>
#include "ville/ville.h"
#include "ville/villes.h"
#include <vector>
#include <chrono>

void researchBestPath(Ville *, Villes *, int);

int shortest_distance = -1;
Villes *shortest_path = nullptr;
Villes all_villes;
Ville *startingVille = nullptr;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << "7-villes.txt" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 2;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string villeFromName, villeToName;
        int distance;

        if (!(iss >> villeFromName >> distance >> villeToName)) {
            std::cerr << "Error reading file." << std::endl;
            continue;
        }

        all_villes.addVille(villeFromName);
        all_villes.addVille(villeToName);
        all_villes.find(villeFromName)->addVoisin(all_villes.find(villeToName), distance);
    }

    std::string userInput;
    while (startingVille == nullptr) {
        std::cout << "Enter the departure city from those in the file : " << std::endl;
        std::getline(std::cin, userInput);

        startingVille = all_villes.find(userInput);
    }

    std::cout << "The neighbors of this city are : " << std::endl;
    std::vector<Ville*> *displayed_villes = new std::vector<Ville*>;
    all_villes.find(userInput)->display(0, displayed_villes);
    delete displayed_villes;
    std::cout << "------------------------------------------------ " << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    Villes *path = new Villes();
    researchBestPath(startingVille, path, 0);
    delete path;

    auto end_calcul = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_calcul - start);
    std::cout << "The calculation required : " << duration.count() << " microseconds" << std::endl;

    if (shortest_distance == -1) {
        std::cout << "No route found" << std::endl;
    } else {
        std::cout << "The shortest route found is : " << shortest_distance << std::endl;
        shortest_path->display();
        delete shortest_path;
    }
    all_villes.free();

    return 0;
}

void researchBestPath(Ville *current_ville, Villes *path, int current_distance) {
    Ville *ville_already_visited = path->find(current_ville->getName());
    path->addVille(current_ville);

    if (shortest_distance != -1 && current_distance > shortest_distance) {
        return;
    }

    if (path->getSize() == all_villes.getSize() && current_ville == startingVille) {
        if (current_distance < shortest_distance || shortest_distance == -1) {
            std::cout << "Possible candidate found with distance of " << current_distance << ": ";
            path->display();
            shortest_distance = current_distance;
            if (shortest_path != nullptr) {
                delete shortest_path;
            }
            shortest_path = new Villes(path);
        }
        return;
    }

    // Pour vérifier si la ville actuelle a déjà été visitée
    if (ville_already_visited != nullptr) {
        return;
    }
}