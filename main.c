#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<unistd.h>

int hashFile(char* source, char* dest)
{
static char template[] ="/tmp/myfileXXXXXX";
char fname [1000];
char cmd[300];
char c;

strcpy(fname,template);
int fd = mkstemp(fname);
if(fd== -1)
return -1;
close(fd);

snprintf(cmd, sizeof(cmd),"sha256sum \"%s\" > \"%s\"",source, dest);
return system(cmd);
FILE *src =fopen(fname,"r");
FILE *dst =fopen(dest,"w");

if(src==NULL || dst ==NULL)
return -1;
while((c=fgetc(src))!= EOF)
{fputc(c,dst);
}
fclose(src);
fclose(dst);

remove(fname);
}
char* sha256file(char* file)
{
    static char template[] = "/tmp/hashXXXXXX";
    char tmp[1000];
    char cmd[1000];

    strcpy(tmp, template);

    int fd = mkstemp(tmp);
    if(fd == -1)
        return NULL;

    close(fd);

    // pipe + redirection vers fichier temporaire
    snprintf(cmd, sizeof(cmd), "cat \"%s\" | sha256sum > \"%s\"", file, tmp);
    system(cmd);

    FILE* f = fopen(tmp, "r");
    if(f == NULL)
        return NULL;

    static char hash[100];

    fscanf(f, "%s", hash);

    fclose(f);
    remove(tmp);

    return hash;
} 
int main(){
hashFile("main.c","file.tmp");
return 0;
}
