
#include <iostream>
//#include "SQL-PARSE.h"
#include <fstream>
#include <string>
#include <string.h>
//#include <direct.h>
#include "SQL.h"



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
    //mkdir ("test");
    while (1)

    {

        char commands;

        cin >> commands;

        switch (commands)
        {
        case 'C':
        {
            //functia create va creea un tabel si il va salva sub forma de fisier text
            cin >> gol;
            cin.get();
            cin >> gol;
            cin.get();
            cin >> nume_fisier;
            cin.get(gol, 50);
            _CREATE(nume_fisier, line, tabel);
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
            _INSERT(nume_fisier, tabel);
            break;
        }

        }

        if (commands == 'E')
            return 0;

    }

    return 0;
}

