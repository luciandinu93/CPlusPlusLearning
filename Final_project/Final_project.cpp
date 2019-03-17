/* Proiect final: BitAcad Modulul 1 C++
 * Student: Dinu Dumitru-Lucian 
 */

#include "Persoana.h"
#include "MeniuPrincipal.h"
#include "MeniuIntroducere.h"
#include "MeniuCautare.h"
#include "Listare.h"

int main()
{
	int comanda;
	Student* studenti;
	Profesor* profesori;

	do
	{
		displayMP();
		std::cout << "Alegeti o optiune: ";
		std::cin >> comanda;

		switch(comanda)
		{
		case 1:
			processInputComand(studenti, profesori);
			break;
		case 2:
			processFindComand(studenti, profesori);
			break;
		case 3:
			displayAll(studenti, profesori);
		case 0:
			break;
		default:
			std::cout << "Optiune incorecta! Va rog alegeti comanda 1, 2, 3 sau 0 pentru iesire." << std::endl;
			break;
		}
	} while (comanda != 0);

	Persoana* pers = new Persoana("Ion", "Mihai");
	Student* stud = new Student("Ion", "Mihai", 1, 7);
	Profesor* prof = new Profesor("Ion", "Mihai", "matematica");

    std::cout << "Persoana " << pers->ToString() << std::endl;
	std::cout << "Student " << stud->ToString() << std::endl;
	std::cout << "Profesor " << prof->ToString() << std::endl;

	return 0;
}
