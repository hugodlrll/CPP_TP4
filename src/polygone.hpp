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

template <typename T>
Polygone<T>::Polygone() {}

template <typename T>
Polygone<T>::Polygone(const vector<Point2D<T>> listeSommets) : sommets(listeSommets) {}

template <typename T>
Polygone<T>::Polygone(const Polygone<T> & poly) : sommets(poly.sommets) {}

template <typename T>
vector<Point2D<T>>& Polygone<T>::getSommets() {
    return sommets ;
}

template <typename T>
void Polygone<T>::setSommets(vector<Point2D<T>> listeSommets) {
    sommets = listeSommets  ;
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

template <typename T>
ostream& operator<<(ostream& os,Polygone<T> & p) {
    for(typename vector<Point2D<T>>::iterator it = p.getSommets().begin(); it != p.getSommets().end(); it++)
    {
        os << "[" << it->getX() << "," << it->getY() << "] ";
    }
    return os;
}

#endif