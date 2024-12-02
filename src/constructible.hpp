/**
 * @file constructible.hpp
 * @author DELARUELLE Hugo, DEPEYRIS Julien, DARGERE Lucas, LAVAUX Bastien
 * @brief Définition de la classe abstraite Constructible
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "parcelle.hpp"

#ifndef CONSTRUCTIBLE_HPP
#define CONSTRUCTIBLE_HPP

/**
 * @class Constructible "constructible.hpp"
 */
class Constructible
{
    public:
    /**
     * @brief Retourne la surface constructible
     * @return int 
     */
        virtual int surfaceConstructible() = 0 ;
} ;

#endif