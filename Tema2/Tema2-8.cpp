/* Se introduc de la tastatura elementele unei matrice de n*m elemente.
 * Scrieti un program care:
 * a) afiseaza elementele matricei
 * b) afiseaza elementele de deasupra diagonalei principale ( daca matricea e patratica)
 * c) afiseaza suma elementelor de pe fiecare linie
 * d) afiseaza suma elementelor negative si impare
 * e) elementele de pe diagonala secundara
 */

#include <iostream>

using namespace std;

int main(void)
{
    short int n, m, i, j;
    int sum;

    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;
    cout << "-------------" << endl;

    int matrice[n][m];
    sum = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << "matrice[" << i + 1 << "][" << j + 1 << "]:";
            cin >> matrice[i][j];
        }
    }
    cout << "-------------" << endl;
    cout << "A. afiseaza elementele matricei:" << endl;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << matrice[i][j] << " ";
        }

        cout << endl;
    }


    cout << "-------------" << endl;
    cout << "B. afiseaza elementele deasupra diagonalei principale (daca matricea este patratica):" << endl;
    
    if (n == m)
    {
        for (i = 0; i < n - 1; i++)
        {
            for (j = 1; j < m; j++)
            {
                if (i < j)
                    cout << matrice[i][j] << " ";
            }

            cout << endl;
        }
    }
    else
    {
        cout << "Matricea nu este patratica!" << endl;
    }
    

    cout << "-------------" << endl;
    cout << "C. afiseaza suma elementelor de pe fiecare linie:" << endl;
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            sum += matrice[i][j];
        
        cout << "Suma elementelor de pe linia " << i + 1 << " este = " << sum << endl;
        sum = 0;
    }

    
    cout << "-------------" << endl;
    cout << "D. afiseaza suma elementelor negative si impare:" << endl;

    sum = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (matrice[i][j] < 0 || matrice[i][j] % 2 != 0)
                sum += matrice[i][j];
        }
    }

    cout << "Suma elemtenelor negative si impare este = " << sum << "." << endl;

    cout << "-------------" << endl;
    cout << "E. afiseaza elementele de pe diagonala secundara:" << endl;

    if (n == m)
    {
        cout << "Elementele de pe diagonala secundara sunt : ";
        for (i = 0; i < n; i++)
        {
            cout << matrice[i][n-1-i] << " ";
        }
    }
    else
    {
        cout << "Matricea nu este patratica!" << endl;
    }
    
    return 0;
}
