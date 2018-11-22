#ifndef POINT_H
#define POINT_H
#include <iostream>

template <class T>
class Point;

//declaracion como funcion
template <class T>
std::ostream& operator<<(std::ostream &output, const Point<T> &punto);

template <class T>
Point<T>& operator+(const Point<T> &punto1, const Point<T> &punto2);

template <class T>
class Point{
    public:
        // declaracion en clase
        friend std::ostream& operator<< <>(std::ostream &output, const Point<T> &punto);
        friend Point<T>& operator+<>(const Point<T> &punto1, const Point<T> &punto2);

        Point(){
            x = 0;
            y = 0;
        }

        Point(Point<T> &p){
            x = p.x;
            y = p.y;
        }

        Point(const T u, const T v) : x(u), y(v) {}

        void offset(T nx, T ny){
            x += nx;
            y += ny;
        }
/*
        void imprimir()
        {
         std::cout << "(" << x << ", " << y << ")" << std::endl;
        }
*/
        T getX(){
            return x;
        }

        T getY(){
            return y;
        }

        void setX(T x){
            this->x = x;
        }

        void setY(T y){
            this->y = y;
        }

        void print(){
            std::cout << "(" << x << ", " << y << ")";
        }

    private:
        T x,y;
};

//sobrecarga <<
template <class T>
std::ostream& operator<<(std::ostream &output, const Point<T> &punto){
    output << "(" << punto.x << ", " << punto.y << ")";
    return output;
}

//sobrecarga +
template <class T>
Point<T>& operator+(const Point<T> &punto1, const Point<T> &punto2){
    Point<T> *suma = new Point<T>;
    suma->x = punto1.x + punto2.x;
    suma->y = punto1.y + punto2.y;

    return *suma;
}

#endif // POINT_H
