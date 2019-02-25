/////////////////////////////////////////////////////////
//   Name: Alan Truong                                 //
//   Date: 2/12/2019                                   //
//   Course: Object Orient Numerical Method            //
//   Purpose: Learning how to use templated class      //
//            and refamiliarize ourself with OOP       //
//                                                     //
/////////////////////////////////////////////////////////

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <vector>
#include <string>

template <class T>
class myvector
{
    private:
        T *m_array;
        int size = 1;
        int curr = 0;
        
        
    
    public:
        myvector();
        ~myvector(){}
        myvector(const T* sourceArray);
        myvector(const myvector &source);

        myvector<T>& operator=(const myvector<T> &source)const;

        myvector<T> operator-()const;
        myvector<T> operator-(const myvector<T> &source)const;
        myvector<T> operator+(const myvector<T> &source)const;

        T operator[](int index)const;
        T& operator[](int index);
        double operator*(const myvector<T> &source)const;
        void grow();
        void pushback(const T &value);
        void incrementCurr();
        int getCurr()const;
        int getSize()const;

        
    
};

template <typename U>
        std::ostream& operator<<(std::ostream& os, const myvector<U> &obj);
        
        template <typename U>
        std::istream& operator>>(std::istream& in, myvector<U> &obj);

#include "vector.hpp"

#endif 