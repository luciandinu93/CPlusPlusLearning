/* Creati:
 * 1. O functie denumita minim care returneaza minimul dintre doua numere intregi
 * 2. O functie denumita minim care returneaza minimul dintre trei numere intregi
 * 3. O functie denumita minim care returneaza minimul dintre elementele unui vector
 */

#include <iostream>

using namespace std;

// Cerinta 1
inline int min(int a, int b)
{	
    return a < b ? a : b;
}

// Cerinta 2
int min(int a, int b, int c)
{
    int min = c;
    if(a < b && a < c)
        return a;
    else if(b < a && b < c)
        return b;
    else
        return c;
}

// Cerinta 3
int min(int vec[], int *finalPos)
{
    int n, min;
    n = finalPos - vec; // difference of last address and first addres of array returning the number of elements in array
    min = vec[0];
    for(int i = 0; i < n; i++)
    {
        if(min > vec[i])
            min = vec[i];
    }
    return min;
}

int main(void)
{
    unsigned short int i = 0, optiune;
    int *vector, number, *finalPos, min_num, x, y, z;
    vector = new int[100]; 
	
	while(1)
	{
		cout << "Menu:" << endl;
		cout << "Introduceti 1 pentru a gasi minimul a doua numere." << endl;
		cout << "Introduceti 2 pentru a gasii minimul a trei numere." << endl;
		cout << "Introduceti 3 pentru a gasi minimul elementelor unui vector." << endl;
		cout << "Introduceti altceva (ex:0) pentru a iesi." << endl;
		cout << "Optiune: ";
		cin >> optiune;
		
		if(optiune != 1 && optiune != 2 && optiune !=3)
		{
			cout << "Bye for now!" << endl;
			break;
		}
		
		switch(optiune)
		{
			case 1:
				cout << "Introduceti doua numere. " << endl;
				cout << "x = ";
				cin >> x;
				cout << "y = ";
				cin >> y;
				min_num = min(x, y);
				cout << "The min(" << x << "," << y << ") is = " << min_num << endl;
				break;
			case 2:
				cout << "Introduceti trei numere. " << endl;
				cout << "x = ";
				cin >> x;
				cout << "y = ";
				cin >> y;
				cout << "z = ";
				cin >> z;
				min_num = min(x, y, z);
				cout << "The min(" << x << "," << y << "," << z << ") is = " << min_num << endl;
				break;
			case 3:
				while(1)
				{
				cout << "Enter number " << i << " from array and \'-1\' to stop: ";
				cin >> number;
				if(number == -1)
					break;
				else
				{
					vector[i] = number;
					i++;
				}
				
				finalPos = &vector[i]; // get the address of the last element from array
				}
				
				min_num = min(vector, finalPos);
				cout << "min = " << min_num << endl;
				break;
			default:
				break;
		}

    }
    return 0;
}
