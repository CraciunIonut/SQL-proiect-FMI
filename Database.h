#pragma once

#include <iostream>
#include <string>
//#include <direct.h>
#include <sys/stat.h>

using namespace std;

void _create_database()// functie pentru a crea directorul cu numele selectat de noi
{
	string database_name;
	cin >> database_name;
	mkdir(database_name.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
}


string _select_database()// functie pentru a selecta in care director lucram.
{
	string database_name;
	cin >> database_name;

	return database_name;
}