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
        void setType() ;
    protected:
        std::string typeCulture ;
} ;

ostream& operator<<(ostream& os, ZA& z) ;

#endif