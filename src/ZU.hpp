/**
 * @file ZU.hpp
 * @author DELARUELLE Hugo, DEPEYRIS Julien, DARGERE Lucas, LAVAUX Bastien
 * @brief Définition de la classe ZU
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "ZAU.hpp"

#ifndef ZU_HPP
#define ZU_HPP

class ZU : public ZAU
{
    public:
        ZU(int num, std::string prop, Polygone<int> forme, int pConstruc);
        int surfaceConstructible();
        void setType();
        int getPContruite();
    protected:
        int pConstruite;
} ;

ostream& operator<<(ostream& os, ZU& z);

#endif