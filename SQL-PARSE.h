#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;



// _CREATE creeaza un tabel cu un nume care il dam noi in directorul test
//  Pune coloanele care trebuiesc si le tine minte intr-o matrice.
void _CREATE (string intrare,string result,string line,string tabel[100][100])
{
    string Filepath= "test/" + intrare + ".txt";
    ofstream g(Filepath.c_str());
     int i=0,j=0;
     while (cin>>line && line.back()!=';')
           {
               tabel[i][j]=line;
               cin>>line;
               j++;
           }
           for (i=0;i<=j;i++)
           g<<tabel[0][i]<<" ";
           g<<"\n";
           g.close();


}
/*
citim COMANDA DE LA TASTATURA INSERT apoi stie ca urmeaza into.
citim numele tabelelui si il deschidem
printr-un algoritm citim coloanele in care trebuie sa inseram si scoatem virgulele de la ele si dupa aceea printr-un vector ne punem poziitile necesare pentru fiecare coloana.
*/
void _INSERT (string intrare,string tabel[100][100])
{
    string Filepath= "test/" + intrare + ".txt";
    ofstream g(Filepath.c_str());
    //INSERT INTO TABEL2 (col1, col2, col3)  for tabel[0][j]==string vector k[i]=j; tabel[1][k[i]];
    // VALUES
    //(bla,bla,bla ),
    //(








}
