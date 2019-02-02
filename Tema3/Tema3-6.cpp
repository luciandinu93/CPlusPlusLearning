/* Creati:
 * 1. O structura care contine urmatoarele date: numele si nota unui student
 * 2. Un array de astfel de structuri de n elemente, n citit de la tastatura
 * 3. O functie pentru citirea datelor despre cei n studenti
 * 4. O functie pentru afisarea datelor celor n  studenti
 * 5. O functie pentru afisarea studentilor cu note peste 5
 * 6. O functie pentru calcularea mediei grupei de studenti
 */

#include <iostream>

using namespace std;

struct Student
{
    string nume;
    float nota;
};

void introducetiNotele(Student *studenti, unsigned short int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "Numele studentului " << i + 1<< " este: ";
        cin.ignore(); // empty the cin buffer before getline
        getline(cin, studenti[i].nume);
        cout << "Nota studentului este: ";
        cin >> studenti[i].nota;
    }
    cout << endl;
}

inline void afisareStudent(Student *studenti, unsigned short int index)
{
    cout << index + 1 << "." << studenti[index].nume << " nota: " << studenti[index].nota << endl;
}

void afisareDateStudenti(Student *studenti, unsigned short int n)
{
    cout << "Studentii clasei sunt: " << endl;
    for(int i = 0; i < n; i++)
    {
        afisareStudent(studenti, i);
    }
    cout << endl;
}

void afisareStudentiPeste5(Student *studenti, unsigned short int n)
{
    cout << "Afisare studenti cu note peste 5: " << endl;
    for(int i = 0; i < n; i++)
    {
        if(studenti[i].nota > 5)
            afisareStudent(studenti, i);
    }
}

void afisareMedieGrupa(Student *studenti, unsigned short int n)
{
    float sum = 0.0;
    for(int i = 0; i < n; i++)
    {
        sum += studenti[i].nota;
    }

    cout << "\n ------------------------- \n";
    cout << "Media acestei grupe este : " << sum/n << endl;
}

int main(void)
{
    unsigned short int n;
    Student *studenti;

    cout << "Cati studenti sunt in clasa dvs. : ";
    cin >> n;
    
    studenti = new Student[n];

    introducetiNotele(studenti, n);
    afisareDateStudenti(studenti, n);
    afisareStudentiPeste5(studenti, n);
    afisareMedieGrupa(studenti, n);

    delete []studenti;

    return 0;
}
