#include "ZA.hpp"

ZA::ZA(std::string culture, int sMax, int pMax) : typeCulture(culture), sConstructibleMax(sMax), pConstructibleMax(pMax) {}

std::string ZA::getCulture() {
    return this->typeCulture;
}