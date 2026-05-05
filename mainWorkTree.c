#include <stdio.h>
#include <stdlib.h>
#include "workTree.h"

int main() {

/*
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

        wt->tab[i].name = strdup(filename);
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


// **********************************

    WorkTree* wt = initWorkTree();

    int n;

    printf("Combien de fichiers à ajouter ? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        char name[256];
        char hash[256];
        int mode;

        printf("\n--- Fichier %d ---\n", i + 1);

        printf("Nom : ");
        scanf("%255s", name);

        printf("Hash : ");
        scanf("%255s", hash);

        printf("Mode : ");
        scanf("%d", &mode);

        int r = appendWorkTree(wt, name, hash, mode);

        printf("Ajout résultat : %d\n", r);
    }

    printf("\nContenu du WorkTree :\n");
    for (int i = 0; i < wt->n; i++) {
        printf("  [%d] %s\n", i, wt->tab[i].name);
    }
    */
    WorkTree* wt = initWorkTree();
    appendWorkTree(wt, "main.c",  "abc123", 644);
    appendWorkTree(wt, "utils.c", "def456", 755);
    appendWorkTree(wt, "readme",  "NULL",    0);

    char* str = wtts(wt);
    printf("WorkTree en string :\n%s\n", str);

    free(str);
    

    return 0;
}
