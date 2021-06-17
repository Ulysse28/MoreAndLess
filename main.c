#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    //Nombre mystère
    int nombreMystere;

    //mode de jeu
    int modeJoueur;

    //niveau de jeu
    int level;

    //Variables pour générer un nombre aléatoire
    int max;
    const MIN = 1;


    //Réponse du joueur initialiser à 0
    int rep = 0;

    //Compteur
    int compteur = 0;

    //Pour continuer ou pas la partie
    int running = 1;


    //Boucle principale du jeu
    while(running)
    {
        //Mode de jeeux (2 joueurs ou 1 joueur)
        printf("Voulez vous jouez à 1 ou 2 joueurs ? (1)/(2)  ");
        scanf("%d", &modeJoueur);

        //Selon la réponse
        if(modeJoueur == 1)
        {

            //L'utilisateur choisi le niveau de diificulté
            printf("choisissez le niveau de difficulte : 1/2/3 : \n");

            scanf("%d", &level);

            switch(level){

             case 1:
                max = 100;
                break;
            case 2:
                max =1000;
                break;
            case 3 :
                max = 10000;
                break;
            }


            //Générer un nombre aléatoire entre 0 et 100
            srand(time(NULL));
            nombreMystere = (rand() % (max - MIN + 1)) + MIN;

        }
        else
        {
            printf("Entrez le nombre à faire deviner : ");
            scanf("%d", &nombreMystere);

        }


        //Boucle de partie
        do
        {
            //L'utilisateur entre un nombre entre 0 et 100
            printf("Entrez un nombre entre 0 et %d  ", max);
            scanf("%d", &rep);

            //Tests sur la réponse du joueur
            if(nombreMystere > rep)
            {
                printf("C'est plus grand !");
                compteur++;

            }
            else if(nombreMystere < rep)
            {
                printf("c'est plus petit !");
                compteur++;

            }
            else
            {
                printf("Bravo, vous avez trouve le nombre mystere !!!");
                printf("Vous avez reussi en %d coups !", compteur);
            }
        }
        while (rep != nombreMystere);


        //si le il veut rejouer
        printf("Vouslez vous refaire une partie ? yes(1)/no(0) ");

        scanf("%d", &running);


    }

    //Si le joueur arrete la partie
    printf("au revoir !");

    return 0;
}
