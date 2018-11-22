#ifndef POINTARRAY_H
#define POINTARRAY_H
#include "Point.h"

template <class T>
class PointArray;

// declaracion como funcion
template <class T>
std::ostream& operator<<(std::ostream &output, const PointArray<T> &arr);

template <class T>
PointArray<T>& operator+(const PointArray<T> &arr1, const PointArray<T> &arr2);

template <typename T>
class PointArray{
    public:
        //declaracion como funcion amiga de PointArray
        friend std::ostream& operator<< <>(std::ostream &output, const PointArray<T> &arr);
        friend PointArray<T>& operator+<>(const PointArray<T> &arr1, const PointArray<T> &arr2);

        PointArray(){
            this->size = 0;
            this->points = new T[size];
        }

        PointArray(const T pts[], const int size){
            this->size = size;
            this->points = new T[size];
            for(int i = 0; i < size; i++)
            points[i] = pts[i];
        }

        PointArray(PointArray &p){
            this->size = p.getSize();
            this->points = new T[size];

            for(int i = 0; i < size; i++){
                this->points[i] = p.points[i];
            }
        }

        ~PointArray(){
            delete[] points;
        }

        int getSize(){
            return this->size;
        }

        void resize(int newSize){
            T *pts = new T[newSize];

            int minSize = (newSize > size) ? size : newSize;
            for (int i = 0; i < minSize; i++)
                pts[i] = points[i];

            delete[] points;
            size = newSize;
            points = pts;
        }

        void pushBack(T &p){
            resize(size+1);
            this->points[size-1] = p;
        }

        void insertElem(T &p, const int pos){
            resize(size+1);

            for (int i = size; i > pos; i--)
                points[i] = points[i-1];

            this->points[pos] = p;
        }

        void remove(const int pos){
            for (int i = pos; i < size; i++)
                points[i] = points[i+1];

            resize(size-1);
        }

        void print(){
            for(int i = 0; i < size; i++){
                points[i].print();
                std::cout << " ";
            }
        }

    private:
        int size;
        T *points;
};

//sobrecarga <<
template <class T>
std::ostream& operator<<(std::ostream &output, const PointArray<T> &arr){
    for (int i = 0; i < arr.size; i++)
        output << arr.points[i] << " ";
    return output;
}

//sobrecarga +
template <class T>
PointArray<T>& operator+(const PointArray<T> &arr1, const PointArray<T> &arr2){
    int minSize = (arr1.size > arr2.size) ? arr2.size : arr1.size;
    PointArray<T> *suma = new PointArray<T>;

    int i;
    for (i = 0; i < minSize; i++)
        suma->pushBack(arr1.points[i] + arr2.points[i]);

    if (minSize == arr1.size)
        for (; i < arr2.size; i++)
            suma->pushBack(arr2.points[i]);
    else
        for (; i < arr1.size; i++)
            suma->pushBack(arr1.points[i]);

    return *suma;
}
#endif // POINTARRAY_H
