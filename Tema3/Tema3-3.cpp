/* Se da un sir de n numere naturale citite de la tastatura.
 * Sa se salveze numerele intr-un vector de numere intregi si apoi afisati:
 * 1. elementele vectorului
 * 2. elementele vectorului aflate pe pozitii pare
 * 3. elementele impare ale vectorului
 * 4. suma elementelor pozitive
 * 5. produsul elementelor negative aflate pe pozitii impare
 * 6. numarul elementelor divizibile cu 5
 * daca elementul de pe pozitia p (p citit de la tastatura) este par
 */

#include <iostream>

using namespace std;

void afiseazaElementeVector (int v[], int n)
{
    cout << "Displaying array ... " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "v[" << i << "] = " << v[i] << endl;

    }
}

void afiseazaPozitiiPare (int v[], int n)
{
    cout << "Displaying even indexes ... " << endl;
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
        {
            cout << "v[" << i << "] = " << v[i] << endl;
        }
    }
}

void afiseazaPozitiiImpare (int *ptr, int n)
{
    cout << "Displaying odd indexes ... " << endl;
    for(int i = 0; i < n; i++)
    {
        if(i % 2 != 0)
        {
            cout << "v[" << i << "] = " << *(ptr + i) << endl;
        }
    }
}

void afiseazaSumaElemPozitive (int v[], int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(v[i] > 0)
        {
            sum = sum + v[i];
        }
    }

    cout << "Sum of positive elements is = " << sum << endl;
}

void afiseazaProdusElemNeg (int v[], int n)
{
    int prod, k; // k = counter for negative elements
    prod = 1;
    k = 0;

    for(int i = 0; i < n; i++)
    {
        if(v[i] < 0)
        {
            k++;
            prod = prod * v[i];
        }
    }

    if(k == 0)
    {
        cout << "Product of negative elements is 0. " << endl;
        prod = 0;
    }
    else
    {
        cout << "Product of negative elements is " << prod << endl;
    }
}

afiseazaNrElemDiv5 (int *ptr, int n)
{
    int k = 0;

    for(int i = 0; i < n; i++)
    {
        if(*(ptr+i) % 5 == 0)
            k++;
    }

    cout << "There are " << k << " that divides with 5." << endl;
}

void afiseazaPozP (int v[], int &p)
{
    if(v[p] % 2 == 0)
        cout << "v[" << p << "] = " << v[p] << " este par." << endl;
    else
        cout << "v[" << p << "] = " << v[p] << " este impar." << endl;
}

int main(void)
{
    int n, p = -1;
    
    cout << "Cate elemente doriti in vector?" << endl;
    cout << "n = ";
    cin >> n;

    int v[n];
    int *ptrV = v;

    for (int i = 0; i < n; i++)
    {
        cout << "v[" << i << "] = ";
        cin >> v[i];
    }

    while (p < 0 || p >= n)
    {
        cout << "Alegeti un index intre 0 si " << n -1 << "." << endl;
        cout << "Index = ";
        cin >> p;
    }

    afiseazaElementeVector(v, n);
    afiseazaPozitiiPare(v, n);
    afiseazaPozitiiImpare(ptrV ,n);
    afiseazaSumaElemPozitive(v, n);
    afiseazaProdusElemNeg(v, n);
    afiseazaNrElemDiv5(ptrV, n);
    afiseazaPozP(v, p);

    return 0;
}
