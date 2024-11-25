#include "ZA.hpp"

ZA::ZA(int num, std::string prop, Polygone<int> forme, std::string culture)
    : ZN(num, prop, forme), typeCulture(culture) {}

int ZA::surfaceConstructible() {
    int s = static_cast<int>(0.1 * this->getSurface());
    if(s > 200)
        return 200 ;
    else
        return s ;
}

std::string ZA::getCulture() {
    return this->typeCulture ;
}

void ZA::setType() {
    this->type = "ZA" ;
}

ostream& operator<<(ostream& os, ZA& z) {
    os << "Type culture : " << z.getCulture() << endl ;
    return os ;
}