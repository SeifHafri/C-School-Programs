#include <stdio.h>
#include <stdlib.h>
typedef struct Maillon { int val; struct Maillon *next;} Maillon;
void allouer(Maillon **nouveau)
{ *nouveau=(Maillon*)malloc(sizeof(Maillon));}

void aff_adr(Maillon *p,Maillon *q)
{p->next=q;}

void aff_val(Maillon *p, int valeur)
{ p->val=valeur;}

Maillon *suivant(Maillon *p)
{return p->next;}

int valeur(Maillon *p)
{return p->val;}

void liberer(Maillon**ancien)
{free(*ancien); *ancien=NULL;}

Maillon *creation(int n)
{
Maillon *tete,*p,*q; int i,v;
allouer(&p);
printf("veuillez remplir la liste SVP");
scanf("%d",&v);
 aff_val(p,v);
  tete=p;
for (i=1; i<n; i++)
{
allouer(&q);
scanf("%d",v);
aff_val(q,v);
aff_adr(p,q);
p=q;
v=0;
}
aff_adr(p,NULL);
return tete;
}
void afficher(Maillon *p)
{
while(p!=NULL)
{printf("%d ",valeur(p));
 p=suivant(p);}
}
int main()
{
    int n;
    printf("donner le nombre d'elements dde la liste");
    scanf("%d",&n);
Maillon *tete;
tete=creation(n);
afficher(tete);
printf("Hello world!\n");
return 0;
}
