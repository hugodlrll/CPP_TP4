/**
 * @file carte.cpp
 * @author DELARUELLE Hugo, DEPEYRIS Julien, DARGERE Lucas, LAVAUX Bastien
 * @brief Description de la classe Carte
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "carte.hpp"

/**
 * @brief Lecture d'un fichier
 * 
 * @param path lien du fichier
 */
string Carte::readFileIntoString(const string& path) {
  string content;
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    content = string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>())+string("\n");
    input_file.close();
  
  return content;
}


/**
 * @brief Extraction des mots d'une phrase
 * 
 * @param phrase phrase a traiter
 */
vector<string> Carte::extraireMots(const string& phrase) {
    vector<string> mots;
    istringstream flux(phrase); // Cree un flux à partir de la chaîne
    string mot;
    // Lire chaque mot separe par un espace
    while (flux >> mot) {
        mots.push_back(mot);
    }
    return mots;
}


/**
 * @brief import d'une ZU
 * 
 * @param data donnees a passer en paramètres de la ZU
 */
void Carte::ImporZU (string data){
  vector<string> mots = extraireMots(data);
  string Zone = "ZU" ;
  int Numero = stoi(mots[1]);
  string Proprietaire = mots[2];
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
  Polygone<int> poly = Polygone<int>(points);
  ZU* parcelle = new ZU( Numero, Proprietaire, poly , pConstructible, surfaceConstruite);
  ListaParcelles.push_back(parcelle);
}

/**
 * @brief import d'une ZAU
 * 
 * @param data donnees a passer en paramètres de la ZAU
 */
void Carte::ImporZAU (string data){
  vector<string> mots = extraireMots(data);
  string Zone = "ZAU" ;
  int Numero = stoi(mots[1]);
  string Proprietaire = mots[2];
  int pConstructible = stoi(mots[3]);
  vector<Point2D<int>> points ;
  for(int i=4;i<mots.size();i++){
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
  Polygone<int> poly = Polygone<int>(points);
  ZAU* parcelle = new ZAU( Numero, Proprietaire, poly , pConstructible);
  
  ListaParcelles.push_back(parcelle);

}

/**
 * @brief import d'une ZA
 * 
 * @param data donnees a passer en paramètres de la ZA
 */
void Carte::ImporZA (string data){
  vector<string> mots = extraireMots(data);
  string Zone = "ZA" ;
  int Numero = stoi(mots[1]);
  string Proprietaire = mots[2];
  string typeCulture = mots[3];
  vector<Point2D<int>> points ;
  for(int i=4;i<mots.size();i++){
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
  Polygone<int> poly = Polygone<int>(points);
  ZA* parcelle = new ZA( Numero, Proprietaire, poly , typeCulture);
  ListaParcelles.push_back(parcelle);
}

/**
 * @brief import d'une ZN
 * 
 * @param data donnees a passer en paramètres de la ZN
 */
void Carte::ImporZN (string data){
  vector<string> mots = extraireMots(data);
  string Zone = "ZN" ;
  int Numero = stoi(mots[1]);
  string Proprietaire = mots[2];
  vector<Point2D<int>> points ;
  for(int i=3;i<mots.size();i++){
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
  Polygone<int> poly = Polygone<int>(points);
  ZN* parcelle = new ZN( Numero, Proprietaire, poly,0);
  ListaParcelles.push_back(parcelle);  
}

void Carte::separateur(string data){
  int line = 0;
  string phrase = "";
  for (int i = 0 ; i <  data.size(); i++)
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
          
          line = 0 ;
          phrase = "";
          }
          else{
            line++;
          }
        }
    }
}

/**
 * @brief Constructeur de la classe Carte
 * 
 * @param path lien du fichier des parcelles
 */
Carte::Carte(string path){
  string text= readFileIntoString(path);
  separateur(text);
}

/**
 * @brief Obtention de la surface totale de toute les parcelles 
 * 
 * 
 */
int Carte::GetSurfaceTotale(){
  int SurfaceTotale = 0;
  for(int i = 0 ; i<ListaParcelles.size(); i++){
    SurfaceTotale = SurfaceTotale + ListaParcelles[i]->getSurface();
  }
  return SurfaceTotale;
}

/**
 * @brief Exportation des parcelles dans in fichier
 * 
 * @param data donnees a passer en paramètres de la ZU
 */

void Carte::Export(const string& nom_fichier){
   ofstream fichier(nom_fichier);
    // Verifier si le fichier est ouvert
    if (fichier.is_open()) {
     for(int i = 0 ; i<ListaParcelles.size(); i++){
        // ecrire dans le fichier
         fichier<< ListaParcelles[i]->getType()<<" ";
         fichier<< ListaParcelles[i]->getNumero()<<" ";
         fichier<< ListaParcelles[i]->getProprietaire()<<" ";


        if ((ListaParcelles[i]->getType())=="ZA"){
          auto za = dynamic_cast<ZA*>(ListaParcelles[i]) ;
          fichier << za->getCulture() << "\n";

        }else if((ListaParcelles[i]->getType())=="ZAU"){
          fichier<< ListaParcelles[i]->getPConstruct()<<"\n";

        }else if((ListaParcelles[i]->getType())=="ZN"){
          fichier<<"\n";
         
        }else if((ListaParcelles[i]->getType())=="ZU"){
          fichier<< ListaParcelles[i]->getPConstruct()<<" ";
          auto zu = dynamic_cast<ZU*>(ListaParcelles[i]) ;
          fichier << zu->getPContruite() << "\n";
         
        }
        fichier<< ListaParcelles[i]->getForme()<<"\n";
     }
        // Fermer le fichier
        fichier.close(); 
    } else {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    }
}

/**
 * @brief Importation d'une parcelle
 * 
 * @param type Type de parcelle
 * @param numero Numero de la parcelle
 * @param proprietaire Proprietaire de la parcelle
 * @param pConstructible Taux de constructibilite de la parcelle 
 * @param surfaceConstruite Surface construite de la parcelle
 * @param typeCulture Type de culture de la parcelle
 * @param ListeDePoint Liste des points de la parcelle
 */
void Carte::ImportParcelle(string type ,int numero, string proprietaire, int pConstructible , int surfaceConstruite, string typeCulture, string ListeDePoint ){
string phrase = "";
vector<Point2D<int>> points ;
vector<string> mots = extraireMots(ListeDePoint);
for(int i=0;i<mots.size();i++){
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

  if(type == "ZA"){
    Polygone<int> poly = Polygone<int>(points);
    ZA* parcelle = new ZA( numero, proprietaire, poly , typeCulture);
    ListaParcelles.push_back(parcelle);
    

  }else if(type == "ZAU"){
    Polygone<int> poly = Polygone<int>(points);
    ZAU* parcelle = new ZAU( numero, proprietaire, poly , pConstructible);
    ListaParcelles.push_back(parcelle);
    

  }
  else if(type == "ZN"){
    Polygone<int> poly = Polygone<int>(points);
    ZN* parcelle = new ZN( numero, proprietaire, poly,-1);
    ListaParcelles.push_back(parcelle);
    

  }else if(type == "ZU"){
    Polygone<int> poly = Polygone<int>(points);
    ZU* parcelle = new ZU( numero, proprietaire, poly , pConstructible, surfaceConstruite);
    ListaParcelles.push_back(parcelle);
    

  }

}


