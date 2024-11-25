#include "ZAU.hpp"

#ifndef ZU_HPP
#define ZU_HPP

class ZU : public ZAU
{
    public:
        ZU(int num, std::string prop, Polygone<int> forme, int pConstruc);
        int surfaceConstructible();
        void setType();
    protected:
        int pConstruite;
} ;

ostream& operator<<(ostream& os, ZU& z);

#endif