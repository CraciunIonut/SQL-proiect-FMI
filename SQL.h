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
    
        int i_sec = 0, j_sec = 0, coloane = 0;

        while (input>>tabel[i_sec][j_sec]){
            j_sec += 1;

            if (tabel[i_sec][j_sec] == "\n"){
                coloane = j_sec;
                break;
            }
        }
    
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

    string linie_curenta;
    string word = "";

    while (getline (f, linie_curenta)){

        for (auto x : linie_curenta)
        {
            if (x == ' ')
            {
                tabel_secundar[i_sec][j_sec] = word;
                j_sec++;
                word ="";
            }
            else
            {
                word = word + x;
            }
        }
        tabel_secundar[i_sec][j_sec] = word;
        i_sec++;
        word = "";
        coloane = j_sec;
        j_sec = 0;
    }
/*
    for (int i = 0; i <= i_sec; i++) {
        for (int j = 0; j <= coloane; j++) {
            cout << tabel_secundar[i][j] << " ";
        }
        cout << "\n";
    }
*/    

    string comanda;//aici ne luam numele coloanelor si variabilele

    int index = 0;

    for (int i = 0; i <= coloane; i++){
        vector_aparitii[index] = tabel_secundar[0][i];
        cout << vector_aparitii[index] << " ";
        index++;
    }

    cin>>comanda;

    if (comanda.length() == 1){
        cin>>comanda;
    }

    index -= 1;

    //ne folosim de asta ca sa stim in ce coloane trebuie sa inseram
    //UPDATE: Nu il mai folosim deloc momentan, dar l-am lasat aici in caz ca
    //        poate reusim sa il reparam sau poate ne trebuie in alta parte
    //        Acum e doar pe post de citire in gol pentru numele coloanelor din insert,
    //        deci tot e oarecum util.

    while (cin>>comanda && comanda.back() != ')'){

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

    int contor = i_sec;

    int index_vec = 0;
    

    //aici incercam sa eliminam orice nu este de bagat in tabel
    //ceva gen ooga booga caveman brain

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
            comanda.erase(pozitie, pozitie+1);
        }

        pozitie = comanda.find("',");

        if (pozitie > 0){
            comanda.erase(pozitie, pozitie+2);
        }

        pozitie = comanda.find(",");

        // if (pozitie > 0){
        //     comanda.erase(pozitie, pozitie+1);
        // }

        //teoretic daca s-a ajuns in aceasta situatie inseamna ca se introduc mai multe
        //date in aceeasi secventa de insert
        //momentan nu functioneaza
        //TODO: de reparat mai multe introduceri de campuri in acelasi insert
        //UPDATE: Am reparat, doar ca pentru campurile care urmeaza dupa primul
        //        pune un spatiu inainte. Din ce am vazut momentan nu afecteaza
        //        functionalitatea ulterioara a programului, probabil de undeva de la scriere

        if (pozitie > 0 && comanda.at(pozitie-1) == ')') {
            comanda.erase(pozitie-1, pozitie+1);
            contor++;
            index_vec = 0;
        } else if (pozitie > 0 && comanda.at(pozitie-1) != ')'){
            comanda.erase(pozitie, pozitie+1);
        }

        //index_vec este indexul coloanei
        //contor este indexul liniei

        cout<<"comanda: "<<comanda<<"\n";

        if (index_vec <= index){
            tabel_secundar[contor][index_vec] = comanda;
            cout<<"index: "<<index<<" tabel_secundar: "<<tabel_secundar[contor][index_vec]<<" contor: "<<contor<<" index_vec: "<<index_vec<<" vec: "<<vec[index_vec]<<"\n";
            index_vec += 1;
        }

        
    }

    ofstream g(Filepath.c_str());

    for (int i = 0; i <= contor; i++){
        for (int j = 0; j <= index; j++){
            g<<tabel_secundar[i][j]<<" ";   
        }
        g<<"\n";
    }
    //g.close();
    //f.close();

    //trebuie un if cu o verificare, care sa valideze ca tabelul in care urmeaza sa inserez
    //exista, aka capetele de tabel din comanda se potrivesc cu cele din fisier
    //ar mai trebui un if care sa verifice ca ordinea de inserare este cea buna

}

//pentru DELETE exista DELETE FROM nume WHERE conditie; unde se sterge doar randul care
//indeplineste conditia respectiva, de exemplu DELETE FROM test WHERE nume = 'Alexandru'.

//avem si DELETE FROM nume; unde se vor sterge toate informatiile din tabel, dar el in sine
//va ramane ca un fisier, impreuna cu capetele acestuia.

void _DELETE (string intrare, string tabel[100][100]){

    bool ok = false; //folosim un ok ca sa ne dam seama daca stergem tot tabelul sau doar
                     //o singura linie

    if (intrare.back() == ';'){
        intrare.erase(intrare.end()-1, intrare.end());
        ok = true;
    }

    string Filepath = "test/" + intrare + ".txt";

    ifstream f(Filepath.c_str());

    //citirea intr-o matrice secundara este copy-paste de la insert

    int i_sec = 0, j_sec = 0, coloane = 0;

    string linie_curenta;
    string word = "";
    string tabel_secundar[100][100];

    while (getline (f, linie_curenta)){

        for (auto x : linie_curenta)
        {
            if (x == ' ')
            {
                tabel_secundar[i_sec][j_sec] = word;
                j_sec++;
                word ="";
            }
            else
            {
                word = word + x;
            }
        }
        tabel_secundar[i_sec][j_sec] = word;
        i_sec++;
        word = "";
        coloane = j_sec;
        j_sec = 0;
    }
/*
    for (int i = 0; i <= i_sec; i++) {
        for (int j = 0; j <= coloane; j++) {
            cout << tabel_secundar[i][j] << " ";
        }
        cout << "\n";
    }
*/

    //prima oara tratam cazul in care ok = true, aka stergem toata matricea,
    //lasand doar capetele de tabel

    if (ok){

        ofstream g(Filepath.c_str());

        for (int i = 0; i < coloane; i++){
            g << tabel_secundar[0][i] << " ";
        }

    } else {
        //aici vom trata cazul in care trebuie stearsa o linie sau mai multe, 
        //care indeplinesc conditia specificata in comanda
        //din fericire nu se pot pune mai multe conditii (god bless...)

        char gol[50];
        string comanda;

        cin >> gol;
        cin.get();

        cin >> comanda;

        int pozitie = -1;

        //pozitia ghilimelei se aplica doar daca vom cauta o variabila salvata ca "char"
        
        pozitie = comanda.find("'");

        if (pozitie > 0){

            comanda.erase(0, pozitie+1);
            pozitie = comanda.find("'");
            comanda.erase(pozitie, pozitie+1);

        } else {

            //daca vom cauta un "int" se va realiza o cautare dupa egal

            pozitie = comanda.find("=");
            comanda.erase(0, pozitie+1);
            pozitie = comanda.find(";");
            comanda.erase(pozitie, pozitie+1);
        }

        ofstream g(Filepath.c_str());

        bool confirmare = false; //folosim acest boolean ca sa confirmam ca exita conditia
                                //pe randul curent

        for (int i = 0; i < i_sec; i++){

            for (int j = 0; j <= coloane; j++){
                if (tabel_secundar[i][j] == comanda){
                    confirmare = true;
                }
            }
            
            //daca conditia nu exista, aka nu trebuie sters randul, acesta este scris in fisier
            if (!confirmare){
                for (int j = 0; j <= coloane; j++){
                    g << tabel_secundar[i][j] << " ";
                }
                g << "\n";
            }

            confirmare = false;
        }
    }
}


