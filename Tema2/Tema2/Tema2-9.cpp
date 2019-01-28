/* Creati o structura denumita Angajat, care sa retina:
 * - Numele fiecarui angajat
 * - CNP-ul
 * - Numarul de ani vechime
 * - Plata pe ora
 * - Numarul de ore lucrate
 * - Remuneratia (calculata ca plata pe ora * nr-ul orelor lucrate)
 */

#include <iostream>
#include <string.h>

using namespace std;
struct Data_angajare
{
	int zi;
	int luna;
	int an;
};

struct Angajat
{
    string nume;
    char CNP[14];
    short int ani_vechime;
    float bani_pe_ora;
    short int ore_lucrate;
    float remuneratie;
	Data_angajare data_angajare;
};

int main(void)
{
    short int numar_anagajati;
	numar_anagajati = 2;
	struct Angajat angajati[numar_anagajati];
	
    // angajat 1
    angajati[0].nume = "Lucian";
    strcpy(angajati[0].CNP, "1230207551691");
    angajati[0].ani_vechime = 10;
    angajati[0].bani_pe_ora = 50.8;
    angajati[0].ore_lucrate = 100;
    angajati[0].remuneratie = angajati[0].bani_pe_ora * angajati[0].ore_lucrate;
	angajati[0].data_angajare.zi = 14;
	angajati[0].data_angajare.luna = 02;
	angajati[0].data_angajare.an = 2019 - angajati[0].ani_vechime;

    // angajat 2
    angajati[1].nume = "George";
    strcpy(angajati[1].CNP, "1232134445569");
    angajati[1].ani_vechime = 1;
    angajati[1].bani_pe_ora = 10.2;
    angajati[1].ore_lucrate = 150;
    angajati[1].remuneratie = angajati[1].bani_pe_ora * angajati[1].ore_lucrate;
	angajati[1].data_angajare.zi = 17;
	angajati[1].data_angajare.luna = 03;
	angajati[1].data_angajare.an = 2019 - angajati[1].ani_vechime;

    if (angajati[0].remuneratie > angajati[1].remuneratie)
    {
        cout << angajati[0].nume << " castiga mai mult cu " << angajati[0].remuneratie - angajati[1].remuneratie << " euro." << endl;
    }
    else
    {
        cout << angajati[1].nume << " castiga mai mult cu " << angajati[1].remuneratie - angajati[0].remuneratie << " euro." << endl;
    }
	
	cout << "Angajatii urmatori au lucrat mai mult de 40 de ore : ";
	for (short int i = 0; i < numar_anagajati; i++)
	{
		if (angajati[i].ore_lucrate > 40)
			cout << angajati[i].nume << ", ";
	}
	cout << endl;
	
	cout << "Numele angajatilor angajati dupa anul 2010 sunt : ";
	for (short int i = 0; i < numar_anagajati; i++)
	{
		if (angajati[i].data_angajare.an > 2010)
			cout << angajati[i].nume << " ";
	}
	
    return 0;
}
