#include <stdio.h>
#include <stdlib.h>
#include "workfile.h"

int main()
{
    char name[100];

    printf("Donner le nom du fichier: ");
    scanf("%s", name);

    WorkFile* wf = createWorkFile(name);

    char* result = wfts(wf);

    if (result == NULL)
    {
        printf("Erreur conversion\n");
    }
    else
    {
        printf("Resultat: %s\n", result);
        free(result); // مهم
    }

    return 0;
}
