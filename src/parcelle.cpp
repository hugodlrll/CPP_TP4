#include "parcelle.hpp"
#include<iostream>

Parcelle::Parcelle(int num, string prop, Polygone<int> forme) : numero(num), proprietaire(prop), forme(forme), surface(calculSurface(forme)) {}

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
    calculSurface(forme);
}

float Parcelle::calculSurface(Polygone<int> forme){
    float result = 0;
    vector<Point2D<int>>::iterator itNext;
    for(typename vector<Point2D<int>>::iterator it = forme.getSommets().begin(); it != forme.getSommets().end(); it++)
    {
        if(std::next(it,1) != forme.getSommets().end()){
            itNext = std::next(it,1);
        } else {
            itNext = forme.getSommets().begin();
        }
        result +=  it->getX()*itNext->getY() - itNext->getX()*it->getY();
        std::cout << it->getX() << " * " << itNext->getY() << " - " << itNext->getX() << " * " << it->getY() << std::endl;
    }
    return (abs(0.5*result));
}

ostream& operator<<(ostream& os, Parcelle& p) {
    os << "Parcelle n° " << p.getNumero() << " :" << endl;
    os << "\tType : " << p.getType() << endl;
    os << "\tPolygone : " << p.getForme() << endl;
    os << "\tPropriétaire : " << p.getProprietaire() << endl;
    os << "\tSurface : " << p.getSurface() << endl;
    return os;
}