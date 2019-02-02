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

void alegeDimensiuneArray(unsigned short int &n, unsigned short int &m)
{
    cout << "Introduceti numarul de linii:";
    cin >> n;
    cout << "Introduceti numarul de coloane:";
    cin >> m;
    cout << "Ati ales o matrice de " << n << " linii si " << m << " coloane." << endl;
}

void introduElemente( float **array, unsigned short int l, unsigned short int c)
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

inline void printLine(float **array, unsigned short int &l, unsigned short int &c, unsigned short int lToPrint)
{
    lToPrint--; // array starting from 0
    cout << "Line nr. " << l << " is : ";

    for(int i = 0; i < c; i++)
    {
        cout << *(array[lToPrint] + i) << " ";           
    }
    
    cout << endl;
}

int main(void)
{
    unsigned short int l, c, lToPrint, sub_l, sub_c; // linii si coloane
 
    // Cerinta 1.a
    alegeDimensiuneArray(l, c);

    float **array;
    
    array = new float *[l];
    for(int i = 0; i < l; i++)
    {
        array[i] = new float[c];
    }
    // Cerinta 1.b
    introduElemente(array, l, c);

    // Cerinta 2
    afiseazaElementeArray(array, l, c);

    // Cerinta 3
    lToPrint = 0;
    while(lToPrint < 1 || lToPrint > l)
    {
        cout << "Ce linie doriti sa o afisati: ";
        cin >> lToPrint;
        if(lToPrint < 1)
            cout << "Prima linie este 1!" << endl;
        if(lToPrint > l)
            cout << "Ultima linie este " << l << "!" << endl;
    }
    printLine(array, l, c, lToPrint);

    // Cerinta 4
    cout << "Introduceti numarul de linii si coloane pe care vreti sa le afisati din matrice:" << endl;
    alegeDimensiuneArray(sub_l, sub_c);
    while(sub_l > l || sub_c > c)
    {
        if(sub_l > l)
            cout << "Numarul de linii trebuie sa fie mai mic sau egal cu " << l << "." << endl;
        if(sub_c > c) 
            cout << "Numarul de coloane trebuie sa fie mai mic sau egal cu " << c << "." << endl;
        alegeDimensiuneArray(sub_l, sub_c);
    }
    afiseazaElementeArray(array, sub_l, sub_c);

    // Cerinta 5
    // Done see before ...

    return 0;
}
