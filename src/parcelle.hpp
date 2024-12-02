/**
 * @file parcelle.hpp
 * @author DELARUELLE Hugo, DEPEYRIS Julien, DARGERE Lucas, LAVAUX Bastien
 * @brief Définition de la classe Parcelle
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <string>
#include <iostream>
#include "polygone.hpp"

#ifndef PARCELLE_HPP
#define PARCELLE_HPP

using namespace std;
class Parcelle {
    public:
        Parcelle(int num, string prop, Polygone<int> forme, int pConstruc) ; 
        Parcelle(const Parcelle & parc) ;

        int getNumero() const ;
        std::string getProprietaire() const ;
        float getSurface() const ;
        Polygone<int> & getForme() ;
        std::string getType() const ;
        int getPConstruct() const ;

        void setNumero(int n) ;
        void setProprietaire(std::string prop) ;
        void setForme(Polygone<int> forme) ;
        void setPConstruct(int p) ;
        float calculSurface(Polygone<int> forme) ;
        virtual void setType() = 0 ;

        friend ostream& operator<<(ostream& os, Parcelle& p) ;
    protected:
        std::string type ;
        int numero ;
        std::string proprietaire ;
        float surface ;
        Polygone<int> forme ;
        int pConstructible ;
} ;



#endif