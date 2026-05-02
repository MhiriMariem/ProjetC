#include <stdio.h>
#include <stdlib.h>
#include "workfile.h"

int main() {
    char filename[256];
    char str[256];
	

    
    printf("Donner le nom du fichier: ");
    scanf("%s", filename);
   
    printf("Donner la chaine (format: name\\thash\\tmode): ");
    scanf(" %[^\n]", str); 
   

    WorkFile* wf = createWorkFile(filename);
    char* s = wfts(wf);

    printf("Résultat: %s\n", s);
    
    WorkFile* wf1 = stwf(str);

    printf("name : %s\n", wf1->name);
    printf("hash : %s\n", wf1->hash == NULL ? "NULL" : wf1->hash);
    printf("mode : %d\n", wf1->mode);
    


    // Libération mémoire
    free(s);
    free(wf->name);
    free(wf);

    return 0;
}


