## Voyageur de commerce 
### Implémentation de l'algorithme du proche voisin

## Explication du code 

### Fichier ville/ville.cpp :

Le fichier ville.cpp définit la classe Ville, qui représente une ville avec ses voisins et leurs distances.

#### Logique du code ville/ville.cpp :

Ici on initialise une ville avec un nom et une distance. Le code permet d'ajouter des voisins avec des distances, affiche les voisins récursivement avec leurs distances, et permet de trouver un voisin par son nom. La fonction de destructeur est actuellement commentée car il n'y a pas d'allocation dynamique de mémoire nécessitant une libération explicite.

### Fichier ville/ville.h :

Le fichier ville.h définit la classe Ville, représentant une ville avec ses voisins et leurs distances, ainsi que les méthodes pour gérer ces relations.

#### Logique du code ville/ville.h :

La classe Ville contient des membres pour le nom, les voisins et les distances, ainsi que des méthodes pour ajouter des voisins, afficher les voisins récursivement, trouver un voisin par son nom et obtenir la liste des voisins. La modification du type de retour de la méthode getVoisins est effectuée pour correspondre à la structure de stockage des voisins.

### Fichier ville/villes.cpp :

Le fichier villes.cpp implémente les méthodes de la classe Villes, permettant de gérer une collection de villes et d'effectuer des opérations telles que l'ajout, la suppression et la recherche de villes.

#### Logique du code ville/villes.cpp :

La classe Villes contient des méthodes pour gérer une collection de villes, y compris l'ajout, la suppression et la recherche de villes, ainsi que des méthodes pour afficher les noms des villes et libérer la mémoire allouée pour les villes. La méthode de copie du constructeur Villes est utilisée pour créer une copie des objets Villes.

### Fichier ville/villes.h :

Le fichier villes.h définit la classe Villes, qui représente une collection de villes et fournit des méthodes pour ajouter, supprimer, rechercher et afficher des villes, ainsi que pour libérer la mémoire allouée pour les villes.

### Logique du code ville/villes.h :

La classe Villes maintient un vecteur de pointeurs vers des objets Ville, offrant des fonctionnalités pour gérer cette collection, y compris l'ajout, la suppression, la recherche et l'affichage des villes. Les méthodes addVille() permettent d'ajouter des villes par nom ou par pointeur, tandis que la méthode find permet de rechercher une ville par son nom. La méthode free libère la mémoire allouée pour les villes à la destruction de l'objet Villes.

### Main.cpp

Le fichier main.cpp contient la fonction principale main qui charge les données des villes à partir d'un fichier, permet à l'utilisateur de sélectionner une ville de départ, recherche le chemin le plus court entre les villes, puis affiche le résultat avec le temps de calcul.

#### Logique du code Main.cpp :

Le programme charge les données des villes à partir d'un fichier et permet à l'utilisateur de sélectionner une ville de départ. Ensuite, il utilise un algorithme récursif pour trouver le chemin le plus court entre les villes en explorant toutes les possibilités. Le temps de calcul est mesuré pour évaluer les performances de l'algorithme.

