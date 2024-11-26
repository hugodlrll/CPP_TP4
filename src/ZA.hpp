/**
 * @file ZA.hpp
 * @author DELARUELLE Hugo, DEPEYRIS Julien, DARGERE Lucas, LAVAUX Bastien
 * @brief Définition de la classe ZA
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "ZN.hpp"
#include "Constructible.hpp"
#include <string>

#ifndef ZA_HPP
#define ZA_HPP

class ZA : public ZN, public Constructible
{
    public:
        ZA(int num, std::string prop, Polygone<int> forme, std::string culture) ;
        int surfaceConstructible() ;
        std::string getCulture() ;
        void setType() override ;
    protected:
        std::string typeCulture ;
} ;

ostream& operator<<(ostream& os, ZA& z) ;

#endif