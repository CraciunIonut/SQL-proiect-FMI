// SQL.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

#include <iostream>
//#include "SQL-PARSE.h"
#include <fstream>
#include <string>
#include <string.h>
//#include <direct.h>
#include "SQL.h"
#include "Database.h"
#include <unistd.h>
#include <sys/stat.h>

//ifstream f ("Tabel.txt");
//ofstream g ("Tabel.txt");

using namespace std;


/*             1.switch care sa ia toata propozitia si sa isi dea seama singur de comanda introdusa si de datele din ea.
2. in switch-ul ala/switch-urile alea trebuie sa aiba un tip de formatare dupa cum urmeaza:
a) Comanda ceruta
b) Unde sa se creeze (tabela);
c) Numele tabelei
d) Datele necesare
3. Trebuie sa creem prioritati la comenzi (delete sa stearga ori doar un anumit tip de date or toata linia)
4. Formatare tipuri de date ( sa ii facem diferentiere intre numere, nume , date anuale,etc);
EXTRA:
Numele o sa inceapa cu ' si se termina cu ' exemplu : 'CUCU-CIUHAN Cipran' (o sa ne ajute pentru ca o sa cautam in string-ul dat ' pana la cealalta '
Trebuie sa facem si cazul in care lipseste un tip de date, ex: lipseste anul nasterii , programul nostru sare peste coloana aceea
*/


int main()
{

	string line;
	string tabel[100][100];
	string nume_fisier;
	char gol[50];
	string database_table;// este folosit pentru a ne da seama daca creem baza de date sau tabel 
	string database_name;//in database_name a intrat numele directorului in care lucram.
	//mkdir ("test", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	while (1)

	{

		cout << "Meniu principal" << "\n";

		char commands;

		cin >> commands;

		switch (commands)
		{
		case 'C':
		{
			//functia create va creea un tabel si il va salva sub forma de fisier text
			cin >> gol;
			cin.get();
			cin >> database_table;
			cin.get();
			if (database_table.at(0) == 'd' || database_table.at(0) == 'D')
			{
				_create_database();
			}
			else {
				cin >> nume_fisier;
				cin.get(gol, 50);
				_CREATE(nume_fisier, line, tabel,database_name);
			}
			break;
		}

		case 'I':
		{
			//functia insert insereaza in tabel date
			cin >> gol;
			cin.get();
			cin >> gol;
			cin.get();
			cin >> nume_fisier;
			cout << "Inserati in tabelul " << nume_fisier << "\n";
			_INSERT(nume_fisier, tabel,database_name);
			break;
		}

		case 'D':
		{
			//functia delete va avea doua proprietati, ori va sterge toate datele din
			//tabel, lasandu-l gol, ori va sterge un rand care indeplineste o conditie

			cin >> gol;
			cin.get();
			cin >> gol;
			cin.get();
			cin >> nume_fisier;
			_DELETE(nume_fisier, tabel,database_name);
			break;
		}

		case 'S':
		{

			// functia select va selecta in care baza de date vom lucra;
			cin >> gol;
			cin.get();
			cin >> database_table;
			cin.get();
			database_name = _select_database();
			cout << "Momentan lucrati in baza de date " << database_name << "\n";

		}

		case 'U':
		{
			//functia update va pune informatiile pasate de la tastatura
			//in locul informatiilor deja prezente in tabel

			cin >> gol;
			cin.get();
			cin >> nume_fisier;
			_UPDATE (nume_fisier, tabel, database_name);
		}


		}

		if (commands == 'E')
			return 0;

	}

	return 0;
}

