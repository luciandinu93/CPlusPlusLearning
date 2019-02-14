/* Dynamic data */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Collection 
{
    int elno;
    int *elements;
};

void AddToCollection(Collection &col, int element)
{
    if(col.elements == NULL)
    {
        col.elements = new int[1];
        col.elements[0] = element;
        col.elno = 1;
    }
    else
    {
        int *newArr = new int[col.elno+1];
        for(int i = 0; i < col.elno; i++)
        {
            newArr[i] = col.elements[i];
        }
        newArr[col.elno] = element;
           
        delete[] col.elements;
        col.elements = new int[col.elno+1];
        for(int i = 0; i < col.elno+1; i++)
        {
            col.elements[i] = newArr[i];
        }

        delete[] newArr;
        newArr = NULL;
        col.elno++;
    }
}

void PrintCollection(Collection col) 
{
    cout << "[";
    for(int i = 0; i < col.elno; i++)
        cout << col.elements[i] << " ";
    cout << "]" << endl;
}

int main(void)
{
    Collection collection = {0, NULL};

    int elems;
    cout << "How many elements? ";
    cin >> elems;

    srand(time(NULL));
    for(int i = 0; i < elems; i++)
        AddToCollection(collection, rand() % 100 + 1);
    PrintCollection(collection);
    delete[] collection.elements;

    return 0;
}
