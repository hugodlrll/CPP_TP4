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

template <typename T>
Point2D<T>::Point2D(T x, T y) : x(x), y(y)  {}

template <typename T>
Point2D<T>::Point2D() : x(0), y(0) {}

template <typename T>
Point2D<T>::Point2D(const Point2D<T> & p) : x(p.x), y(p.y) {}

template <typename T>
T Point2D<T>::getX() {
    return x;
}

template <typename T>
T Point2D<T>::getY() {
    return y;
}

template <typename T>
void Point2D<T>::setX(T x) {
    this->x = x;
}

template <typename T>
void Point2D<T>::setY(T y) {
    this->y = y;
}

template <typename T>
void Point2D<T>::translate(T x, T y) {
    this->x += x;
    this->y += y;
}

#endif