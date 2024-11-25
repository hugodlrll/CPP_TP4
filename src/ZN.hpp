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