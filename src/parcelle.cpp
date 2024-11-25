#include "parcelle.hpp"

Parcelle::Parcelle(int num, string prop, Polygone<int> forme) : numero(num), proprietaire(prop), forme(forme) {}

Parcelle::Parcelle(const Parcelle & parc) : type(parc.type), numero(parc.numero), surface(parc.surface), proprietaire(parc.proprietaire), forme(parc.forme) {}       

int Parcelle::getNumero(){
    return numero ;
}

string Parcelle::getProprietaire(){
    return proprietaire ;
}

float Parcelle::getSurface(){
    return surface ;
}

Polygone<int> & Parcelle::getForme(){ 
    return forme ;
}

string Parcelle::getType(){
    return type ;
}


void Parcelle::setNumero(int n){
    this-> numero = n ;
}

void Parcelle::setProprietaire(string prop){
    this-> proprietaire = prop ;
}

void Parcelle::setForme(Polygone<int> forme){
    this->forme = forme ;
}

ostream& operator<<(ostream& os, Parcelle& p) {
    os << "Parcelle n° " << p.getNumero() << " :" << endl;
    os << "\tType : " << p.getType() << endl;
    os << "\tPolygone : " << p.getForme() << endl;
    os << "\tPropriétaire : " << p.getProprietaire() << endl;
    os << "\tSurface : " << p.getSurface() << endl;
    return os;
}