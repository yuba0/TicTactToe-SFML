# TicTactToe-SFML
Jeu de Tic Tac Toe avec interface graphique en C++ utilisant SFML
# Tic Tac Toe - SFML

Ce projet est un jeu de Tic Tac Toe avec une interface graphique développée en C++ en utilisant la bibliothèque SFML. Le jeu est conçu pour deux joueurs qui s'affrontent pour obtenir trois symboles identiques alignés dans une grille de 3x3.

## Description

L'application propose une interface graphique simple où les joueurs peuvent tour à tour placer leurs symboles (`X` et `O`). Le jeu détecte automatiquement les conditions de victoire (trois symboles alignés) ou de match nul lorsque la grille est remplie sans gagnant.

## Fonctionnalités

- Interface graphique intuitive utilisant SFML.
- Alternance des tours entre deux joueurs.
- Détection de la victoire ou du match nul.
- Affichage du résultat (victoire ou match nul) à la fin de chaque partie.
- Redémarrage facile du jeu (si cette fonctionnalité est présente).

## Technologies Utilisées
Langage : C++
Bibliothèque : SFML (Simple and Fast Multimedia Library) pour l’interface graphique, la gestion des événements et le rendu.
CMake : Outil pour gérer la compilation du projet.


## Installation

### Prérequis

- **Compilateur C++** compatible avec C++17 ou version supérieure.
- **SFML 2.5** : Téléchargez et installez la bibliothèque SFML en suivant les instructions sur le site officiel : [SFML Download](https://www.sfml-dev.org/download.php).

### Instructions de Compilation

1. **Clonez le dépôt GitHub** :

   ```bash
   git clone https://github.com/ton-utilisateur/TicTacToe-SFML.git
   cd TicTacToe-SFML
2. **Configuration de la police de caractères** :
   '''bash 	
   Copiez le fichier de police OpenSans-Regular.ttf dans le dossier build. Ce fichier est nécessaire pour afficher le texte dans l'interface graphique.

3. **Créez un dossier de build et compilez le projet** :
   '''bash  
     mkdir build
     cd build
     cmake ..
     make

4. **Execution du jeu** : 
./TicTacToeSFML



