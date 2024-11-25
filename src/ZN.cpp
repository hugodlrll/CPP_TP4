#include "ZN.hpp"

using namespace std;

ZN::ZN(int num, std::string prop, Polygone<int> forme)
    : Parcelle(num, prop, forme) {}

void ZN::setType() {
    this->type = "ZN";
}