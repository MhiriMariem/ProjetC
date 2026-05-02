#include <stdio.h>
#include <stdlib.h>
#include "workTree.h"

int main() {

  int n;
    WorkTree* wt = initWorkTree();

    do {
    printf("Saisir la taille du tableau : ");
    scanf("%d", &n);
  } while (n <= 0 || n > wt->size);
    
   

    // Ajout dynamique des fichiers
    for (int i = 0; i < n && i < wt->size; i++) {
        char filename[256];
        printf("Nom du fichier %d : ", i+1);
        scanf("%255s", filename);

        wt->tab[i].name = strdup(filename); // copie dynamique du nom
        wt->n++;
    }

    // Recherche dynamique
    char search[256];
    printf("Entrez le nom d'un fichier à rechercher : ");
    scanf("%255s", search);

    int pos = inWorkTree(wt, search);
    if (pos != -1)
        printf("%s trouvé à la position : %d\n", search, pos);
    else
        printf("%s n'est pas dans le WorkTree\n", search);

    // Libération mémoire
    for (int i = 0; i < wt->n; i++) {
        free(wt->tab[i].name);
    }
    free(wt->tab);
    free(wt);

    return 0;
}
