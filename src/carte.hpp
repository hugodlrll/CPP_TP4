/**
 * @file carte.hpp
 * @author DELARUELLE Hugo DEPEYRIS Julien DARGERE Lucas LAVAUX Bastien
 * @brief Définition de la classe Carte
 * @version 0.1
 * @date 2024-12-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef Carte_h
#define Carte_h

#include "point2D.hpp"
#include "polygone.hpp"
#include "ZN.hpp"
#include "ZA.hpp"
#include "ZAU.hpp"
#include "ZU.hpp"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <vector>
#include <sstream> // Pour utiliser istringstream

using namespace std;

class Carte
{
    public:
        Carte(string path);
        void Export(const string& nom_fichier);
        int GetSurfaceTotale();
        void ImportParcelle(string type ,int numero, string proprietaire, int pConstructible , int surfaceConstruite, string typeCulture, string ListeDePoint );
        vector<string> extraireMots(const string& phrase);
        void separateur(string data);
        string readFileIntoString(const string& path);
        void ImporZAU (string data);
        void ImporZU (string data);
        void ImporZA (string data);
        void ImporZN (string data);
    protected:
        vector<Parcelle*> ListaParcelles;
};

// opérateur d'affichage
#endif