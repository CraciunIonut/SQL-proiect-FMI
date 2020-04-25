#include <iostream>
#include "SQL-PARSE.h"
#include <fstream>
#include <string>
#include <string.h>


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



  while (1)

   {


       string commands; //aici bagi create

       cin>>commands;

       int ok=1;//


       switch (ok)
        {
         case "create":
          //TODO: CREATE va crea ori un tabel ori o baza de date.(creaza un fisier). Acesta va necesita un nume
          string gol;
          cin>>gol;
          cin>>gol;
          _CREATE(gol);



        }

   }


    return 0;
}
