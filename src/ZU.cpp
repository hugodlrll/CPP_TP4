#include "ZU.hpp"

ZU::ZU(int num, std::string prop, Polygone<int> forme, int pConstruc)
    : ZAU(num, prop, forme, pConstruc) {}

int ZU::surfaceConstructible() {
    return (((pConstructible/100) * this->getSurface()) - pConstruite);
}

void ZU::setType() {
    this->type = "ZU";
}

ostream& operator<<(ostream& os, ZU& z) {
    return os;
}