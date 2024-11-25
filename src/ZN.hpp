/**
 * @file ZN.hpp
 * @author DELARUELLE Hugo, DEPEYRIS Julien, DARGERE Lucas, LAVAUX Bastien
 * @brief Définition de la classe ZN
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Parcelle.hpp"

#ifndef ZN_HPP
#define ZN_HPP

class ZN : public Parcelle
{
    public:
        ZN(int num, std::string prop, Polygone<int> forme);
        void setType() override;
} ;

#endif