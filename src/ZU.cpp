/**
 * @file ZU.cpp
 * @author DELARUELLE Hugo, DEPEYRIS Julien, DARGERE Lucas, LAVAUX Bastien
 * @brief Description de la classe ZU
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "ZU.hpp"

/**
 * @brief Constructeur de la classe ZU
 * 
 * @param num Numéro de la parcelle
 * @param prop Nom du propriétaire de la parcelle
 * @param forme Polygone représentant la forme de la parcelle
 * @param pConstruc Surface constructible de la parcelle
 */
ZU::ZU(int num, std::string prop, Polygone<int> forme, int pConstruc)
    : ZAU(num, prop, forme, pConstruc) {}

/**
 * @brief Calcul de la surface constructible
 * 
 * @return int surface constructible
 */
int ZU::surfaceConstructible() {
    return (((pConstructible/100) * this->getSurface()) - pConstruite);
}

/**
 * @brief Setter du type de la parcelle
 * 
 */
void ZU::setType() {
    this->type = "ZU";
}

/**
 * @brief Accesseur du taux de constuction de la parcelle
 * 
 */
int ZU::getPContruite() {
    return this->pConstruite;
}

/**
 * @brief Surcharge de l'opérateur << pour afficher une parcelle ZU
 * 
 * @param os Flux de sortie
 * @param z Parcelle à afficher
 * @return ostream& Flux de sortie
 */
ostream& operator<<(ostream& os, ZU& z) {
    os << "% constructible : " << z.getPConstruct() << endl ;
    os << "surface construite : " << (z.getSurface() * (z.getPContruite()/100)) ;
    os << "surface à construire restante : " << z.surfaceConstructible() << endl ;
    return os;
}