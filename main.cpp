#include <iostream>
#include "SQL-PARSE.h"
#include <fstream>

ifstream f ("Tabel.txt");
ofstream g ("Tabel.txt");

using namespace std;


/*             1.switch care sa ia toata propozitia si sa isi dea seama singur de comanda introdusa si de datele din ea.
               2. in switch-ul ala/switch-urile alea trebuie sa aiba un tip de formatare dupa cum urmeaza:
               a) Comanda ceruta
               b) Unde sa se creeze (tabela);
               c) Numele tabelei
               d) Datele necesare
               3. Trebuie sa creem prioritati la comenzi (delete sa stearga ori doar un anumit tip de date or toata linia)
               4. Formatare tipuri de date ( sa ii facem diferentiere intre numere, nume , date anuale,etc);

*/


int main()
{
  while (1)

   {
       switch (commands)
        {
         case "CREATE":



        }
   }



    return 0;
}
