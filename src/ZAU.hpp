#include "Constructible.hpp"

#ifndef ZAU_HPP
#define ZAU_HPP

class ZAU : public Parcelle, public Constructible
{
    public:
        ZAU(int num, std::string prop, Polygone<int> forme, int pConstruc);
        int surfaceConstructible();
        void setType();
} ;

ostream& operator<<(ostream& os, ZAU& z);

#endif