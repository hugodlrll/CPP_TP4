/**
 * @file carte.hpp
 * @author DELARUELLE Hugo DEPEYRIS Julien DARGERE Lucas LAVAUX Bastien
 * @brief Définition de la classe Carte
 * @version 0.1
 * @date 2024-11-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef CARTE_HPP
#define CARTE_HPP

#include <vector>
#include <iostream>
#include "parcelle.hpp"
#include "utilitaire.hpp"

using namespace std;

class Carte {
    public:
        Carte() ;
        Carte(vector<Parcelle*>& listeParcelles) ;
        Carte(Carte& carte) ;
        vector<Parcelle*>& getListeParcelles() ;
        void setListeParcelles(vector<Parcelle*>& listeParcelles) ;
        void importCarte(string& path) ;
        void exportCarte(string& path) ;
        void addParcelle(Parcelle& parc) ;
        void delParcelle(Parcelle& parc) ;
        friend ostream& operator<<(ostream& os, Carte& carte);
    protected:
        int surfaceTotale ;
        vector<Parcelle*> listeParcelles ;
};

#endif