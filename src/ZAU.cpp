#include "ZAU.hpp"

ZAU::ZAU(int num, std::string prop, Polygone<int> forme, int pConstruc)
    : Parcelle(num, prop, forme, pConstruc) {}

int ZAU::surfaceConstructible() {
    return ((pConstructible/100) * this->getSurface());
}

void ZAU::setType() {
    this->type = "ZAU";
}

ostream& operator<<(ostream& os, ZAU& z) {
    return os;
}