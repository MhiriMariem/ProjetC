
#include<stdio.h>
#include<stdlib.h>
#include <dirent.h>
#include "workTree.h"

#define WORKTREE_SIZE 100 

WorkTree* initWorkTree() {
    WorkTree* wt = malloc(sizeof(WorkTree));
    wt->tab  = malloc(sizeof(WorkFile) * WORKTREE_SIZE);
    wt->size = WORKTREE_SIZE;
    wt->n    = 0;
    return wt;
}

int inWorkTree(WorkTree* wt, char* name) {
    for (int i = 0; i < wt->n; i++)           // parcourt tous les éléments
        if (strcmp(wt->tab[i].name, name) == 0) // compare les noms
            return i;                            // trouvé → retourne la position
    return -1;                                   // pas trouvé → retourne -1
}

int appendWorkTree(WorkTree* wt, char* name, char* hash, int mode) {
    if (inWorkTree(wt, name) != -1) return 0; // déjà présent
    if (wt->n >= wt->size)         return -1; // tableau plein

    wt->tab[wt->n].name = strdup(name);
    wt->tab[wt->n].hash = hash ? strdup(hash) : NULL;
    wt->tab[wt->n].mode = mode;
    wt->n++;
    return 1;
}

//*****************************************

char* wtts(WorkTree* wt) {

    // 1️⃣ On calcule la taille totale nécessaire pour la chaîne finale
    // On commence à 1 pour le caractère '\0' de fin de chaîne
    int total = 1;

    // Parcours de tous les fichiers du WorkTree
    for (int i = 0; i < wt->n; i++) {

        // On convertit chaque fichier en chaîne avec wfts
        char* s = wfts(&wt->tab[i]);

        // On ajoute la taille de cette chaîne +1 pour le '\n'
        total += strlen(s) + 1;

        // On libère la chaîne temporaire (car on n'en a plus besoin)
        free(s);
    }

    // 2️⃣ Allocation de la chaîne finale
    char* result = malloc(total);

    // On initialise la chaîne vide (important pour strcat)
    result[0] = '\0';

    // 3️⃣ Construction de la chaîne finale
    for (int i = 0; i < wt->n; i++) {

        // Conversion de chaque fichier en string
        char* s = wfts(&wt->tab[i]);

        // On ajoute la ligne dans la chaîne finale
        strcat(result, s);

        // On ajoute un saut de ligne
        strcat(result, "\n");

        // On libère la chaîne temporaire
        free(s);
    }

    // 4️⃣ On retourne la chaîne finale
    return result;
}
