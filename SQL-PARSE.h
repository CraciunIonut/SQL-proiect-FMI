#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;


void _CREATE (string intrare)
{
    string Filepath= "test/" + intrare + ".txt";
    ofstream g(Filepath.c_str());
    g<<"POPO CACA PIPI";
    g.close();
}
