#include<stdio.h>
#include<stdlib.h>
#include <dirent.h>
#include "list.h"

// 🔹 créer une liste vide
List* initList()
{
    List* L = (List*) malloc(sizeof(List));
    *L = NULL;
    return L;
}

// 🔹 créer cellule
Cell* buildCell(char* ch)
{
    Cell* c = (Cell*) malloc(sizeof(Cell));
    c->data = ch;
    c->next = NULL;
    return c;
}

void insertFirst(List *L, Cell *C) {

    C->next = *L;  // le nouveau noeud pointe vers l'ancienne tête
    *L = C;        // mise à jour de la tête de liste
}


char* ctos(Cell* c) {
   
    return c->data;               // retourne la chaîne contenue dans la cellule
}


void ltos(List* L) {
    Cell* tmp = *L;   // pointeur temporaire pour parcourir la liste
    while (tmp != NULL) {
        printf("%s", ctos(tmp));       // afficher la chaîne de la cellule
        if (tmp->next != NULL) printf("|"); // ajouter séparateur si pas la dernière cellule
        tmp = tmp->next;               // avancer vers la cellule suivante
    }
    printf("\n"); // retour à la ligne à la fin
}

Cell* listGet(List* L, int i) {

    if (i <= 0) return NULL;                   // indice invalide

    Cell* tmp = *L;   // pointeur temporaire pour parcourir la liste
    int k = 1;

    while (tmp != NULL && k < i) {
        tmp = tmp->next;   // avancer vers la cellule suivante
        k++;               // incrémenter le compteur
    }

    return tmp; // soit la cellule trouvée, soit NULL si fin de liste
}

Cell* searchList(List* L, char* str) {

    Cell* tmp = *L;   // pointeur temporaire pour parcourir la liste
    while (tmp != NULL) {
        if (strcmp(ctos(tmp), str) == 0) {
            return tmp; // trouvé : on renvoie la cellule
        }
        tmp = tmp->next; // avancer vers la cellule suivante
    }

    return NULL; // pas trouvé
}

List* stol(char* s) {
    List* L = initList();

    char* ch = strtok(s, "|");

    while (ch != NULL) {
        Cell* c = buildCell(ch);
        insertFirst(L, c);

        ch = strtok(NULL, "|");
    }

    return L;
}

void ltof(List* L, char* path) {
    FILE* f = fopen(path, "w");

    if (f == NULL) return;

    Cell* tmp = *L;

    while (tmp != NULL) {
        fprintf(f, "%s", ctos(tmp));

        if (tmp->next != NULL)
            fprintf(f, "|");

        tmp = tmp->next;
    }

    fclose(f);
}

List* ftol(char* path) {
    FILE* f = fopen(path, "r");

    if (f == NULL) return NULL;

    char T[1000];

    fscanf(f, "%s", T);

    fclose(f);

    return stol(T);
}


List* listdir(char* root_dir)
{
    DIR *dp = opendir(root_dir);
    struct dirent *ep;

    if (dp == NULL)
        return NULL;

    List* L = initList();

    while ((ep = readdir(dp)) != NULL)
    {
        Cell* c = buildCell(ep->d_name);
        insertFirst(L, c);
    }

    closedir(dp);

    return L;
}

int file_exists(char *file)
{
    FILE *f = fopen(file, "r");

    if (f == NULL)
        return 0;   // n'existe pas

    fclose(f);
    return 1;       // existe
}


void cp(char *to, char *from)
{
    // Vérifier si le fichier source existe
    if (!file_exists(from))
    {
        printf("Erreur : fichier source inexistant\n");
        return;
    }

    FILE *src = fopen(from, "r");
    FILE *dest = fopen(to, "w");

    if (src == NULL || dest == NULL)
    {
        printf("Erreur ouverture fichier\n");
        return;
    }

    char Tab[1024];

    // lecture ligne par ligne
    while (fgets(Tab, sizeof(Tab), src) != NULL)
    {
        fputs(Tab, dest);
    }

    fclose(src);
    fclose(dest);
}


char* hashToPath(char* hash)
{
    int len = strlen(hash);

    char* path = (char*)malloc(len + 3); // '/' + '\0'

    if (path == NULL)
        return NULL;

    // copier les 2 premiers caractères
    path[0] = hash[0];
    path[1] = hash[1];

    // ajouter '/'
    path[2] = '/';

    // copier le reste
    strcpy(path + 3, hash + 2);

    return path;
}

void blobFile(char* file)
{
    char* hash = sha256file(file);

    if (hash == NULL) {
        printf("Erreur hash\n");
        return;
    }

    char* dir = hashToPath(hash);

    char cmd[300];

    // créer dossier
    sprintf(cmd, "mkdir -p %s", dir);
    system(cmd);

    // construire chemin complet fichier
    char dest[400];
    sprintf(dest, "%s/%s", dir, file);

    // copier fichier
    cp(dest, file);

    printf("Snapshot cree dans %s\n", dest);
}


