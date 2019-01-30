/* Se da un sir de n numere naturale citite de la tastatura.
 * Sa se salveze numerele intr-un vector de numere intregi si apoi afisati:
 *
 * 1. Elementele vectorului
 * 2. Elementele vectorului aflate pe pozitii pare
 * 3. Elementele impare ale vectorului
 * 4. Suma elementelor pozitive
 * 5. Produsul elementelor negative aflate pe pozitii impare;
 * 6. Numarul elementelor divizibile cu 5
 * 7. Daca elem de pe pozitia p (p citit de la tastatura) este par
 */

#include <iostream>

using namespace std;

void citesteVector (int v[], int &n)
{
    int i = 0, value = 0;
    cout << "Introduceti elementele, \'-1\' pentru a termina operatiunea:" << endl;
    while ( value != -1)
    {
        cout << "Enter v[" << i << "]= ";
        cin >> value;
        v[i] = value;
        i++;
    }
}

void afiseazaVector (int *p, int n)
{
    cout << "Afisare vector: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << *(p+i) << " ";
    }
    cout << endl;
}

int main(void)
{
    int v[] = {0}, n;

    int p* = v;

    citesteVector(p, n);
    afiseazaVector(p, n);
    
    return 0;
}
