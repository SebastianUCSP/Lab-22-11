#include <iostream>
#include "Point.h"
#include "PointArray.h"

using namespace std;

int main(){

    Point<int> a(2, 3);
    cout << "Point int: ";
    cout << a;
    cout << endl;

    Point<double> b(3.5, 6.7);
    cout << "Point double: ";
    cout << b;
    cout << endl;

    Point<float> c(4.56546456, 5.43242354);
    cout << "Point float: ";
    cout << c;
    cout << endl;

    Point<string> d("7abc", "8xyz");
    cout << "Point string: ";
    cout << d;
    cout << endl;


    Point<int> point1(1,1);
    Point<int> point2(2,2);
    Point<int> point3(3,3);
    Point<int> point4 = point2 + point3;

    cout << "Puntos:" << endl;
    cout << point2 << point3 << endl;

    cout << "Suma puntos: " << endl;
    cout << point4 << endl;
    cout << endl;


    PointArray<Point<int> > Array;
    Array.pushBack(point1);
    Array.pushBack(point2);
    Array.pushBack(point3);
    Array.pushBack(point4);

    Point<int> point5(1,1);
    Point<int> point6(2,2);
    Point<int> point7(3,3);
    Point<int> point8(4,4);
    Point<int> point9(5,5);

    PointArray<Point<int> > Array2;
    Array2.pushBack(point5);
    Array2.pushBack(point6);
    Array2.pushBack(point7);
    Array2.pushBack(point8);
    Array2.pushBack(point9);

    cout << "Arreglo 1: " << endl;
    cout << Array << endl;
    cout << "Arreglo 2: " << endl;
    cout << Array2 << endl;
    cout << endl;

    cout << "Suma de arreglos: " << endl;
    PointArray<Point<int> > Array3 = Array + Array2;
    cout << Array3 << endl;

    return 0;
}
