#ifndef Carte_h
#define Carte_h

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

class Carte
{


public:
    Carte(string path);
    void Export(const string& nom_fichier);
    int GetSurfaceTotale();
};

// opérateur d'affichage
#endif