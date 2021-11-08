/*MonFichier3.cpp : Ex3 Devoir2 CSI2772A*/

#include <iostream>
using namespace std;

int **triangleInf(int n) {
  int **tab = new int *[n]; // Créer un tableau avec n lignes
  // Initialiser le tableau
  for (int i = 0; i < n; i++) {
    *(tab + i) = new int[n]; // Chaque ligne a n éléments
    **(tab + i) = 1;         // Le premier élément de chaque ligne est 1
    // Calculer la valeur des éléments suivants selon les règles données
    for (int p = 1; p <= i; p++)
      *(*(tab + i) + p) = *(*(tab + i - 1) + p - 1) + *(*(tab + i - 1) + p);
  }

  return tab;
}

int** triangleInf2(int n)
{
	int** ret = new int *[n]; //creer un tableau avec n ligne
	// Initialiser le tableau
	for (int i = 0; i < n; i++) {
		*(ret + i) = new int[n]; // Chaque ligne a n éléments
		ret[i][0] = 1; // Le premier élément de chaque ligne est 1
		// Calculer la valeur des éléments suivants selon les règles données
		for (int j = 1; j <= i; j++) {
			ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
		}
	}
	return ret;
}


int main() {
	int** tab;
	const int size = 10;
	tab = triangleInf(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <= i; j++)
			cout << tab[i][j] << " ";
		cout << endl;
	}

	cout << endl;

	int** tab2;
	tab2 = triangleInf(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <= i; j++)
			cout << tab2[i][j] << " ";
		cout << endl;
	}
}