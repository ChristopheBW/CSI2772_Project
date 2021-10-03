/*
 * a) Dans la boucle while, la fonction menu() est appelee. 
 * Trois options sont donne par switch clause:
 * Taper 1 pour calculer la surface du disque de rayon;
 * Taper 2 pour calculer le volumne du cylindre de rayon et hauteur;
 * Taper 3 quitter le programm;
 * Taper autre letter pour ressayer
 * 
 * Avant la quite du programme, le nombre de fois qu'on a appelee 
 * trois fonctions sera donne sur l'ecran.
 */


/* Fonction qui calcule le volumn d'un cylindre */ 

#include "monfichier2.h"

double volume(double const& ray, double const& haut) {
    return surface(ray) * haut;
}

/* Fonction qui calcule la surface d'un cricle */ 
double surface(double const& ray) {
    return Pi * ray * ray;
}

/* Fonction principale main */ 
int  main(void) {
    char choix;
    int nvolume = 0;
    int nsurface = 0;
    double rayon, hauteur;
    double res;

    while (1) {
        choix = menu();
        switch (choix) {
        case '1':
                cout << endl << "Calcul de la surface :" << endl; 
                cout << "Donnez le rayon: ";
                cin >> rayon;
                res = surface(rayon);
                nsurface++; //increment counter by one
                cout << "La surface est: " << res << endl;
                break;
        case '2': 
                cout << endl << "Calcul du volume :" << endl; 
                cout << "Donnez le rayon: ";
                cin >> rayon;
                cout << "Donnez la hauteur: "; 
                cin >> hauteur;
                res = volume(rayon, hauteur); 
                nvolume++; //increment counter by one
                cout << "Le volume est: " << res << endl;
                break;

        case '3':
                cout << endl << "Sortie du programme" << endl;
                cout << "La fonction volume a ete lancee " << nvolume << " fois" << endl; 
                cout << "La fonction surface a ete lancee " << nsurface << " fois" << endl; exit(0);
        default: break;
        }
    }
}


/*Fonction menu() : Fonction qui affiche un menu d'option et retourne l'option choisie */
char menu(void){
    char choix;

    cout << endl;
    cout << "Que souhaitez-vous faire ?:"  << endl;
    cout << "\t-Calculer la surface du disque de rayon (Tapez 1)" <<  endl;
    cout << "\t-Calculer le volume du cylindre de rayon et hauteur (Tapez 2)"  << endl;
    cout << "\t-Quittez le programme (Tapez 3)" << endl ;
    cout << "Votre choix: ";
    cin >> choix;
    return(choix);

}