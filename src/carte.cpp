#include "Carte.h"
#include "point2D.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <sstream> // Pour utiliser istringstream

using namespace std;

string readFileIntoString(const string& path) {
  string  content;
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    content = string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
    input_file.close();
  //cout << content<<endl;
  return content;
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
  

     
      
  
 
  cout << Zone<<endl;
  cout << Numéro<<endl;
  cout << Propriétaire<<endl;
  cout << pConstructible<<endl;
  cout << surfaceConstruite<<endl;
  
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



Carte::Carte(string path){
  string text= readFileIntoString(path);
  separateur(text);
}



