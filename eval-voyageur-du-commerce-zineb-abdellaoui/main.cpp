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
    // Vérifier le nombre d'arguments
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << "7-distance.txt" << std::endl;
        return 1;
    }

    // Ouvrir le fichier contenant les informations sur les villes et leurs voisins
    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 2;
    }

    // Lire les informations sur les villes et leurs voisins à partir du fichier
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

    // Sélectionner la ville de départ
    std::string userInput;
    while (startingVille == nullptr) {
        std::cout << "Enter the departure city from those in the file : " << std::endl;
        std::getline(std::cin, userInput);

        startingVille = all_villes.find(userInput);
    }

    // Afficher les voisins de la ville de départ
    std::cout << "The neighbors of this city are : " << std::endl;
    std::vector<Ville*> *displayed_villes = new std::vector<Ville*>;
    all_villes.find(userInput)->display(0, displayed_villes);
    delete displayed_villes;
    std::cout << "------------------------------------------------ " << std::endl;

    // Mesurer le temps d'exécution
    auto start = std::chrono::high_resolution_clock::now();

    // Rechercher le meilleur chemin
    Villes *path = new Villes();
    researchBestPath(startingVille, path, 0);
    delete path;

    // Afficher le temps d'exécution
    auto end_calcul = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_calcul - start);
    std::cout << "The calculation required : " << duration.count() << " microseconds" << std::endl;

    // Afficher le résultat
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
    // Vérifier si la ville actuelle a déjà été visitée
    Ville *ville_already_visited = path->find(current_ville->getName());
    path->addVille(current_ville);

    // Vérifier si le chemin actuel est plus long que le chemin le plus court trouvé jusqu'à présent
    if (shortest_distance != -1 && current_distance > shortest_distance) {
        return;
    }

    // Vérifier si toutes les villes ont été visitées et si la ville actuelle est la ville de départ
    if (path->getSize() == all_villes.getSize() && current_ville == startingVille) {
        // Vérifier si le chemin actuel est plus court que le chemin le plus court trouvé jusqu'à présent
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

    // Vérifier si la ville actuelle a déjà été visitée
    if (ville_already_visited != nullptr) {
        return;
    }
}