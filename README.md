# TD: C

- [TD: C](#td-c)
    - [Notes & Cours](#notes-cours)
        - [gcc](#gcc)
            - [Compilation](#compilation)
            - [Execution](#execution)
            - [Options](#options)
    - [Fonction main](#fonction-main)
    - [Fonction rand](#fonction-rand)
        - [Graine](#graine)
        - [Valeurs](#valeurs)
    - [Pointeurs](#pointeurs)
        - [Definition de pointeur](#definition-de-pointeur)
        - [Utilisation](#utilisation)
        - [Cas des tableaux](#cas-des-tableaux)
    - [Charte de nommage](#charte-de-nommage)
    - [Exercices](#exercices)
        - [Compilation](#compilation)

## Notes & Cours

### gcc

gcc (**GNU C Compiler**) est un compilateur C, il permet de convertir le C en binaire

#### Compilation

Compiler un fichier .c:

```bash
gcc fichier.c
```

La sortie sera par défaut *a.out* si celui-ci n'existe pas déjà

#### Execution

Executer le fichier compilé:

```bash
./a.out
```

#### Options

```bash
gcc fichier.c -o fichier_de_sortie # Permet de choisir le fichier de sortie
gcc fichier.c -lm # En cas d'utilisation de math.h
```

## Fonction main

`main` est la fonction exécutée automatiquement par défaut lorsque le code est lancé, on peut y récupérer les arguments donnés en entrée:

```c
int main(int argc, char *argv[]) {
    // argc: Contient le nombre d'arguments donnés en entrée
    // argv: Contient les arguments donnés en entrée sous forme d'un tableau de tableaux de caractères

    // Par défaut (sans arguments):
    //  argc = 1
    //  argv[0] = Nom de votre script

    return 0; // Valeur de sortie
}
```

Aussi bien qu'on puisse traiter les arguments en entrée, on peut donner une valeur de sortie pour les programmes qui appellent le code: `return 0` signifie qu'il n'y a pas eu d'erreur et `return 1` renvoie une erreur.

## Fonction rand

### Graine

La "graine" (seed) permet à la fonction rand de changer ses paramètres: la fonction rand prend des valeurs de la graine l'une aprés l'autre à chaque appel

```c
srand(graine); // Définit la "graine" pour la fonction aléatoire
```

On définit donc la graine en fonction du temps, ce qui nous permet d'avoir des valeurs aléatoires différentes à chaques secondes:

```c
srand(time(NULL));
```

### Valeurs

Random entre [0; x[:

```c
rand() % x;
```

Random entre [0; x]:

```c
rand() % (x + 1);
```

Random entre [a; b[:

```c
(rand() % (b - a)) + a;
```

## Pointeurs

Les **pointeurs** permettent manipuler les adresses des variables et aussi de manipuler leurs valeurs en mémoire

### Definition de pointeur

```c
int a =  5;     // a est un entier de valeur 5
int *ptr = &a;  // ptr est un pointeur (*) d'entier (int) pointant vers l'adresse (&) de a
```

### Utilisation

- `*ptr` donne la valeur de a
- `ptr` donne l'adresse de a
- `&a` donne aussi l'adresse de a
- `&ptr` donne l'adresse du pointeur

### Cas des tableaux

Définir un pointeur sur un tableau et incrémenter son adresse permet de parcourir les valeurs du tableau

```c
int tab[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int *ptr = tab; // Avec les tableaux le '&' devant la variable n'est pas nécessaire, un tableau est en arrière-plan, un pointeur

// tab[0] = *(ptr)
// tab[1] = *(ptr + 1)
// tab[x] = *(ptr + x)
```

## Charte de nommage

- **La base**: Ne pas utiliser de chiffres et caractères spéciaux (autre que le "underscore": _) dans les noms de variables, fonctions, structures,...
- **CamelCase**: Commencer les noms d'élement par une miniscule et chaque nouveau mot par une majuscule (ex: `calculDistance`)
- **Constante**: Définir les constances en majuscules (ex: `#define SIZE 10`)

## Exercices

### Compilation

A l'aide d'un `Makefile` la compilation est simplifiée (sous linux):

```bash
make build EXERCICE=1 # Pour compiler l'exercice 1
```

Les fichiers de sorties sont: `exon` avec `n` les numéro de l'exercice