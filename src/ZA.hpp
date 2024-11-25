#include "ZN.hpp"
#include "Constructible.hpp"

#ifndef ZA_HPP
#define ZA_HPP

class ZA : ZN, Constructible
{
    public:
        ZA(std::string culture, int sMax, int pMax) ;
        int surfaceConstructible() ;
        std::string getCulture() ;
    protected:
        std::string typeCulture ;
        const int pConstructibleMax ;
        const int sConstructibleMax ;
} ;

ostream& operator<<(ostream& os, ZA & const z) {
    os << "Type culture : " << z.getCulture() << endl;
    return os;
}

#endif