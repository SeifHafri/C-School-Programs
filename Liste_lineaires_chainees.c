 #include <stdlib.h>
 #include <stdio.h>
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
Maillon *creer_LLC(int n)
{
    int i;
    int v;
     Maillon *Q;
     Maillon *P;
     Maillon *tete;
     Allouer(&P);
     scanf("%d",&v);
     Aff_Val(P,v);
     tete=P;



    for(i=1;i<(n-1);i++)
    {
    Allouer(&Q);
    scanf("%d\n",&v);
    Aff_Val(Q,v);
    Aff_Adr(P,Q);
    Aff_Adr(Q,NULL);
    P=Q;
    }
    Aff_Adr(Q,NULL);



    return tete;


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
int LongueurLLC(Maillon *tete)
{
    Maillon *P;
    P=tete;int cpt=0;
    while (P!=NULL)
    {
        cpt++;
        P=Suivant(P);
    }
    return cpt;
}
Maillon *Acc_pos(Maillon *T, int pos)//returns a pointer to the wanted position
{
    Maillon *P,*L;
    int cpt;
    P=T;
    cpt=1;
    if ((LongueurLLC(P))>=pos)
    {
        while((P!=NULL) && (cpt!=pos))
        {
            P=Suivant(P);
            cpt++;
        }
        L=P;
    }
    else
        {
            printf("position n'existe pas");
            L=NULL;
        }

    return L;

}
void RechL(Maillon *T,int val,Maillon **Prec,Maillon **adr)
{
    Maillon *P;
    P=T;
    int trouv=0;
    *Prec=NULL;
    while((P!=NULL) && (Valeur(P)!=val))
          {
              *Prec=P;
              P=Suivant(P);
          }
    if (Valeur(P)!=val)
        {
            *Prec=NULL;
            *adr=NULL;
        }
    else
    {
        trouv=1;*adr=P;
    }

}


int main ()
{

     Maillon *P,*Prec,*adr;
     Maillon *tete=NULL;
     int n,i;
     printf("donner le nombre d'elements de la liste (terminer par null): ");
     scanf("%d",&n);
    tete=creer_LLC(n+1);
    afficher(tete);
    printf("\n%d",LongueurLLC(tete));
    RechL(tete,13,&Prec,&adr);
    printf("\n%d-%d",Valeur(Prec),Valeur(adr));


    return 0;
}


