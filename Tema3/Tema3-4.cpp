/* Realizati un program care prelucreaza un array cu doua dimensiuni numere reale
 * 1. Se apeleaza o functie pentru a introduce numarul de linii si coloane si o
 * functie pentru a introduce numarul de linii si coloane
 * 2. O functie afiseaa elementele array-ului
 * 3. O functie primeste ca parametru un numar cuprins intre 1 si l (nr de linii)
 * si returneaza elementele de pe linia selectata
 * 4. O functie primeste ca parametrii doua nr intregi si daca acestea sunt mai mici
 * decat numarul de linii respectiv coloane afiseaza matricea trunchiata 
 * flosind noul nr de linii si coloane
 * 5. Apelati corespunzator functiile create din functia main
 */

#include <iostream>

using namespace std;

const int b = 3;

void alegeDimensiuneArray(unsigned short int &n, unsigned short int &m)
{
    cout << "Introduceti numarul de linii:";
    cin >> n;
    cout << "Introduceti numarul de coloane:";
    cin >> m;

    cout << "Ati ales o matrice de " << n << " linii si " << m << " coloane." << endl;
}

void introduElemente( float array[][c], unsigned short int l, unsigned short int c)
{
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> array[i][j];
        }
    }
}

void afiseazaElementeArray( float **array, unsigned short int l, unsigned short int c)
{
    cout << "Afiseaza elementele ... " << endl;
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cout << "a[" << i << "][" << j << "] = " << array[i][j] << endl;
        }
    }
}
int main(void)
{
    unsigned short int l, c; // linii si coloane

    alegeDimensiuneArray(l, c);

    float array[l][c];
    
    introduElemente(array, l, c);

    afiseazaElementeArray(array, l, c);

    return 0;
}
