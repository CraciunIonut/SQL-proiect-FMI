#pragma once
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

	while (input >> tabel[i_sec][j_sec]) {
		j_sec += 1;

		if (tabel[i_sec][j_sec] == "\n") {
			coloane = j_sec;
			break;
		}
	}

}



// _CREATE creeaza un tabel cu un nume care il dam noi in directorul test
//  Pune coloanele care trebuiesc si le tine minte intr-o matrice.
void _CREATE(string intrare, string line, string tabel[100][100],string database_name)
{
	string Filepath = database_name +"/" + intrare + ".txt";
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
		g << tabel[0][i] << ((i == j - 1) ? "" : " "); // conditie ? true : false 
	}

	g << "\n";
	g.close();
}
/*
citim COMANDA DE LA TASTATURA INSERT apoi stie ca urmeaza into.
citim numele tabelelui si il deschidem
printr-un algoritm citim coloanele in care trebuie sa inseram si scoatem virgulele de la ele 
si dupa aceea printr-un vector ne punem poziitile necesare pentru fiecare coloana.
*/

void _INSERT(string intrare, string tabel[100][100],string database_name)
{
	string Filepath = database_name +"/" + intrare + ".txt";
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

	for (int i = 0; i <= coloane; i++) {
		vector_aparitii[index] = tabel_secundar[0][i];
		//cout << vector_aparitii[index] << " ";
		index++;
	}

	cin >> comanda;

	if (comanda.length() == 1) {
		cin >> comanda;
	}

	index -= 1;

	//ne folosim de asta ca sa stim in ce coloane trebuie sa inseram
	//UPDATE: Nu il mai folosim deloc momentan, dar l-am lasat aici in caz ca
	//        poate reusim sa il reparam sau poate ne trebuie in alta parte
	//        Acum e doar pe post de citire in gol pentru numele coloanelor din insert,
	//        deci tot e oarecum util.

	while (cin >> comanda && comanda.back() != ')') {

		int i = 0;

		comanda.erase(comanda.end() - 1, comanda.end());

		int j = 0;

		for (i = 0; i < index; i++) {
			if (vector_aparitii[i] == comanda) {
				vec[j] = i;
				j += 1;
			}
		}
	}

	cin >> comanda;

	int contor = i_sec;

	int index_vec = 0;


	//aici incercam sa eliminam orice nu este de bagat in tabel
	//ceva gen ooga booga caveman brain

	while (cin >> comanda && comanda.back() != ';') {

		int pozitie = -1;

		pozitie = comanda.find("(");

		if (pozitie == 0) {
			comanda.erase(0, 1);
		}

		pozitie = comanda.find("'");

		if (pozitie == 0) {
			comanda.erase(0, 1);
		}

		pozitie = comanda.find("'");

		if (pozitie > 0) {
			comanda.erase(pozitie, pozitie + 1);
		}

		pozitie = comanda.find("',");

		if (pozitie > 0) {
			comanda.erase(pozitie, pozitie + 2);
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

		if (pozitie > 0 && comanda.at(pozitie - 1) == ')') {
			comanda.erase(pozitie - 1, pozitie + 1);
			contor++;
			index_vec = -1;
		}
		else if (pozitie > 0 && comanda.at(pozitie - 1) != ')') {
			comanda.erase(pozitie, pozitie + 1);
		}

		//index_vec este indexul coloanei
		//contor este indexul liniei

		cout << "comanda: " << comanda << "\n";

		if (index_vec <= index) {
			tabel_secundar[contor][index_vec] = comanda;
			cout << "index: " << index << " tabel_secundar: " << tabel_secundar[contor][index_vec] << " contor: " << contor << " index_vec: " << index_vec << " vec: " << vec[index_vec] << "\n";
			index_vec += 1;
		}


	}

	ofstream g(Filepath.c_str());

	for (int i = 0; i <= contor; i++) {
		for (int j = 0; j <= index; j++) {
			g << tabel_secundar[i][j] << " ";
		}
		g << "\n";
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

void _DELETE (string intrare, string tabel[100][100], string database_name) {

	bool ok = false; //folosim un ok ca sa ne dam seama daca stergem tot tabelul sau doar
					 //o singura linie

	if (intrare.back() == ';') {
		intrare.erase(intrare.end() - 1, intrare.end());
		ok = true;
	}

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

	if (ok) {

		ofstream g(Filepath.c_str());

		for (int i = 0; i < coloane; i++) {
			g << tabel_secundar[0][i] << " ";
		}

	}
	else {
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

		if (pozitie > 0) {

			comanda.erase(0, pozitie + 1);
			pozitie = comanda.find("'");
			comanda.erase(pozitie, pozitie + 1);

		}
		else {

			//daca vom cauta un "int" se va realiza o cautare dupa egal

			pozitie = comanda.find("=");
			comanda.erase(0, pozitie + 1);
			pozitie = comanda.find(";");
			comanda.erase(pozitie, pozitie + 1);
		}

		ofstream g(Filepath.c_str());

		bool confirmare = false; //folosim acest boolean ca sa confirmam ca exita conditia
								 //pe randul curent

		for (int i = 0; i < i_sec; i++) {

			for (int j = 0; j <= coloane; j++) {
				if (tabel_secundar[i][j] == comanda) {
					confirmare = true;
				}
			}

			//daca conditia nu exista, aka nu trebuie sters randul, acesta este scris in fisier
			if (!confirmare) {
				for (int j = 0; j <= coloane; j++) {
					g << tabel_secundar[i][j] << " ";
				}
				g << "\n";
			}

			confirmare = false;
		}
	}
}

//pentru UPDATE e mai tricky. trebuie facut in asa fel incat sa se respecte mai
//multe posibilitati de sintaxa
// avem UPDATE nume_tabel SET coloana1=valoare, coloana2=valoare (ENTER)
// WHERE conditie;

// bazat pe conditie se poate updata un singur camp sau mai multe 

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
/*	
	for (int i = 0; i <= i_sec; i++) {
		for (int j = 0; j <= coloane; j++) {
			cout << tabel_secundar[i][j] << " ";
		}
		cout << "\n";
	}
*/

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
	// 	camp += variabila_noua.at(i);
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
		if (tabel_secundar[i][j_conditie] == conditie){
			i_conditie = i;
			break;
		}
	}

	//conditia este in casuta tabel_secundar[i_conditie][j_conditie]
	//trebuie sa editam linia pe care exista conditia, conform cerintelor
	//din statement-ul set

	//verificam daca s-a gasit conditia 

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