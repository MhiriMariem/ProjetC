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
