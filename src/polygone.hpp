#include "point2D.hpp"
#include <vector>

#ifndef POLYGONE_HPP
#define POLYGONE_HPP

using namespace std;

template <typename T>
class Polygone
{
    public:
        Polygone() ;
        Polygone(vector<Point2D<T>> listeSommets) ;
        Polygone(Polygone<T> & poly) ;
        vector<Point2D<T>> getSommets() ;
        void setSommets(vector<Point2D<T>> listeSommets) ;
        void addPoint(Point2D<T> p) ;
        void translate(T x, T y); 
    protected:
        vector<Point2D<T>> sommets ;
};

template <typename T>
Polygone<T>::Polygone() {}

template <typename T>
Polygone<T>::Polygone(vector<Point2D<T>> listeSommets) : sommets(listeSommets) {}

template <typename T>
Polygone<T>::Polygone(Polygone<T> & poly) : sommets(poly.getSommets()) {}

template <typename T>
vector<Point2D<T>> Polygone<T>::getSommets() {
    return this->sommets ;
}

template <typename T>
void Polygone<T>::setSommets(vector<Point2D<T>> listeSommets) {
    this->sommets = listeSommets  ;
}

template <typename T>
void Polygone<T>::addPoint(Point2D<T> p) {
    this->sommets.push_back(p);
}

template <typename T>
void Polygone<T>::translate(T x, T y) {
    for(typename vector<Point2D<T>>::iterator it = this->sommets.begin(); it != this->sommets.end(); ++it) {
        it->x += x;
        it->y += y;
    }
}

#endif