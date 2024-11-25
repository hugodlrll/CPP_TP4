/**
 * @file ZA.cpp
 * @author DELARUELLE Hugo, DEPEYRIS Julien, DARGERE Lucas, LAVAUX Bastien
 * @brief Description de la classe ZA
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "ZA.hpp"

/**
 * @brief Constructeur de la classe ZA
 * 
 * @param num Numéro de la parcelle
 * @param prop Nom du propriétaire de la parcelle
 * @param forme Polygone représentant la forme de la parcelle
 * @param culture Type de culture de la parcelle
 */
ZA::ZA(int num, std::string prop, Polygone<int> forme, std::string culture)
    : ZN(num, prop, forme), typeCulture(culture) {}

/**
 * @brief Calcul de la surface constructible
 * 
 * @return int surface constructible
 */
int ZA::surfaceConstructible() {
    int s = static_cast<int>(0.1 * this->getSurface());
    if(s > 200)
        return 200 ;
    else
        return s ;
}

/**
 * @brief Accesseur du type de culture
 * 
 * @return string : Type de culture
 */
std::string ZA::getCulture() {
    return this->typeCulture ;
}

/**
 * @brief Setter du type de la parcelle
 * 
 */
void ZA::setType() {
    this->type = "ZA" ;
}

/**
 * @brief Surcharge de l'opérateur << pour afficher une parcelle ZA
 * 
 * @param os Flux de sortie
 * @param z Parcelle à afficher
 * @return ostream& Flux de sortie
 */
ostream& operator<<(ostream& os, ZA& z) {
    os << "Type culture : " << z.getCulture() << endl ;
    return os ;
}