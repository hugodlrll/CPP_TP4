/**
 * @file parcelle.cpp
 * @author DELARUELLE Hugo, DEPEYRIS Julien, DARGERE Lucas, LAVAUX Bastien
 * @brief Description de la classe Parcelle
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 */

#include "parcelle.hpp"
#include<iostream>

/**
 * @brief Constructeur de la classe Parcelle
 * 
 * @param num Numéro de la parcelle
 * @param prop Nom du propriétaire de la parcelle
 * @param forme Polygone représentant la forme de la parcelle
 */
Parcelle::Parcelle(int num, string prop, Polygone<int> forme, int pConstruc) : numero(num), proprietaire(prop), forme(forme), pConstructible(pConstruc), surface(calculSurface(forme)) {}

/**
 * @brief Constructeur de copie
 * 
 * @param parc Copie de la parcelle
 */
Parcelle::Parcelle(const Parcelle & parc) : type(parc.type), numero(parc.numero), surface(parc.surface), proprietaire(parc.proprietaire), forme(parc.forme) {}       

/**
 * @brief Accesseur du numéro de la parcelle
 * 
 * @return int : Numéro de la parcelle 
 */
int Parcelle::getNumero() const {
    return numero ;
}

/**
 * @brief Accesseur du propriétaire de la parcelle
 * 
 * @return string : Nom du propriétaire de la parcelle
 */
string Parcelle::getProprietaire() const {
    return proprietaire ;
}

/**
 * @brief Accesseur de la surface de la parcelle
 * 
 * @return float : Surface de la parcelle
 */
float Parcelle::getSurface() const {
    return surface ;
}

/**
 * @brief Accesseur de la forme de la parcelle
 * 
 * @return Polygone<int> : Forme de la parcelle
 */
Polygone<int> & Parcelle::getForme() { 
    return forme ;
}

/**
 * @brief Accesseur du type de la parcelle
 * 
 * @return string : Type de la parcelle
 */
string Parcelle::getType() const {
    return type ;
}

/**
 * @brief Accesseur de la surface constructible de la parcelle
 * 
 * @return int : Surface constructible de la parcelle
 */
int Parcelle::getPConstruct() const {
    return pConstructible ;
}

/**
 * @brief Setter du numéro de la parcelle
 * 
 * @param n Numéro de la parcelle
 */
void Parcelle::setNumero(int n){
    this-> numero = n ;
}

/**
 * @brief Setter du propriétaire de la parcelle
 * 
 * @param prop Nom du propriétaire de la parcelle
 */
void Parcelle::setProprietaire(string prop){
    this-> proprietaire = prop ;
}

/**
 * @brief Setter de la forme de la parcelle
 * 
 * @param forme Polygone représentant la forme de la parcelle
 */
void Parcelle::setForme(Polygone<int> forme) {
    this->forme = forme ;
    calculSurface(forme);
}

/**
 * @brief Setter du taux constructible de la parcelle
 * 
 * @param p taux constructible de la parcelle
 */
void Parcelle::setPConstruct(int p) {
    this->pConstructible = p ;
}

/**
 * @brief Calcul de la surface de la parcelle
 * 
 * @param forme Polygone représentant la forme de la parcelle
 * @return float : Surface de la parcelle
 */
float Parcelle::calculSurface(Polygone<int> forme) {
    float result = 0 ;
    vector<Point2D<int>>::iterator itNext ;
    for(typename vector<Point2D<int>>::iterator it = forme.getSommets().begin(); it != forme.getSommets().end(); it++)
    {
        if(std::next(it,1) != forme.getSommets().end()){
            itNext = std::next(it,1) ;
        } else {
            itNext = forme.getSommets().begin() ;
        }
        result +=  it->getX()*itNext->getY() - itNext->getX()*it->getY() ;
    }
    return (abs(0.5*result)) ;
}

/**
 * @brief Surcharge de l'opérateur << pour afficher une parcelle
 * 
 * @param os Flux de sortie
 * @param p Parcelle à afficher
 * @return ostream& : Flux de sortie
 */
ostream& operator<<(ostream& os, Parcelle& p) {
    os << "Parcelle n° " << p.getNumero() << " :" << endl;
    os << "\tType : " << p.getType() << endl;
    os << "\tPolygone : " << p.getForme() << endl;
    os << "\tPropriétaire : " << p.getProprietaire() << endl;
    os << "\tSurface : " << p.getSurface() << endl;
    return os;
}