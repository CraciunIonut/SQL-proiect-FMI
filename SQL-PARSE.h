#include <fstream>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;


void _CREATE (string intrare)
{
    char fname[50];
    // Construct file name here.
    sprintf(fname, "test/%s", intrare);
    ofstream ostrm(fname);
}
