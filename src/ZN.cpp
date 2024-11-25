#include "ZN.hpp"

using namespace std;

ZN::ZN(int num, std::string prop, Polygone<int> forme)
    : Parcelle(num, prop, forme, -1) {}

void ZN::setType() {
    this->type = "ZN" ;
}