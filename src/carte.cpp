/**
 * @file carte.cpp
 * @author DELARUELLE Hugo DEPEYRIS Julien DARGERE Lucas LAVAUX Bastien
 * @brief Description de la classe Carte
 * @version 0.1
 * @date 2024-11-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "carte.hpp"

/**
 * @brief Constructeur par défaut de la classe Carte
 * 
 */
Carte::Carte() {}

/**
 * @brief Constructeur de la classe Carte
 * 
 * @param listeParcelles Liste des parcelles de la carte
 */
Carte::Carte(vector<Parcelle*>& listeParcelles) : listeParcelles(listeParcelles) {}

/**
 * @brief Constructeur de copie
 * 
 * @param carte Carte à copier
 */
Carte::Carte(Carte & carte) : surfaceTotale(carte.surfaceTotale), listeParcelles(carte.listeParcelles) {}

/**
 * @brief Accesseur de la liste des parcelles
 * 
 * @return vector<Parcelle>& Liste des parcelles 
 */
vector<Parcelle*>& Carte::getListeParcelles() {
  return this->listeParcelles ;
}

/**
 * @brief Setter de la liste des parcelles
 * 
 * @param listeParcelle Liste des parcelles
 */
void Carte::setListeParcelles(vector<Parcelle*>& listeParcelle) {
  this->listeParcelles = listeParcelle ;
}

/**
 * @brief Importe une carte depuis un fichier
 * 
 * @param path Chemin du fichier
 */
void importCarte(std::string path) {

} 

/**
 * @brief Exporte une carte dans un fichier
 * 
 * @param path Chemin du fichier
 */
void exportCarte(std::string path) {

}

/**
 * @brief Ajoute une parcelle à la carte
 * 
 * @param parc Parcelle à ajouter
 */
void addParcelle(Parcelle & parc) {

}

/**
 * @brief Supprime une parcelle de la carte
 * 
 * @param parc Parcelle à supprimer
 */
void delParcelle(Parcelle & parc) {

}

/**
 * @brief Surcharge de l'opérateur << pour afficher la carte
 * 
 * @param os Flux de sortie
 * @param carte Carte à afficher 
 * @return ostream&  Flux de sortie
 */
ostream& operator<<(ostream& os, Carte& carte) {
  for(vector<Parcelle*>::iterator it = carte.getListeParcelles().begin(); it!= carte.getListeParcelles().end(); it++) {
    os << *it << endl;
  }
  return os;
}


vector<string> extraireMots(const string& phrase) {
    vector<string> mots;
    istringstream flux(phrase); // Crée un flux à partir de la chaîne
    string mot;

    // Lire chaque mot séparé par un espace
    while (flux >> mot) {
        mots.push_back(mot);
    }

    return mots;
}


//Polygone<int> extrairePolygone()

void ImporZU (string data){
  vector<string> mots = extraireMots(data);
  string Zone = "ZU" ;
  int Numéro = stoi(mots[1]);
  string Propriétaire = mots[2];
  int pConstructible = stoi(mots[3]);
  int surfaceConstruite = stoi(mots[4]);
  vector<Point2D<int>> points ;
  for(int i=5;i<mots.size();i++){
    int x = 0; 
    int y = 0;
    mots[i] = mots[i].substr(1, mots[i].size() - 2); // Enlève '[' et ']'

    // Trouver la position du ';'
    size_t posPointVirgule = mots[i].find(';');
  
    // Extraire les parties avant et après le ';'
    string avantStr = mots[i].substr(0, posPointVirgule);
    string apresStr = mots[i].substr(posPointVirgule + 1);

      // Convertir les chaînes en entiers
    x = stoi(avantStr);
    y = stoi(apresStr);
    
    points.push_back(Point2D<int>(x,y)); 
  }  
}

void ImporZAU (string data){
  vector<string> mots = extraireMots(data);
  string Zone = "ZAU" ;
  int Numéro = stoi(mots[1]);
  string Propriétaire = mots[2];
  int pConstructible = stoi(mots[3]);
  cout << Zone<<endl;
  cout << Numéro<<endl;
  cout << Propriétaire<<endl;
  cout << pConstructible<<endl;
}

void ImporZA (string data){
  vector<string> mots = extraireMots(data);
  string Zone = "ZA" ;
  int Numéro = stoi(mots[1]);
  string Propriétaire = mots[2];
  string typeCulture = mots[3];
  cout << Zone<<endl;
  cout << Numéro<<endl;
  cout << Propriétaire<<endl;
  cout << typeCulture<<endl;
}

void ImporZN (string data){
  vector<string> mots = extraireMots(data);
  string Zone = "ZN" ;
  int Numéro = stoi(mots[1]);
  string Propriétaire = mots[2];
  cout << Zone<<endl;
  cout << Numéro<<endl;
  cout << Propriétaire<<endl;
  
}

void separateur(string data){
  int line = 0;
  string phrase = "";
  for (int i = 0, len = data.size(); i < len; i++)
    {
      phrase += data[i];
        // check whether parsing character is punctuation or not
      if (data[i] =='\n')
        {
          if(line ==1){
            size_t espaceIndex = phrase.find(' ');
            string Zone = phrase.substr(0, espaceIndex);
            if(Zone =="ZU"){
              ImporZU(phrase);
            } else if (Zone =="ZAU"){
              ImporZAU(phrase);
            }else if (Zone == "ZA"){
              ImporZA(phrase);
            }else if (Zone=="ZN"){
              ImporZN(phrase);
            }
          cout << ""<<endl;
          line = 0 ;
          phrase = "";
          }
          else{
            line++;
          }
        }
    }
  
  
}







