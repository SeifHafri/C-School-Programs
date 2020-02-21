#include <stdio.h>
#include <stdlib.h>
int main()
{
FILE *fichier=NULL;

fichier = fopen("test.txt","w");
if (fichier!=NULL)
{
    fprintf(fichier,"ousssma bouchiara");
}
else {
    printf("il y'a eu une erreur");
}
return 0;
}
