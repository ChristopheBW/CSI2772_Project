/*MonFichier4.cpp : Ex4 Devoir2 CSI2772A*/

#include "MonFichier4.h"

int main() {
	char* chaine[nb_ch];		//tableau de pointeurs sur caractere(s)
	char choix;			//variable pour le choix saisi dans menu()

	cout << endl << "Saisissez les 5 chaines de caracteres en les terminant par une tabulation et un retour chariot :" << endl;

	for (int i = 0; i < nb_ch; i++) {
		chaine[i] = new char[size_ch];	//reservation de memoire pour une chaine
		cin.getline(chaine[i], size_ch, '\t');	//saisie de la chaine
		cin.ignore(INT_MAX, '\n');		//on ignore les retours chariot
	}

	display(chaine, nb_ch);

	while (1) {
		choix = menu();

		switch (choix) {
		case '1':	
			display(chaine, nb_ch);
			break;
		case '2':	
			replace(chaine, nb_ch, size_ch);
			break;
		case '3':	
			trier(chaine, nb_ch);
			break;
		case '4':	
			exit(0);
		default:	
			break;
		}
	}
}





/********************************************************************************/
/* Fonction menu Fournie */
/********************************************************************************/
char menu(void)
{
	char choix;

	cout << endl << endl << "\t\tMenu" << endl << endl;
	cout << "1) Affichage des chaines de caracteres." << endl;
	cout << "2) Remplacement d'une chaine par une autre" << endl;
	cout << "3) Tri des chaines" << endl;
	cout << "4) Sortie du programme." << endl << endl;
	cout << "Votre choix :";
	cin >> choix;

	return(choix);

}

/********************************************************************************/
/*La fonction display qui affiche les chaines de caract�res*/
/********************************************************************************/
void display(char *tab[], int const &nbre) {
  cout << endl;
  for (int i = 0; i < nbre; i++) {
    cout << "La chaine " << i << " est : " << *(tab + i) << endl;
  }
}

/*************************************************************/
/*La fonction replace qui remplace une chaine par une autre*/
void replace(char* tab[], int const& nbre, int const& size)
{
	int numero;		//la chaine a modifier

	cout << endl << "Donnez le numero de la chaine a modifier: " ;
	cin.ignore(INT_MAX, '\n');
	cin >> numero;

	//VOTRE VIENT ICI
	cout << endl << "Saisissez la nouvelle chaine: ";
	char* buffer = new char[size]; //initilize buffer
	cin.ignore(INT_MAX, '\n');
	cin.getline(buffer, size, '\t'); //enter new string
	strcpy(tab[numero], buffer); //replace old value
}

/********************************************************************************/
/*La fonction trier qui trie les chaines */
/********************************************************************************/
void trier(char* tab[], int const& nbre)
{
	int i, j; //initilize two variables
	for (int i = 0; i < nbre; i++) {
		//choisir l'element qu'on va comparer
		char* pivot = new char[size_ch]; 
		//copier la chaine dans buffer
		strcpy(pivot, tab[i]);
		//comparer l'element avec tous les element
		for (j = i-1; j >= 0 && strcmp(tab[j], pivot) > 0; j--) {
			strcpy(tab[j+1], tab[j]);
		}
		//copier l'element dans la position correcte.
		strcpy(tab[j+1], pivot); 
	}
}

