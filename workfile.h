#ifndef WORKFILE_H
#define WORKFILE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
char* name;
char* hash;
int mode;
} WorkFile;

typedef struct {
WorkFile* tab;
int size;
int n;
} WorkTree;

WorkFile* createWorkFile(char* name);

char* wfts(WorkFile* wf);


#endif
