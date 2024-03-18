## Voyageur de commerce 
### Implémentation d' l'algorithme du proche voisin

## Explication du code 

### Fichier ville/ville.cpp :

Ce fichier implémente la classe Ville qui représente une ville dans un contexte de recherche de chemin optimal.

#### Logique du code ville/ville.cpp :

La classe Ville permet de créer des objets représentant des villes et de gérer leurs relations avec les villes voisines. Elle offre des fonctionnalités pour ajouter des voisins, rechercher des voisins par leur nom, récupérer la liste des voisins et afficher les informations de la ville et de ses voisins en arborescence.

### Fichier ville/ville.h :

Le fichier ville.h est un en-tête qui déclare la classe Ville et ses fonctions membres.

#### Logique du code ville/ville.h :

Le fichier d'en-tête ville.h permet aux autres fichiers source du projet d'utiliser la classe Ville sans avoir accès à son implémentation interne (définie dans ville.cpp). Les fonctions membres publiques définissent l'interface de la classe Ville et ce que les autres parties du code peuvent utiliser.

### Fichier ville/villes.cpp :

Le fichier villes.cpp implémente la classe Villes pour gérer un ensemble de villes.

#### Logique du code ville/ville.cpp :

La classe Villes implémente les fonctionnalités de gestion d'un ensemble de villes. Le code semble correct et fonctionnel, mais le constructeur par copie nécessite une modification pour effectuer une copie profonde et éviter les problèmes de mémoire.

### Fichier ville/villes.h :

Le fichier villes.h est un en-tête qui déclare la classe Villes et ses fonctions membres. Cette classe permet de gérer un ensemble de villes.

### Fichier ville/villes.h :

La classe Villes fournit des fonctionnalités pour gérer une collection de villes. Elle permet d'ajouter, supprimer, rechercher et afficher des villes.

### Main.cpp

Le fichier main.cpp implémente la logique principale du programme permettant de trouver le chemin le plus court entre des villes.

#### Logique du code Main.cpp :

Dans l'ensemble, le code implémente une approche de type backtracking avec une recherche en profondeur (DFS) pour explorer tous les chemins possibles à partir de la ville de départ et visiter toutes les villes exactement une fois. Il garde une trace de la plus courte distance trouvée jusqu'à présent et met à jour le meilleur chemin si un chemin plus court est découvert.

