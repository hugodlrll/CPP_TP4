/**
 * @file ZAU.hpp
 * @author DELARUELLE Hugo, DEPEYRIS Julien, DARGERE Lucas, LAVAUX Bastien
 * @brief Définition de la classe ZAU
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "parcelle.hpp"
#include "constructible.hpp"
#include <string>

#ifndef ZAU_HPP
#define ZAU_HPP

class ZAU : public Parcelle, public Constructible
{
    public:
        ZAU(int num, std::string prop, Polygone<int> forme, int pConstruc);
        int surfaceConstructible() override;
        void setType() override ;
} ;

ostream& operator<<(ostream& os, ZAU& z);

#endif