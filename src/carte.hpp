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
    void ImportParcelle(string type ,int numero, string proprietaire, int pConstructible , int surfaceConstruite, string typeCulture, string ListeDePoint );
};

// opérateur d'affichage
#endif