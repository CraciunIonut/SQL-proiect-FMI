#pragma once

#include <iostream>
#include <string>
#include <direct.h>

using namespace std;

void _create_database()// functie pentru a crea directorul cu numele selectat de noi
{
	string database_name;
	cin >> database_name;
	_mkdir(database_name.c_str());
}


string _select_database()// functie pentru a selecta in care director lucram.
{
	string database_name;
	cin >> database_name;

	return database_name;
}