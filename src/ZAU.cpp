/**
 * @file ZAU.cpp
 * @author DELARUELLE Hugo, DEPEYRIS Julien, DARGERE Lucas, LAVAUX Bastien
 * @brief Description de la classe ZAU
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "ZAU.hpp"

/**
 * @brief Constructeur de la classe ZAU
 * 
 * @param num Numéro de la parcelle
 * @param prop Nom du propriétaire de la parcelle
 * @param forme Polygone représentant la forme de la parcelle
 * @param pConstruc Surface constructible de la parcelle
 */
ZAU::ZAU(int num, std::string prop, Polygone<int> forme, int pConstruc)
    : Parcelle(num, prop, forme, pConstruc) {}

/**
 * @brief Calcul de la surface constructible
 * 
 * @return int surface constructible
 */
int ZAU::surfaceConstructible() {
    return ((pConstructible/100) * this->getSurface());
}

/**
 * @brief Setter du type de la parcelle
 * 
 */
void ZAU::setType() {
    this->type = "ZAU";
}

/**
 * @brief Surcharge de l'opérateur << pour afficher une parcelle ZAU
 * 
 * @param os Flux de sortie
 * @param z Parcelle à afficher
 * @return ostream& Flux de sortie
 */
ostream& operator<<(ostream& os, ZAU& z) {
    os << "% constructible : " << z.getPConstruct() << endl ;
    return os;
}