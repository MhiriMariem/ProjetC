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
