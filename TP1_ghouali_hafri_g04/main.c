#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include<windows.h>
#include <time.h>
#include "TP.h"



void main(void)
{
	// Declaration des variables.

	int choix ;


	// Debut de programme.
    intro();
    system("pause");
    system("cls");
	menu(); // affichage de menu principale

    choix = choix1();

    system("cls");
    switch (choix)
        {
        case 1 :
                affich_fich();
            break;

        case 2 :
                Creer_fich();
            break;

        case 3 :
                 concatene();
            break;

        case 4 :

                traduction_c_fr();
            break;

        case 5 :
                traduction_fr_c();
            break;

        case 6 :
                stat();
            break;

        case 7 :

                encrypt();
            break;

        case 8 :

                decrypt();
            break;

        case 9 :
                system("cls");
                exit(EXIT_FAILURE);
            break;


        }

}
