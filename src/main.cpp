#include "ZN.hpp"
#include "Carte.h"

using namespace std;

int main(void) {
    /*vector<Point2D<int>> listeSommets;
    Point2D<int> p1(1,1);
    Point2D<int> p2(2,1);
    Point2D<int> p3(2,2);
    Point2D<int> p4(1,2);
    listeSommets.push_back(p1);
    listeSommets.push_back(p3);
    listeSommets.push_back(p2);
    listeSommets.push_back(p4);
    Polygone<int> poly(listeSommets);
    std::cout << poly << std::endl;
    ZN zn(12, "Hugo", poly, -1);
    zn.setType();
    std::cout << zn << endl;
    cout << zn.getProprietaire() << endl;
    cout << zn.getNumero() << endl;
    cout << zn.getSurface() << endl;*/

  


  std::cout << "Hello World!\n"; 
  Carte carte =Carte("../Parcelles.txt");

  
  carte.Export();
   


    return 0;
}