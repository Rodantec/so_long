# so_long

so_long est un petit jeu en 2D réalisé avec MiniLibX. Le joueur doit parcourir une carte, récupérer tous les objets et rejoindre la sortie en un minimum de mouvements.

## Objectif

Le projet consiste à :

- charger et vérifier une carte
- afficher les textures du jeu avec MiniLibX
- gérer les déplacements du joueur
- compter les objets récupérés
- refuser les cartes invalides

## Structure

- `so_long.c` : point d'entrée du programme
- `so_long.h` : déclarations et structure principale `t_data`
- `map/` : chargement de la carte, textures et rendu
- `game_control/` : déplacement du joueur et mise à jour de la carte
- `errors/` : vérifications et messages d'erreur
- `gnl/` : lecture de fichiers avec `get_next_line`
- `ft_printf/` : fonctions d'affichage utilisées par le projet
- `mlx/` : MiniLibX
- `maps/` : fichiers de carte de test
- `img/` : images utilisées par le jeu

## Compilation

Depuis la racine du projet :

```bash
make
```

Cela génère l'exécutable `so_long`.

## Commandes Makefile

- `make` : compile le projet
- `make clean` : supprime les fichiers objets
- `make fclean` : supprime les objets et l'exécutable `so_long`
- `make re` : reconstruit le projet depuis zéro

## Lancement

Le programme attend un seul argument, le fichier de carte, par exemple:

```bash
./so_long maps/map.ber
```

## Règles de carte

Le projet vérifie généralement qu'une carte est :

- entourée de murs
- rectangulaire
- contenant un joueur
- contenant au moins une sortie
- contenant au moins un objet à récupérer

## Contrôles

Les déplacements se font au clavier, avec les touches WASD ou les fleches de directions.

## Fonctionnement

- la carte est chargée depuis un fichier texte
- les textures sont appliquées via MiniLibX
- le joueur se déplace case par case
- la sortie s'ouvre après la récupération de tous les objets

## Notes

- Premier projet graphique