#include <stdlib.h>
#include <stdio.h>
#include <math.h>
typedef struct Maillon
{
    int val;
    struct Maillon *suiv;
}Maillon;

 void Allouer (Maillon **nouveau)
{  *nouveau=( Maillon*) malloc( sizeof( Maillon)); }
void Aff_Val( Maillon *P, int v)
{ P->val=v; }
void Aff_Adr(  Maillon *P,  Maillon *Q)
{ P->suiv = Q; }
 Maillon *Suivant(  Maillon *P)
{ return( P->suiv ); }
int Valeur(  Maillon *P)
{ return( P->val) ; }
void Liberer(Maillon **P)
{
    free(*P);
    *P=NULL;
}
void afficher( Maillon *P)
    {

    while (P != NULL)
    {
        printf("%d =>",Valeur(P));
        P=Suivant(P);
    }
    printf("NULL");
    }
int main()
{
    Maillon *tete,*P,*Q;int i,C,n;
    Allouer(&tete);
    P=tete;
    printf("donner le degree du polynome :\n ");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        printf("Donner le coefficient du terme degree %d\n",i);
        scanf("%d",&C); //le continue
        Aff_Val(P,C);
        Allouer(&Q);Aff_Adr(P,Q);
        P=Q;
    }
    Aff_Val(P,0);
    Aff_Adr(P,NULL);
    afficher(tete);
    printf("\nDonner la Valeur du point X SVP\n");
    P=tete;
    int R=0;i=0;
    int X=0;
    scanf("%d",&X);
    while(P!=NULL)
    {
        R=(Valeur(P)*(pow(X,i))+R);
        i++;
        P=Suivant(P);
    }
    printf("le resultat est: %d\n",R);
    return 0;
}


