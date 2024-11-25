#include <string>
#include <iostream>
#include "polygone.hpp"

#ifndef PARCELLE_HPP
#define PARCELLE_HPP

using namespace std;
class Parcelle {
    public:
        Parcelle(int num, string prop, Polygone<int>forme) ; 
        Parcelle(const Parcelle & parc) ;
        int getNumero() ;
        std::string getProprietaire() ;
        float getSurface() ;
        Polygone<int> & getForme() ;
        std::string getType() ;
        void setNumero(int n);
        void setProprietaire(std::string prop);
        void setForme(Polygone<int> forme);
        float calculSurface(Polygone<int> forme);
        virtual void setType(string type) = 0;
    protected:
        std::string type ;
        int numero ;
        std::string proprietaire ;
        float surface ;
        Polygone<int> forme;
        int pConstructible;
} ;

ostream& operator<<(ostream& os, Parcelle& p);

#endif