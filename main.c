#include<stdio.h>
#include <stdlib.h>
int hashFile(char* source, char* dest)
{
char cmd[300];
sprintf(cmd,"sha256sum %s > %s",source ,dest);
return system(cmd);
}
int main(){
hashFile("main.c","file.tmp");
return 0;
}
