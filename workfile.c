#include<stdio.h>
#include<stdlib.h>
#include <dirent.h>
#include "workfile.h"



WorkFile* createWorkFile(char* name)
{
    WorkFile* wf = (WorkFile*) malloc(sizeof(WorkFile));

    wf->name = name;   // on stocke le nom
    wf->hash = NULL;   // pas encore calculé
    wf->mode = 0;      // permissions initialisées à 0

    return wf;
}

char* wfts(WorkFile* wf)
{
    char* hash;   //  déclaration

    if (wf->hash == NULL)
        hash = "";
    else
        hash = wf->hash;

    int size = strlen(wf->name) + strlen(hash) + 20;

    char* str = (char*) malloc(size);

    sprintf(str, "%s\t%s\t%d", wf->name, hash, wf->mode);

    return str;
}

WorkFile* stwf(char* ch) {
    WorkFile* wf = malloc(sizeof(WorkFile));
    char* tmp = strdup(ch);   // copie car strtok MODIFIE la chaîne originale

    char* token = strtok(tmp, "\t");          // découpe au 1er \t → name
    wf->name = strdup(token);

    token = strtok(NULL, "\t");               // découpe au 2ème \t → hash
    wf->hash = strcmp(token, "NULL") == 0 ? NULL : strdup(token);
    //         si le texte est "NULL" → on remet NULL (pointeur)

    token = strtok(NULL, "\t");               // découpe au 3ème \t → mode
    wf->mode = atoi(token);                   // convertit "644" → 644

    free(tmp);
    return wf;
}
