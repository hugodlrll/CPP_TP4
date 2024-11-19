#include "parcelle.hpp"

Parcelle::Parcelle(int num, string prop, Polygone<int,float> forme) : numero(num), proprietaire(prop), forme(forme) {}

Parcelle::Parcelle(Parcelle & parc) : type(parc.getType()), numero(parc.getNumero()), surface(parc.getSurface()), proprietaire(parc.getProprietaire()), forme(parc.getForme()) {}       

Parcelle::~Parcelle() {}

int Parcelle::getNumero(){
    return this->numero ;
}

string Parcelle::getProprietaire(){
    return this->proprietaire ;
}

float Parcelle::getSurface(){
    return this->surface ;
}

Polygone<int,float> Parcelle::getForme(){
    return this->forme ;
}

string Parcelle::getType(){
    return this->type ;
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