/**
 * @file polygone.hpp
 * @author DELARUELLE Hugo, DEPEYRIS Julien, DARGERE Lucas, LAVAUX Bastien
 * @brief Définition de la classe template Polygone
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "point2D.hpp"
#include <vector>
#include <iostream>

#ifndef POLYGONE_HPP
#define POLYGONE_HPP

using namespace std;

template <typename T>
class Polygone;

template <typename T>
ostream& operator<<(ostream&, Polygone<T> &);

template <typename T>
class Polygone
{
    public:
        Polygone() ;
        Polygone(const vector<Point2D<T>> listeSommets) ;
        Polygone(const Polygone<T> & poly) ;
        vector<Point2D<T>>& getSommets() ;
        void setSommets(vector<Point2D<T>> listeSommets) ;
        void addPoint(Point2D<T> p) ;
        void translate(T x, T y); 
    protected:
        vector<Point2D<T>> sommets;
};

/**
 * @brief Constructeur par défaut de la classe Polygone
 * 
 * @tparam T Type de données
 */
template <typename T>
Polygone<T>::Polygone() {}

/**
 * @brief Constructeur de la classe Polygone
 * 
 * @tparam T Type de données
 * @param listeSommets Liste des sommets du polygone
 */
template <typename T>
Polygone<T>::Polygone(const vector<Point2D<T>> listeSommets) : sommets(listeSommets) {}

/**
 * @brief Constructeur de copie
 * 
 * @tparam T Type de données
 * @param poly Polygone à copier
 */
template <typename T>
Polygone<T>::Polygone(const Polygone<T> & poly) : sommets(poly.sommets) {}

/**
 * @brief Getter des sommets du polygone
 * 
 * @tparam T Type de données
 * @return vector<Point2D<T>>& Liste des sommets
 */
template <typename T>
vector<Point2D<T>>& Polygone<T>::getSommets() {
    return sommets ;
}

/**
 * @brief Setter des sommets du polygone
 * 
 * @tparam T Type de données
 * @param listeSommets Liste des sommets
 */
template <typename T>
void Polygone<T>::setSommets(vector<Point2D<T>> listeSommets) {
    sommets = listeSommets  ;
}

/**
 * @brief Ajout d'un point au polygone
 * 
 * @tparam T Type de données
 * @param p Point à ajouter
 */
template <typename T>
void Polygone<T>::addPoint(Point2D<T> p) {
    this->sommets.push_back(p);
}

/**
 * @brief Translation du polygone
 * 
 * @tparam T Type de données
 * @param x Translation en x
 * @param y Translation en y
 */
template <typename T>
void Polygone<T>::translate(T x, T y) {
    for(typename vector<Point2D<T>>::iterator it = this->sommets.begin(); it != this->sommets.end(); ++it) {
        it->translate(x,y);
    }
}

/**
 * @brief Surcharge de l'opérateur <<
 * 
 * @tparam T Type de données
 * @param os Flux de sortie
 * @param p Polygone à afficher
 * @return ostream& Flux de sortie
 */
template <typename T>
ostream& operator<<(ostream& os, Polygone<T> & p) {
    for(typename vector<Point2D<T>>::iterator it = p.getSommets().begin(); it != p.getSommets().end(); it++)
    {
        os << "[" << it->getX() << "," << it->getY() << "] ";
    }
    return os;
}

#endif