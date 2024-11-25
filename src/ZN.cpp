/**
 * @file ZN.cpp
 * @author DELARUELLE Hugo, DEPEYRIS Julien, DARGERE Lucas, LAVAUX Bastien
 * @brief Description de la classe ZN
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "ZN.hpp"

using namespace std;

/**
 * @brief Constructeur de la classe ZN
 * 
 * @param num Numéro de la parcelle
 * @param prop Nom du propriétaire de la parcelle
 * @param forme Polygone représentant la forme de la parcelle
 */
ZN::ZN(int num, std::string prop, Polygone<int> forme)
    : Parcelle(num, prop, forme, -1) {}

/**
 * @brief Setter du type de la parcelle
 * 
 */
void ZN::setType() {
    this->type = "ZN" ;
}