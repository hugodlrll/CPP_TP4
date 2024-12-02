#include "ZN.hpp"
#include "carte.hpp"

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
  
  Carte carte =Carte("../Parcelles.txt");

  cout<<carte.GetSurfaceTotale()<< " m2\n";
  carte.ImportParcelle("ZA",50,  "DARGERE", 0, 0,"Blé", "[80;0] [100;0] [100;100] [80;100]" );
  carte.ImportParcelle("ZAU",250,  "LAVAUX", 50, 0,"", "[80;0] [100;0] [100;100] [80;100]" );
  carte.ImportParcelle("ZN",150,  "DELARUELLE", 0, 0,"", "[80;0] [100;0] [100;100] [80;100]" );
  carte.ImportParcelle("ZU",530,  "DEPEYRIS", 45, 7,"", "[80;0] [100;0] [100;100] [80;100]" );
  carte.Export("mon_fichier.txt");
   


    return 0;
}