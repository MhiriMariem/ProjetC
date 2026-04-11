#include<stdio.h>
#include<stdlib.h>

List* initList()
{Liste* L=(List*)malloc(sizeof(List));
*L=NULL;
return L;
}
