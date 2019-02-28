/*!Name: Alan Truong                                 
 *Date: 2/12/2019                                   
 *Course: Object Orient Numerical Method            
 *Purpose: Learning how to use templated class      
           and refamiliarize ourself with OOP       
 */                                                   


#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>
#include <vector>


/*! myvector class
 *
 * myvector class with overloaded operator
 *
 */
template <class T>
class myvector
{
    private:
        T *m_array;
        int m_size;
        
        
    
    public:
        /*! Constructs an empty myvector.
         *
         * \post m_array created with size of 1
         */
        myvector();

        /*! Destructor
         *
         * \post Deallocate the class
         */
        ~myvector(){}

        /*! Paramatized Constructor
         *
         * \post Creates a new vector with passed in number of element
         */
        myvector(const int size);

        /*! Copy Constructor
         *
         * \post Creates a new vector with copies of elements from source
         *       and underlying storage size equal to that of source's storage.
         */
        myvector(const myvector &source);

        /*! Operator = 
         *
         * \post Set lhs vector with copies of elements from rhs
         *       and underlying storage size equal to that of rhs's storage.
         */
        myvector<T>& operator=(const myvector<T> &source);  

        /*! Unary - 
         *
         * \return a vector with lhs value multiple by -1  
         */
        myvector<T> operator-()const;

        /*! Binary - 
         *
         * \param rhs myvector class to subtract lhs myvector class value to
         * \return A myvector class with the difference of the two 
         *
         * \pre rhs myvector class and lhs myvector class must have the same size
         *      and value assign to all index in the array 
         * \throws std::invalid_argument is thrown if size is not the same
         * 
         */
        myvector<T> operator-(const myvector<T> &source)const;

        /*! Binary + 
         *
         * \param rhs myvector class to add with lhs myvector class value to
         * \return A myvector class with the sum of the two 
         *
         * \pre rhs myvector class and lhs myvector class must have the same size
         *      and value assign to all index in the array 
         * \throws std::invalid_argument is thrown if size is not the same
         * 
         */
        myvector<T> operator+(const myvector<T> &source)const;

        /*! Reads an element of the vector.
         *
         * \param idx the index of the element to read.
         * \return The element at position idx is returned.
         *
         * \pre idx is within the range [0, length()).
         * \throws std::invalid_argument is thrown if idx is out of range.
         */
        T operator[](int index)const;

        /*! Return the element of the vector.
         *
         * \param idx the index of the element to read.
         * \return The element at position idx is returned with reference so it is changable
         *
         * \pre idx is within the range [0, length()).
         * \throws std::invalid_argument is thrown if idx is out of range.
         */
        T& operator[](int index);

        /*! Dot product 
         * \param rhs myvector to dot product with lhs.
         * \return a double with the value of the dot product
         *
         * \pre rhs myvector class and lhs myvector class must have the same size
         *      and value assign to all index in the array 
         * \throws std::invalid_argument is thrown if size is not the same
         */
        double operator*(const myvector<T> &source)const;

        /*! Getter for m_size
         *
         * \return m_size
         */
        int getSize()const;

        
    
};
        /*! Stream insertion operator for myvector class.
         *
         * \pre Stream insertion operator is defined.
         * \post The contents of the vector are printed to the ouptut stream.
         * \return the modified output stream.
         *
         */
        template <typename U>
        std::ostream& operator<<(std::ostream& os, const myvector<U> &obj);


        /*! Stream output operator for myvector class.
         *
         * \pre Stream outpit operator is defined.
         * \post The contents of the vector are read into the given variable
         * \return the modified input stream.
         *
         */
        template <typename U>
        std::istream& operator>>(std::istream& in, myvector<U> &obj);

         /*! Guass_sidel method
         *
         * \pre Stream outpit operator is defined.
         * \post The contents of the vector are read into the given variable
         * \return the modified input stream.
         *
         */
        template <typename U>
        void guass_Sidel(const std::vector<U>& matrix);

#include "vector.hpp"

#endif 