/**
 * @file point2D.hpp
 * @author DELARUELLE Hugo, DEPEYRIS Julien, DARGERE Lucas, LAVAUX Bastien
 * @brief Définition de la classe template Point2D
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef POINT2D_HPP
#define POINT2D_HPP

template <typename T>
class Point2D {
    public:
        Point2D(T x, T y) ;
        Point2D() ;
        Point2D(const Point2D<T> & p) ;
        T getX() ;
        T getY() ;
        void setX(T x) ;
        void setY(T y) ;
        void translate(T x, T y) ;
    protected:
        T x, y;
} ;

/**
 * @brief Constructeur de la classe Point2D
 * 
 * @tparam T Type de données
 * @param x coordonnée x
 * @param y coordonnée y
 */
template <typename T>
Point2D<T>::Point2D(T x, T y) : x(x), y(y)  {}

/**
 * @brief Constructeur par défaut de la classe Point2D
 * 
 * @tparam T Type de données
 */
template <typename T>
Point2D<T>::Point2D() : x(0), y(0) {}

/**
 * @brief Constructeur de copie de la classe Point2D
 * 
 * @tparam T Type de données
 * @param p Point2D à copier
 */
template <typename T>
Point2D<T>::Point2D(const Point2D<T> & p) : x(p.x), y(p.y) {}

/**
 * @brief Accesseur de la coordonnée x
 * 
 * @tparam T Type de données
 * @return T coordonnée x
 */
template <typename T>
T Point2D<T>::getX() {
    return x;
}

/**
 * @brief Accesseur de la coordonnée y
 * 
 * @tparam T Type de données
 * @return T coordonnée y
 */
template <typename T>
T Point2D<T>::getY() {
    return y;
}

/**
 * @brief Setter de la coordonnée x
 * 
 * @tparam T Type de données
 * @param x coordonnée x
 */
template <typename T>
void Point2D<T>::setX(T x) {
    this->x = x;
}

/**
 * @brief Setter de la coordonnée y
 * 
 * @tparam T Type de données
 * @param y coordonnée y
 */
template <typename T>
void Point2D<T>::setY(T y) {
    this->y = y;
}

/**
 * @brief Translation du point
 * 
 * @tparam T Type de données
 * @param x déplacement en x
 * @param y déplacement en y
 */
template <typename T>
void Point2D<T>::translate(T x, T y) {
    this->x += x;
    this->y += y;
}

#endif