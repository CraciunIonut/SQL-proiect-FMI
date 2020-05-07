<<<<<<< HEAD
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <vector>

using namespace std;

void citire(string intrare, string tabel[100][100]) {

    string Filepath = "test/" + intrare + ".txt";
    ifstream input(Filepath.c_str());

    input >> tabel[0][0];
    cout << tabel[0][0];
    /*
        int i_sec = 0, j_sec = 0, coloane = 0;

        while (input>>tabel[i_sec][j_sec]){
            j_sec += 1;

            if (tabel[i_sec][j_sec] == "\n"){
                coloane = j_sec;
                break;
            }
        }
    */
}



// _CREATE creeaza un tabel cu un nume care il dam noi in directorul test
//  Pune coloanele care trebuiesc si le tine minte intr-o matrice.
void _CREATE(string intrare, string line, string tabel[100][100])
{
    string Filepath = "test/" + intrare + ".txt";
    ofstream g(Filepath.c_str());
    int i = 0, j = 0;
    while (cin >> line && line.back() != ';')
    {
        tabel[i][j] = line;
        cin >> line;
        j++;
    }
    for (i = 0; i < j; i++)
    {
        g << tabel[0][i] << ((i == j-1) ? "" : " "); // conditie ? true : false 
    }

    g << "\n";
    g.close();
}
/*
citim COMANDA DE LA TASTATURA INSERT apoi stie ca urmeaza into.
citim numele tabelelui si il deschidem
printr-un algoritm citim coloanele in care trebuie sa inseram si scoatem virgulele de la ele si dupa aceea printr-un vector ne punem poziitile necesare pentru fiecare coloana.
*/
void _INSERT(string intrare, string tabel[100][100])
{
    string Filepath = "test/" + intrare + ".txt";
    //ofstream g(Filepath.c_str());
    //INSERT INTO TABEL2 (col1, col2, col3)  for tabel[0][j]==string vector k[i]=j; tabel[1][k[i]];
    // VALUES
    //(bla,bla,bla ),
    //(

    int vec[100];
    string vector_aparitii[100];

    string tabel_secundar[100][100];

    ifstream f(Filepath.c_str());

    int i_sec = 0, j_sec = 0, coloane = 0;

    while (f >> tabel_secundar[i_sec][j_sec]) {
        j_sec += 1;

        if (tabel_secundar[i_sec][j_sec] == "\n") {
            coloane = j_sec;
            break;
        }
    }

    i_sec += 1;
    j_sec = 0;

    while (f >> tabel_secundar[i_sec][j_sec]) {
        j_sec += 1;
        if (tabel_secundar[i_sec][j_sec] == "\n") {
            i_sec += 1;
            j_sec = 0;
        }
    }

    cout << "OK" << endl;


    for (int i = 0; i < i_sec; i++) {
        for (int j = 0; j < coloane; j++) {
            cout << tabel_secundar[i][j] << " ";
        }
        cout << endl;
    }



    /*

    string comanda;//aici ne luam numele coloanelor si variabilele

    cin>>comanda;

    if (comanda.length() == 1){
        cin>>comanda;
    }

    int index = 0;

    for (int i = 0; i <= j_sec; i++){
        vector_aparitii[index] = tabel_secundar[0][index];
        index++;
    }

    for (int i = 0; i <= i_sec; i++){
        for (int j = 0; j <= j_sec; j++){
            tabel[i][j] = tabel_secundar[i][j];
        }
    }

    index -= 1;

    while (cin>>comanda && comanda.back()!=')'){

        int i = 0;

        comanda.erase(comanda.end()-1, comanda.end());

        int j = 0;

        for (i = 0; i < index; i++){
            if (vector_aparitii[i] == comanda){
                vec[j] = i;
                j += 1;
            }
        }
    }

    cin>>comanda;

    int contor = i_sec+1;
    int index_vec = 0;

    while (cin>>comanda && comanda.back()!=';'){

        int pozitie = -1;

        pozitie = comanda.find("(");

        if (pozitie == 0){
            comanda.erase(0,1);
        }

        pozitie = comanda.find("'");

        if (pozitie == 0){
            comanda.erase(0,1);
        }

        pozitie = comanda.find("'");

        if (pozitie > 0){
            comanda.erase(pozitie,pozitie+1);
        }

        pozitie = comanda.find("',");

        if (pozitie > 0){
            comanda.erase(pozitie, pozitie+2);
        }

        pozitie = comanda.find(",");

        if (pozitie > 0){
            comanda.erase(pozitie, pozitie+1);
        }

        pozitie = comanda.find("),");

        if (pozitie > 0){
            comanda.erase(pozitie, pozitie+2);
            contor++;
        }

        if (index_vec < index){
            tabel[contor][vec[index_vec]] = comanda;
            index_vec += 1;
        }

        if (index_vec == index){
            tabel[contor][vec[index_vec]] = comanda;
            index_vec = 0;
        }
    }

    for (int i = 0; i <= contor; i++){
        for (int j = 0; j <= index; j++){
            g<<tabel[i][j]<<" ";
        }
        g<<"\n";
    }

    */

    //g.close();
    f.close();

}
=======
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <vector>

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

    int vec[100];
    string vector_aparitii[100];

    string tabel_secundar[100][100];

    ifstream f(Filepath.c_str());

    int i_sec = 0, j_sec = 0;

    while (f>>tabel_secundar[i_sec][j_sec]){
        j_sec += 1;

        if (tabel_secundar[i_sec][j_sec] == "\n"){
            i_sec += 1;
        }
    }

    string comanda;//aici ne luam numele coloanelor si variabilele

    cin>>comanda;

    if (comanda.length() == 1){
        cin>>comanda;
    }

    int index = 0;

    for (int i = 0; i <= j_sec; i++){
        vector_aparitii[index] = tabel_secundar[0][index];
        index++;
    }

    for (int i = 0; i <= i_sec; i++){
        for (int j = 0; j <= j_sec; j++){
            tabel[i][j] = tabel_secundar[i][j];
        }
    }
    
    index -= 1;

    while (cin>>comanda && comanda.back()!=')'){

        int i = 0;

        comanda.erase(comanda.end()-1, comanda.end());

        int j = 0;
        
        for (i = 0; i < index; i++){
            if (vector_aparitii[i] == comanda){
                vec[j] = i;
                j += 1;
            }
        }
    }

    cin>>comanda;

    int contor = i_sec+1;
    int index_vec = 0;

    while (cin>>comanda && comanda.back()!=';'){

        int pozitie = -1;

        pozitie = comanda.find("(");

        if (pozitie == 0){
            comanda.erase(0,1);
        }

        pozitie = comanda.find("'");

        if (pozitie == 0){
            comanda.erase(0,1);
        }

        pozitie = comanda.find("'");

        if (pozitie > 0){
            comanda.erase(pozitie,pozitie+1);
        }

        pozitie = comanda.find("',");

        if (pozitie > 0){
            comanda.erase(pozitie, pozitie+2);
        }

        pozitie = comanda.find(",");

        if (pozitie > 0){
            comanda.erase(pozitie, pozitie+1);
        }

        pozitie = comanda.find("),");

        if (pozitie > 0){
            comanda.erase(pozitie, pozitie+2);
            contor++;
        }

        if (index_vec < index){
            tabel[contor][vec[index_vec]] = comanda;
            index_vec += 1;
        }

        if (index_vec == index){
            tabel[contor][vec[index_vec]] = comanda;
            index_vec = 0;
        }
    }

    for (int i = 0; i <= contor; i++){
        for (int j = 0; j <= index; j++){
            g<<tabel[i][j]<<" ";
        }
        g<<"\n";
    }

    g.close();
    f.close();







}
>>>>>>> badcdb3fca41d975aaa6563cea44b4ffd0bdf322
