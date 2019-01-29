/* Realizati un program care sa contina:
 * 1. O functie care primeste drept parametri doua numere intregi si returneaza maximul acestora;
 * 2. O functie care primeste drept parametrii doua numere intregi si returneaza suma acestora;
 * 3. O functie care returneaza patratul unui numar primit ca parametru;
 * 4. O functie care primeste doua numere ca parametrii si realizeaza interschimbarea celor doua nr;
 * 5. Apelati functiile in main
 */

#include <iostream>

using namespace std;

// 1. Returneaza maximul a doua numere intregi
int calculeazaMax (int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

// 2. Calculeaza suma a doua numere intregi
int calculeazaSuma (int a, int b)
{
    return a + b;
}

// 3. Returneaza patratul unui numar
int calculeazaPatratul (int a)
{
    return a * a;
}

// 4. Interschimbarea a doua numere
void interschimba(int &a, int * b)
{
    int aux;
    aux = a;
    a = *b;
    *b = aux;
}

int main(void)
{
    int x, y;

    int *ptrY = &y;

    cout << "Introduceti un numar natural x: ";
    cin >> x;

    cout << "Introduceti un numar natural y: ";
    cin >> y;

    // 5. Apelarea functiilor

    cout << "Maximul dintre " << x << " si " << y << " este : " << calculeazaMax(x, y) << endl;
    cout << "Suma dintre " << x << " si " << y << " este : " << calculeazaSuma(x, y) << endl;
    cout << "Patratul numarului " << x << " este : " << calculeazaPatratul(x) << endl;
    cout << "Patratul numarului " << y << " este : " << calculeazaPatratul(y) << endl;
    cout << "x = " << x << " si y = " << y << "." << endl;
    interschimba(x, ptrY);
    cout << "Dupa interschimbare x = " << x << " si y = " << y << "." << endl;

    return 0;
}
