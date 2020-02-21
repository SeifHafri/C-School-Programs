#ifndef _TP_
#define _TP_

////////////////////////////////////////////////////////////////////////////////
////                       DECLARATION DES BIBLIOTHEQUES                    ////
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


////////////////////////////////////////////////////////////////////////////////
////                       DECLARATION DES FONCTIONS                        ////
////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////
////                     FONCTIONS DE TP                   ////
///////////////////////////////////////////////////////////////


void affich_fich(void);
void affich_fich2(char* chemin);
void Creer_fich(void);
void concatene(void);
void traduction_c_fr(void);
void traduction_fr_c(void);
void stat(void);
void encrypt(void);
void decrypt(void);
void encrypt0(FILE* file,FILE* filec ,int crypto);
void decrypt0(FILE* filec,FILE* filed,int key);
int gen(const char *key);





///////////////////////////////////////////////////////////////
////                         DESIGN                        ////
///////////////////////////////////////////////////////////////
void color(int couleurDuTexte, int couleurDeFond); //marche bien
void intro(void);                                  //marche bien
void menu(void);                                   //marche bien
int choix1(void);


////////////////////////////////////////////////////////////////////////////////
////                     IMPLEMENTATION DES FONCTIONS                       ////
////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
////                     FONCTIONS DE TP                   ////
///////////////////////////////////////////////////////////////


int gen(const char *key) {

 		int i=0;
 		int valeur = 0;
 		for(i=0;i<sizeof(key);i++) {
 			valeur += key[i];
		 }
		 valeur %= 128 ;
		 return valeur;
	 }


void encrypt0(FILE* file,FILE* filec ,int crypto) {
	char c;
	while(!(feof(file))){

		c=fgetc(file);
		if(c!= EOF) {
			if(c>=0 && c<=32 || c == '#') {
				c+=50;
				fputc('#',filec);
			}

			c+=crypto;

			fputc(c,filec);

		}
		else {
			break;
		}
	}
	printf("\n           crypte avec succes");
	}
void decrypt0(FILE* filec,FILE* filed,int key) {
		unsigned char c;
		while(!(feof(filec))){


			c=fgetc(filec);
			if(c!=EOF) {
				if (c == '#') {
					c=fgetc(filec);
					c-=50;
				}
				c-=key;

				fputc(c,filed);
			}
			else {
				printf("        fichier parcourue");
			}
	}
		printf("\n       decrypter avec succe.");

	}
void affich_fich(void)
{
    char chemin[50];

    color(11, 16);
    printf("\n                        - affichage des fichiers - \n\n");

    color(14, 16);
    printf("\n\n\n             - inserer le chemin du fichier : ");

    color(15, 16);
    scanf("%s", &chemin);
    system("cls");
    color(14, 16);
    printf("\n ________________________________________________________________________\n\n");

    color(15, 16);

    FILE *fic = fopen(chemin, "r+");

    char c;

    if (fic != NULL)
    {
      for ( c = getc(fic) ; c != EOF ; c = getc(fic)){
      	printf("%c",c);

      }
    }

    fclose(fic);
    color(14, 16);
    printf("\n ________________________________________________________________________\n");
}

///////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void affich_fich2(char* chemin)
{



    color(11, 16);
    printf("\n                        - affichage du fichier - ");

    FILE *fic = fopen(chemin, "r+");

    color(14, 16);
    printf("\n ________________________________________________________________________\n\n");

    color(15, 16);

    char c;

   // if (fic != NULL)
    //{


      c = getc(fic);
      for ( ; c != EOF ; c = getc(fic)) {
      	printf("%c",c );

      }
    //}

    fclose(fic);
    color(14, 16);
    printf("\n ________________________________________________________________________\n");
}

///////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void Creer_fich(void)
{
    char chemin[50];
    color(11, 16);
    printf("\n                        - Creation des fichiers - \n\n");

    color(14, 16);
    printf("\n\n\n             - Inserer le chemin du fichier : ");

    color(15, 16);
    scanf("%s", &chemin);

    FILE *fic = fopen(chemin, "w");

    printf(" \n\n             - Le fichier est Cree.");
}

///////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void concatene(void)
 {
  char name1[50] , name2[50] ;

   color(11, 16);
   printf("\n                        - Concatenation des fichiers - \n\n");

   color(14, 16);
   printf("\n\n\n             - Inserer le chemin du fichier numero 1 : ");
   color(15, 16);
   scanf("%s",&name1);
   FILE* file1 = fopen(name1,"r");

  color(14, 16);
  printf("\n             - Inserer le chemin du fichier numero 2 : ");
  color(15, 16);
  scanf("%s",&name2);

  FILE* file2 = fopen(name2,"a");
  char c;


   if (file1 != NULL)
    {
      fputs("\n",file2);
      c = getc(file1);

      for (; c != EOF ; c = getc(file1))
         fputc(c,file2);

      affich_fich2(name2);
    }
    else{
      printf("\n\n             - Le fichier 1 est vide.\n");
    }

}

///////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void traduction_c_fr(void)
{

char* trad[21][2] = {
{"if" , "Si "},
{"else", "Sinon "},
{"{", "Debut\n"},
{"}", "Fin\n"},
{"{\n", "Debut\n"},
{"}\n", "Fin\n"},
{"while", "Tant Que "},
{"do", "Faire\n"},
{"for", "Pour "},
{"=", "Recoit "},
{"==", "Egale "},
{"!=", "Different "},
{">", "Superieure "},
{"<", "Inferieure "},
{"=<", "Inferieure ou egale "},
{"=>", "Superieure ou egale "},
{"&&", "ET "},
{"||", "OU "},
{"!" , "NON "},
{"EOF","Fin De Fichier "},
{"\n","\n"}};

    char chemin[50];
    color(11, 16);
    printf("\n\n                        - traduction des fichiers C en francais - \n\n");
    color(14,16);
    printf("\n             - Le fichier que vous voulez traduise doit etre formatee.\n             - c'est a dire il doit avoir des escpaces entre le mot reserves dans le langage C.\n\n");
    printf("             - il'est aussi que la derniere ligne se soit pas vide.\n\n");
    color(15,16);
    system("pause");
    system("cls");

    color(11, 16);
    printf("\n\n                        - traduction des fichiers C en francais - \n\n");
    color(14, 16);
    printf("\n\n\n             - Inserer le chemin du fichier : ");

    color(15, 16);
    scanf("%s", &chemin);
    system("cls");
    char fich[50] = "traduction.txt";
    FILE *fic  = fopen(chemin, "r+");

    FILE *fic2 = fopen("traduction.txt", "w");
    fic2 = fopen("traduction.txt", "a+");


char ligne[256];
char* mot ;
int verif;

    while (!feof(fic)){

    fgets(ligne,255,fic);
    mot = strtok(ligne," ");

    while (mot != NULL){
       verif = 0;

       for (int i=0 ; i<21 ; i++)
       {
        if (strcmp(mot,trad[i][0]) == 0)
        {
            verif =1;
            mot = trad[i][1];
            fputs(mot,fic2);
        }

       }
       if (verif != 1)
       {
       fputs(mot,fic2);
       fputc(32,fic2);
       }
       mot = strtok(NULL," ");
    }
    }
    color(15, 16);
    printf("\n\n                    traduction est finnie avec succes ( un fichier traduction.txt est cree dans le repertoire actuel.\n");

  


}

///////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void traduction_fr_c(void)
{
char* trad[21][2] = {
{"if " , "Si"},
{"else ", "Sinon"},
{"{", "Debut"},
{"}", "Fin"},
{"{\n", "Debut\n"},
{"}\n", "Fin\n"},
{"while ", "Tant Que"},
{"do", "Faire"},
{"for ", "Pour"},
{"= ", "Recoit"},
{"== ", "Egale"},
{"!= ", "Different"},
{"> ", "Superieure"},
{"< ", "Inferieure"},
{"=< ", "Inferieure ou egale"},
{"=> ", "Superieure ou egale"},
{"&& ", "ET"},
{"|| ", "OU"},
{"! " , "NON"},
{"EOF ","Fin De Fichier"},
{"\n","\n"}};

    char chemin[50];

   	color(11, 16);
    printf("\n\n                        - traduction des fichiers C en francais - \n\n");

    color(14, 16);
    printf("\n\n\n             - Inserer le chemin du fichier : ");

    color(15, 16);
    scanf("%s", &chemin);

    char fich[50] = "traduction2.txt";
    FILE *fic  = fopen(chemin, "r+");

    FILE *fic2 = fopen("traduction2.txt", "w");
    fic2 = fopen("traduction2.txt", "a+");


char ligne[256];
char* mot ;
int verif;

    while (!feof(fic)){

    fgets(ligne,255,fic);
    mot = strtok(ligne," ");

    while (mot != NULL){
       verif = 0;

       for (int i = 0 ; i < 21 ; i++)
       {
        if (strcmp(mot,trad[i][1])== 0)
        {
            verif =1;
            fputs(trad[i][0],fic2);
        }

       }
       if (verif != 1)
       {
       fputs(mot,fic2);
       fputc(32,fic2);
       }
       mot = strtok(NULL," ");
    }
    }
     color(15, 16);
    printf("\n\n                    traduction est finnie avec succes ( un fichier traduction2.txt est cree dans le repertoire actuel.\n");

   }

///////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void stat(void)
{

char* trad[7] = {"if","else","while","for","="};


    char chemin[50];
    color(11, 16);
    printf("\n\n                        - Statistiques sur les fichiers - \n\n");

    color(14, 16);
    printf("\n\n\n             - Inserer le chemin du fichier : ");

    color(15, 16);
    scanf("%s", &chemin);

    FILE *fic  = fopen(chemin, "r+");
    system("cls");


char c ;
char ligne[256];
char* mot ;
int nbr_if = 0, nbr_else = 0, nbr_rec = 0, nbr_for = 0, nbr_while = 0, nbr_lignes = 0;

     for (c = getc(fic); c != EOF; c = getc(fic)) {
        if (c == '\n')
            nbr_lignes = nbr_lignes + 1;
     }
     if (nbr_lignes > 0)
     {
       nbr_lignes = nbr_lignes +1;
     }

     fic = fopen(chemin,"r+");

    while (!feof(fic)){

    fgets(ligne,255,fic);
    mot = strtok(ligne," ");

    while (mot != NULL)
    {

       for (int i=0 ; i<5 ; i++)
       {
        if (strcmp(mot,trad[i])== 0)
        {

           switch(i)
           {
               case 0 : nbr_if +=1;
               break;

                case 1 : nbr_else  +=1;
               break;

                case 2 : nbr_while +=1;
               break;

                case 3 : nbr_for +=1;
               break;

                 case 4 : nbr_rec +=1;
               break;


           }
        }

       }

        mot = strtok(NULL," ");
    }

    }
    color(15,16);
    printf("\n\n\n   le nombre de if dans le fichier est : %d\n",nbr_if);
    printf("   le nombre de else dans le fichier est : %d\n",nbr_else);
    printf("   le nombre de while dans le fichier est : %d\n",nbr_while);
    printf("   le nombre de for dans le fichier est : %d\n",nbr_for);
    printf("   le nombre de affectations dans le fichier est : %d\n",nbr_rec);
    printf("   le nombre de lignes dans le fichier est : %d\n",nbr_lignes);
}


///////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void encrypt(void) {
	FILE* fichier = NULL;
	FILE* fichier2 = NULL;
	FILE* fichier3 = NULL;

	fichier = fopen("main.c","r+");

	char* name2 = "encrypt.txt";

    color(11,16);
    printf("\n\n          - Cryptage de fichier C. ");


	char code[]="";
	int crypto;
 	if(fichier!= NULL) {
		fichier2 = fopen(name2,"w");
		if(fichier2 != NULL) {

		while(strlen(code)<4){
      color(14,16);
			printf("\n\n          - Veuillez saisir un cle >3 caracteres : ");
      color(15,16);
			scanf("%s",&code);
     		}

			crypto = gen(code);

			encrypt0(fichier,fichier2,crypto);
		}
		else {
			printf("\nimpossible  d'ouvrir le fichier");
		}
	}
		else {
			printf("\nfichier inaccessible");
		}

  }

 ///////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void decrypt(void) {
	FILE* fichier = NULL;
	FILE* fichier2 = NULL;
	FILE* fichier3 = NULL;
	char* name;

	name="encrypt.txt";
    fichier2 = fopen(name,"r+");
		int crypto;
		char code[]="";
		color(11,16);
    printf("\n\n          - Decryptage de fichier C. ");
		if(fichier2!= NULL) {
			fichier3=fopen("decrypt.txt","w+") ;
				if(fichier3 != NULL) {
          color(14,16);
					printf("\n\n          - Veuillez saisir un cle >3 caracteres : ");
          color(15,16);
          scanf("%s",&code);
					crypto = gen(code);
					decrypt0(fichier2,fichier3,crypto);
				}
				else {
					printf("couldnt open file");
				}
			}
			else {
				printf("fichier vide");
			}
  }

///////////////////////////////////////////////////////////////
////                         DESIGN                        ////
///////////////////////////////////////////////////////////////

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void color(int couleurDuTexte, int couleurDeFond) // fonction d'affichage de couleurs
{
  HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(H, couleurDeFond * 16 + couleurDuTexte);
}

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void intro(void)
{

  printf("\n \n \n");
  color(11, 16);
  printf("               ||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~||\n");
  printf("               ||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~||\n");
  printf("               ||");
  printf("                                                                                         || \n");
  printf("               ||");

  color(15, 16);
  printf("                           ECOLE NATIONALE SUPERIEUR D'INFORMATIQUE");

  color(11, 16);
  printf("                      || \n");
  printf("               ||");

  color(15, 16);
  printf("                                CYCLE PREPARATOIRE INTEGRE (CPI)");

  color(11, 16);
  printf("                         ||\n");
  printf("               ||                                                                                         ||\n");
  printf("               ||                   ~~~~~~~~~~~~~~ ~~ ~~~~~~~~~ ~~~ ~~~~~~ ~~~~~~~~~~~                    ||\n");
  printf("               ||");

  color(15, 16);
  printf("                       STRUCTURE FICHIERS ET STRUCTURES DE DONNEES                 ");

  color(11, 16);
  printf("      ||\n");

  color(11, 16);
  printf("               ||                   ~~~~~~~~~~~~~~ ~~ ~~~~~~~~~ ~~~ ~~~~~~ ~~~~~~~~~~~                    ||\n");

  color(11, 16);
  printf("               || ");

  color(11, 16);
  printf("                 ____________________________________________________ ");

  color(11, 16);
  printf("                  ||\n");
  printf("               ||");

  color(11, 16);
  printf("                 |                                                    |");

  color(11, 16);
  printf("                  ||\n");
  printf("               ||");

  color(11, 16);
  printf("                 |");
  printf("                          TP 1 ");
  printf("                     |");

  color(11, 16);
  printf("                  ||\n");
  printf("               ||");

  color(11, 16);
  printf("                 |");

  color(13, 16);

  printf("         Codage et Decodage d'un fichier texte");

  color(11, 16);
  printf("      |");

  color(11, 16);
  printf("                  ||\n");

  color(11, 16);
  printf("               ||");

  color(11, 16);
  printf("                 |              ");
  color(13, 16);
  printf("a partir d'une cle donnee");

   color(11, 16);
  printf("             |");

  color(11, 16);
  printf("                  ||\n");

  color(11, 16);
  printf("               ||");

  color(11, 16);
  printf("                 |____________________________________________________|");

  color(11, 16);
  printf("                  ||\n");
  printf("               ||                                                                                         ||\n");
  printf("               ||                                                                                         ||\n");
  printf("               ||");

  color(15, 16);
  printf("     REALISE PAR : HAFRI SEIF ALI  ET  GHOUALI ABDEL MOUNAIM             ");

  color(11, 16);
  printf("                ||\n");

  color(11, 16);

  printf("               ||                                                                                         ||\n");
  printf("               ||");

  color(15, 16);
  printf("     ENCADRE PAR : DR. Boulkradeche   ");

  color(11, 16);
  printf("                                                   ||\n");
  printf("               ||                                                                                         ||\n");
  printf("               ||");

  color(14, 16);
  printf("                                     2019/2020");

  color(11, 16);
  printf("                                           ||\n");
  printf("               ||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~||\n");
  printf("               ||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~||\n");
}

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void menu(void)
{
  color(11, 16);

  printf("\n\n             				    ____________________________________________\n");
  printf("                		           |                                            |\n");
  printf("                                           |");

  color(15, 16);
  printf("               MENU PRINCIPALE              ");

  color(11, 16);
  printf("|\n");
  printf("               				   |____________________________________________|\n\n\n");


  color(15, 16);
  printf(" 			    - Ce prrogramme contient quelque fonctionalites utiles pour le traitement des fichiers.\n\n");
  printf(" 			    - veilleuez choisir l'une des options suivantes : \n\n\n");


  color(11, 16);
  printf("   			 1) - ");

  color(15, 16);
  printf("  afficher un fichier a l'ecran.\n");

  color(11, 16);
  printf("   			 2) - ");

  color(15, 16);
  printf("  Creer un fichier texte. \n");

  color(11, 16);
  printf("   			 3) - ");

  color(15, 16);
  printf("  Concatener deux fichiers. \n");

  color(11, 16);
  printf("   			 4) - ");

  color(15, 16);
  printf("  Traduire un fichier C en francais. \n");

  color(11, 16);
  printf("   			 5) - ");

  color(15, 16);
  printf("  Faire l'operation inverse de 4. \n");

  color(11, 16);
  printf("   			 6) - ");

  color(15, 16);
  printf("  Faire des statistiques sur un fichier C. \n");

  color(11, 16);
  printf("   			 7) - ");

  color(15, 16);
  printf("  Crypter un fichier C. \n");


  color(11, 16);
  printf("   			 8) - ");

  color(15, 16);
  printf("  Decrypter un fichier C. \n");

  color(11, 16);
  printf("   			 9) - ");

  color(15, 16);
  printf("  Exit. \n");




}

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int choix1(void)
{
  int i = 0, temp;

  do
  {
    color(14, 16);
    if (i == 0)
      printf("\n\n        - Inserer le numero de votre choix : ");

    else
      printf("\n        - Veilleuez reinserer le numero de votre choix s.v.p : ");

    color(11, 16);
    scanf("%d", &temp);
    i++;
  } while ((temp <1) || (temp>9));

  return temp;
}

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////*/


#endif
