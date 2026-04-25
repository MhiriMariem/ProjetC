#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {

    printf("===== SAISIE LISTE =====\n");

    char s[1000];
    char file[100];
    char dest[100];
        char src[100];
    printf("Entrer une liste (ex: A|B|C) : ");
    scanf("%s", s);

    List* L = stol(s);

    printf("\n===== LISTE =====\n");
    ltos(L);

    printf("\n===== TEST LISTGET =====\n");
    int i;
    printf("Donner index : ");
    scanf("%d", &i);

    Cell* c = listGet(L, i);
    if (c != NULL)
        printf("Element index %d : %s\n", i, c->data);
    else
        printf("indice invalide\n");

    printf("\n===== TEST SEARCH =====\n");
    char mot[100];
    printf("Mot a chercher : ");
    scanf("%s", mot);

    Cell* r = searchList(L, mot);
    if (r != NULL)
        printf("Trouve : %s\n", r->data);
    else
        printf("Non trouve\n");

    printf("\n===== SAUVEGARDE =====\n");
    ltof(L, "file.txt");
    printf("Sauvegarde OK\n");

    printf("\n===== LECTURE FICHIER =====\n");
    List* L2 = ftol("file.txt");

    printf("Liste relue : ");
    ltos(L2);

    printf("\n===== TEST LISTDIR =====\n");

    List* Ldir = listdir(".");

    if (Ldir != NULL)
    {
        printf("Contenu dossier courant :\n");
        ltos(Ldir);
    }
    else
    {
        printf("Erreur ouverture dossier\n");
    }

    printf("\n===== TEST FILE EXISTS =====\n");

    printf("Entrer le nom du fichier a verifier : ");
    scanf("%s", file);

    if (file_exists(file))
       printf("%s existe\n", file);
    else
       printf("%s n'existe pas\n", file);
       
      //------------------------------------------------
       
 printf("Source : ");
scanf("%s", src);

FILE *test = fopen(src, "r");

if (test == NULL) {
    printf("Erreur: fichier source introuvable\n");
} else {

    fclose(test);

    printf("Destination : ");
    scanf("%s", dest);

    cp(dest, src);

    printf("Copie terminée\n");
}

printf("\n===== TEST HASHTOPATH =====\n");

char hash[200];

printf("Entrer un hash : ");
scanf("%s", hash);

char* path = hashToPath(hash);

printf("Chemin genere : %s\n", path);

// si malloc utilisé → libérer la mémoire
free(path);

 // ----------------------------
    printf("\n===== TEST BLOBFILE (Q-3.5) =====\n");

    printf("Entrer fichier a sauvegarder (snapshot) : ");
    scanf("%s", file);

    if (file_exists(file)) {
        blobFile(file);
        printf("Snapshot cree avec succes\n");
    } else {
        printf("Fichier introuvable\n");
    }
    return 0;
}
