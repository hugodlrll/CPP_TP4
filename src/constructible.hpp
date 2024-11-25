#include "Parcelle.hpp"

#ifndef CONSTRUCTIBLE_HPP
#define CONSTRUCTIBLE_HPP

class Constructible : Parcelle
{
    public:
        Constructible();
        virtual int surfaceConstructible() const = 0;
} ;

#endif