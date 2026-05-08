#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "workTree.h"

int main() {

    // --- Première partie : création statique ---
    WorkTree* wt = initWorkTree();

    // Ajout manuel des fichiers
    appendWorkTree(wt, "nour.c", "abc111", 644);
    appendWorkTree(wt, "selmi.c", "def222", 755);
    appendWorkTree(wt, "mhiri.c", NULL, 0);


    // Recherche statique
    char search[] = "mhiri.c";

    int pos = inWorkTree(wt, search);

    if (pos != -1)
        printf("%s trouvé à la position : %d\n", search, pos);
    else
        printf("%s n'est pas dans le WorkTree\n", search);

    // --- Deuxième partie : appendWorkTree ---
    
    appendWorkTree(wt, "file1.c",  "abc123", 644);
    appendWorkTree(wt, "file2.c", "def456", 755);
    appendWorkTree(wt, "file3.c",  NULL,     0);

    printf("\n===== Contenu du WorkTree (%d fichier(s)) =====\n", wt->n);

    for (int i = 0; i < wt->n; i++) {
        printf("[%d] Nom: %s | Hash: %s | Mode: %d\n",
               i,
               wt->tab[i].name,
               wt->tab[i].hash ? wt->tab[i].hash : "NULL",
               wt->tab[i].mode);
    }

    // --- Troisième partie : test wtts ---

    char* str = wtts(wt);

    printf("\nWorkTree en string :\n%s\n", str);
    
    // --- 4eme partie : test chwt ---

    // Sérialisation
    printf("Chaîne produite :\n%s\n", str);

    // Reconstruction depuis la chaîne
    WorkTree* wt2 = chwt(str);
    printf("WorkTree reconstruit (%d fichier(s)) :\n", wt2->n);
    for (int i = 0; i < wt2->n; i++)
	 printf("[%d] %s | %s | %d\n",
		   i,
		   wt2->tab[i].name,
		   wt2->tab[i].hash ? wt2->tab[i].hash : "NULL",
		   wt2->tab[i].mode);


    // --- 5eme partie : test wttf ---
    int r = wttf(wt, "worktree.txt");
    if (r == 0)
        printf("WorkTree écrit dans worktree.txt\n");
    else
        printf("Erreur d'écriture\n");

    // --- 6eme partie : test wttf ---
    WorkTree* wt_file = ftwt("worktree.txt");
    if (!wt_file) {
        printf("Impossible d'ouvrir worktree.txt\n");
        return 1;
    }

    printf("WorkTree chargé depuis fichier (%d fichier(s)) :\n", wt->n);
    for (int i = 0; i < wt->n; i++)
        printf("  [%d] %s | %s | %d\n",
               i, wt->tab[i].name,
               wt->tab[i].hash ? wt->tab[i].hash : "NULL",
               wt->tab[i].mode);
    // --- Libération mémoire ---

    free(str);

    for (int i = 0; i < wt->n; i++) {
        free(wt->tab[i].name);

        if (wt->tab[i].hash != NULL)
            free(wt->tab[i].hash);
    }

    free(wt->tab);
    free(wt);

    return 0;
}
