//pentru UPDATE e mai tricky. trebuie facut in asa fel incat sa se respecte mai
//multe posibilitati de sintaxa
// avem UPDATE nume_tabel SET coloana1=valoare, coloana2=valoare (ENTER)
// WHERE conditie;

// bazat pe conditie se poate updata un singur camp sau mai multe

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <vector>
//#include "SQL.h"

using namespace std;

void _UPDATE (string intrare, string tabel[100][100], string database_name) {

    string Filepath = database_name + "/" + intrare + ".txt";

    ifstream f(Filepath.c_str());

    //citirea intr-o matrice secundara este copy-paste de la insert

    int i_sec = 0, j_sec = 0, coloane = 0;

    string linie_curenta;
    string word = "";
    string tabel_secundar[100][100];

    while (getline(f, linie_curenta)) {

        for (auto x : linie_curenta)
        {
            if (x == ' ')
            {
                tabel_secundar[i_sec][j_sec] = word;
                j_sec++;
                word = "";
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
  
    // for (int i = 0; i <= i_sec; i++) {
    //     for (int j = 0; j <= coloane; j++) {
    //         cout << tabel_secundar[i][j] << " ";
    //     }
    //     cout << "\n";
    // }


    char gol[50];
    string variabila_noua;//aici citim valoarea care o va inlocui pe cea veche

    cin >> gol;
    cin.get();

    cin >> variabila_noua;

    //cout << variabila_noua;

    // string camp;//aici ne luam campul care trebuie schimbat

    // int pozitie_camp = -1;

    // pozitie_camp = variabila_noua.find("=");

    // for (int i = 0; i < pozitie_camp; i++){
    //  camp += variabila_noua.at(i);
    // }

    //cout << camp;

    //aici tratam cazul in care se introduce un "char" pentru schimbare
    int pozitie = -1;

    //pozitie = variabila_noua.find(",");

    string camp[100];//aici ne luam campuruile care trebuie schimbate
    int index_camp = 0;
    int index_valoare = 0;
    string valoare[100];//aici ne luam valorile care trebuie schimbate

    int pozitie_camp = -1;
    
    if (variabila_noua.back() == ','){
        
        pozitie_camp = variabila_noua.find("=");

        for (int i = 0; i < pozitie_camp; i++){
            camp[index_camp] += variabila_noua.at(i);
        }

        index_camp += 1;

        //cout << camp;

        pozitie = variabila_noua.find("'");

        if (pozitie > 0){
            variabila_noua.erase(0, pozitie+1);
            //cout << variabila_noua;
            pozitie = variabila_noua.find("'");
            variabila_noua.erase(pozitie, pozitie+2);
            //cout << variabila_noua;
        } else if (pozitie < 0) {
            //aici tratam cazul in care se introduce un "int"
            //se face cautare dupa egal

            pozitie = variabila_noua.find("=");
            variabila_noua.erase(0, pozitie+1);
            variabila_noua.erase(variabila_noua.end()-1, variabila_noua.end());
            //cout << variabila_noua;
        }

        valoare[index_valoare] = variabila_noua;

        index_valoare += 1;

        while (cin >> variabila_noua){

            if (variabila_noua.back() != ','){
                break;
            }

            pozitie_camp = variabila_noua.find("=");

            for (int i = 0; i < pozitie_camp; i++){
                camp[index_camp] += variabila_noua.at(i);
            }

            index_camp += 1;

            //cout << camp;

            pozitie = variabila_noua.find("'");

            if (pozitie > 0){
                variabila_noua.erase(0, pozitie+1);
                //cout << variabila_noua;
                pozitie = variabila_noua.find("'");
                variabila_noua.erase(pozitie, pozitie+2);
                //cout << variabila_noua;
            } else if (pozitie < 0) {
                //aici tratam cazul in care se introduce un "int"
                //se face cautare dupa egal

                pozitie = variabila_noua.find("=");
                variabila_noua.erase(0, pozitie+1);
                variabila_noua.erase(variabila_noua.end()-1, variabila_noua.end());
                //cout << variabila_noua;
            }

            valoare[index_valoare] = variabila_noua;

            index_valoare += 1;
        }
    }

    //aici vom ajunge daca se schimba o singura valoare
    //aka nu se detecteaza virgula
    //sau aici se va introduce ultima valoare, cea care nu a avut
    //virgula la final si care a intrerupt while-ul

    pozitie_camp = variabila_noua.find("=");

    for (int i = 0; i < pozitie_camp; i++){
        camp[index_camp] += variabila_noua.at(i);
    }
    index_camp += 1;
    

    pozitie = variabila_noua.find("'");

    if (pozitie > 0){
        variabila_noua.erase(0, pozitie+1);
        pozitie = variabila_noua.find("'");
        variabila_noua.erase(pozitie, pozitie+1);
        //cout << variabila_noua;
    } else if (pozitie < 0) {
        //aici tratam cazul in care se introduce un "int"
        //se face cautare dupa egal

        pozitie = variabila_noua.find("=");
        variabila_noua.erase(0, pozitie+1);
        //cout << variabila_noua;
    }

    valoare[index_valoare] = variabila_noua;
    index_valoare += 1;



    //in acest stadiu avem valoarea noua care trebuie inlocuita
    //si campul in care trebuie introdusa 

    //acum trebuie sa salvam conditia si campul conditiei (daca exista)

    cin >> gol;
    cin.get();

    string conditie;

    cin >> conditie;

    string camp_conditie;

    pozitie_camp = conditie.find("=");

    for (int i = 0; i < pozitie_camp; i++){
        camp_conditie += conditie.at(i);
    }

    int pozitie_conditie = -1;

    pozitie_conditie = conditie.find("'");

    if (pozitie_conditie > 0){
        conditie.erase(0, pozitie_conditie+1);
        pozitie_conditie = conditie.find("'");
        conditie.erase(pozitie_conditie, pozitie_conditie+1);
        //cout << variabila_noua;
    } else if (pozitie_conditie < 0) {
        //aici tratam cazul in care se introduce un "int"
        //se face cautare dupa egal

        pozitie_conditie = conditie.find("=");
        conditie.erase(0, pozitie_conditie+1);
        pozitie_conditie = conditie.find(";");
        conditie.erase(pozitie_conditie, pozitie_conditie+1);
        //cout << variabila_noua;
    }

    //cout << "conditia este  " << conditie << " campul ei este " << camp_conditie;

    //in acest moment avem salvate conditia, campul conditiei,
    //valoarea noua, si campul acesteia

    /*
    for (int i = 0; i < index_camp; i++){
        cout << "valoarea este " << valoare[i] << " campul este " << camp[i] <<"\n";
    }

    cout << "valoarea conditiei este " << conditie << " si campul conditiei este " << camp_conditie;
    */

    //acum trebuie sa facem inlocuirea si scrierea
    //avem doar o conditie, vom tine asta in minte pentru a 
    //face functia mai eficienta

    int i_conditie = 0, j_conditie = 0;

    for (int i = 0; i <= coloane; i++){
        if (tabel_secundar[0][i] == camp_conditie){
            j_conditie = i;
            break;
        }
    }

    for (int i = 0; i < i_sec; i++){
        // cout << tabel_secundar[i][j_conditie] << " ";
        if (tabel_secundar[i][j_conditie] == conditie){
            i_conditie = i;
            break;
        }
    }

    //conditia este in casuta tabel_secundar[i_conditie][j_conditie]
    //trebuie sa editam linia pe care exista conditia, conform cerintelor
    //din statement-ul set

    //verificam daca s-a gasit conditia 

    // cout << "Conditia este " << conditie << "\n";
    // cout << "Conditia trebuie sa fie " << tabel_secundar[i_conditie][j_conditie] << "\n";
    // cout << "i_cond: " << i_conditie << ", j_cond: " << j_conditie;

    if (tabel_secundar[i_conditie][j_conditie] == conditie){

        //acum stim ca trebuie editata linia i_conditie

        for (int j = 0; j <= coloane; j++){
            for (int i_val = 0; i_val < index_valoare; i_val++){
                if (tabel_secundar[0][j] == camp[i_val]){
                    tabel_secundar[i_conditie][j] = valoare[i_val];
                }
            }
        }

    } else cout << "Conditie invalida";

    ofstream g(Filepath.c_str());

    for (int i = 0; i < i_sec; i++){
        for (int j = 0; j <= coloane; j++){
            g << tabel_secundar[i][j] << " ";
        }
        g << "\n";
    }
}