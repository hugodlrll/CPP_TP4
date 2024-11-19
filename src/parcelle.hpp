#include <string>
#include "polygone.hpp"

#ifndef PARCELLE_HPP
#define PARCELLE_HPP

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
        void setType(string type);
    protected:
        std::string type ;
        int numero ;
        std::string proprietaire ;
        float surface ;
        Polygone<int> forme;
        int pConstructible;
} ;

#endif