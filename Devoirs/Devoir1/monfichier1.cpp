#include "monfichier1.h"

int main(int argc, char const *argv[])
{
    cout << "Taille en octets d'un caractere: " << sizeof(char) << endl;
    cout << "Taille en octets d'un entier: " << sizeof(int) << endl;
    cout << "Taille en octets d'un reel: " << sizeof(float) << endl;
    cout << "Taille en octets d'un double: " << sizeof(double) << endl;
    cout << "Taille en octets d'un entier court: " << sizeof(short) << endl;
    cout << "Taille en octets d'un entier non signe: " << sizeof(unsigned int) << '\n' << endl;


    int temp; //create an integer variable
    cout << "Saisissez un entier: ";
    cin >> temp;
    cout << "nombre en decimal: " << dec << temp << endl;
    cout << "nombre en octal: " << oct << temp << endl;
    cout << "nombre en hexa: " << hex << temp << '\n' << endl;

    printf("nombre en decimal: %d\n",temp); //get decimal form
    printf("nombre en octal: %o\n",temp); //get ocatal form
    printf("nombre en hexa: %x\n\n",temp); //get hexadecimal form
    
    double temp2; //create an integer variable
    cout << "Saisissez un reel: ";
    cin >> temp2;
    cout << temp2 << endl;
    cout << scientific << setprecision(3) << temp2 << "\n" << endl; //get 3 significant digits

    char tempChar; //create an character variable
    cout << "Saisissez un caractere: ";
    cin >> tempChar;
    cout << tempChar << endl;
    cout << hex << tempChar - '\0' << endl;

    return 0;
}
