#include<stdio.h>
#include<stdlib.h>

List* initList()
{Liste* L=(List*)malloc(sizeof(List));
*L=NULL;
return L;
}



Cell* buildCell(char* ch) {
    Cell* c = (Cell*) malloc(sizeof(Cell));
 

    c->data = ch;
 
 

    c->next = NULL;

    return c;
}

void insertFirst(Cell **L, Cell *C) {


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

    if (i < 0) return NULL;                   // indice invalide

    Cell* tmp = *L;   // pointeur temporaire pour parcourir la liste
    int k = 0;

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

