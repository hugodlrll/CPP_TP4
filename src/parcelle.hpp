#include <string>
#include <iostream>
#include "polygone.hpp"

#ifndef PARCELLE_HPP
#define PARCELLE_HPP

using namespace std;
class Parcelle {
    public:
        Parcelle(int num, string prop, Polygone<int,float>forme) ;
        Parcelle(Parcelle & parc) ;
        int getNumero() ;
        std::string getProprietaire() ;
        float getSurface() ;
        Polygone<int,float> getForme() ;
        std::string getType() ;
        void setNumero(int n);
        void setProprietaire(std::string prop);
        void setForme(Polygone<int> forme);
        virtual void setType(string type) const = 0;
    protected:
        std::string type ;
        int numero ;
        std::string proprietaire ;
        float surface ;
        Polygone<int> forme;
        int pConstructible;
} ;

ostream& operator<<(ostream& os, Parcelle & const p) {
    os << "Parcelle n° " << p.getNumero() << " :" << endl;
    os << "\tType : " << p.getType() << endl;
    os << "\tPolygone : " << p.getForme() <<endl;
    os << "\tPropriétaire : " << p.getProprietaire() << endl;
    os << "\tSurface : " << p.getSurface() << endl;
}

#endif