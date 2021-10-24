/*MonFichier2.cpp : Ex2 Devoir2 CSI2772A*/

#include "MonFichier2.h"

int main() {
	int monTab[size_tab] = { 2,4,8,20,3,55,87,13,2,5 };

	cout << "Affichage du tableau non trie :" << endl;
	for (int i = 0;i < size_tab;i++) {
		cout << monTab[i] << endl;
	}
	trier(monTab, size_tab);
	cout << "\nAffichage du tableau trie :" << endl;
	for (int i = 0;i < size_tab;i++) {
		cout << monTab[i] << endl;
	}
}

void trier(int tab[], int size)
{
	int i, j, pivot; //initializer trois variables qu'on va manipuler
	for (int i = 0; i < size; i++) {
		//choisir l'element qu'on va comparer
		pivot = tab[i]; 
		for (j = i-1; j >=0 && tab[j] > pivot; j--) {
			tab[j+1] = tab[j];
		}
		tab[j+1] = pivot;
	}

}
