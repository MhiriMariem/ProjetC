#ifndef WORKTREE_H
#define WORKTREE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "workfile.h"

typedef struct {
WorkFile* tab;
int size;
int n;
} WorkTree;

WorkTree* initWorkTree();

int inWorkTree(WorkTree* wt, char* name);
#endif
