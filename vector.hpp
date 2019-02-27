template <typename T>
myvector<T>::myvector()
{
    m_array = new T[1];
}

template <typename T>
void myvector<T>::grow()
{
    T *temp = new T[size*2];

    for(int i = 0; i < size; i++)
    {
        temp[i] = m_array[i];
    }

    delete [] m_array;

    m_array = temp;

    size = size*2;
}

template <typename T>
myvector<T>::myvector(const T* sourceArray)
{
    while(sizeof(sourceArray)/(sizeof(sourceArray[0])) > size)
    {
        grow();
    }

    for(int i = 0; i < sizeof(sourceArray)/(sizeof(sourceArray[0])); i++)
    {
        m_array[i] = sourceArray[i];
    }
}

template <typename T>
myvector<T>::myvector(const myvector &source)
{
    while(source.size > size)
    {
        grow();
    }

    for(int i = 0; i < source.size; i++)
    {
        m_array[i] = source.m_array[i];
    }

}
template <typename T>
myvector<T>& myvector<T>::operator=(const myvector<T> &source)const
{
    while(source.size > size)
    {
        grow();
    }

    for(int i = 0; i < source.size; i++)
    {
        m_array[i] = source.m_array[i];
    }
}

template <typename T>
myvector<T> myvector<T>::operator-()const
{
    for(int i = 0; i < size;)
    {
        m_array[i] *= -1;
    }
}

template <typename T>
myvector<T> myvector<T>::operator-(const myvector<T> &source)const
{
    T *temp = new T[size];

    if(size == source.size)
    {
        for(int i = 0; i < size; i++)
        temp[i] = m_array[i] - source[i];
        
    }
    else
    {
        throw "Size not equal";
    }

    return myvector<T>(temp);
}

template <typename T>
myvector<T> myvector<T>::operator+(const myvector<T> &source)const
{
    T *temp = new T[size];

    if(size == source.size)
    {
        for(int i = 0; i < size; i++)
        temp[i] = m_array[i] + source[i];
        
    }
    else
    {
        throw "Size not equal";
    }

    return myvector<T>(temp);
}

template <typename T>
double myvector<T>::operator*(const myvector<T> &source)const
{
    T *temp = new T[size];
    double total = 0;

    if(size == source.size)
    {
        for(int i = 0; i < size; i++)
        total += (m_array[i] * source[i]);
        
    }
    else
    {
        throw "Size not equal";
    }

    return total;

}

template <typename T>
T myvector<T>::operator[](int index)const
{
    if(size >= index)
    {
        return m_array[index];
    }
    else
    {
        throw "Index out of bounds";
    }

}

template <typename T>
T& myvector<T>::operator[](int index)
{
    if(size >= index)
    {
        return m_array[index];
    }
    else
    {
        throw "Index out of bounds";
    }
}

template <typename T>
void myvector<T>::pushback(const T &value)
{
    if(curr == size)
    {
        grow();
    }

    m_array[curr] = value;
    curr++;
}

template <typename T>
int myvector<T>::getSize()const
{
    return size;
}

template <typename T>
int myvector<T>::getCurr()const
{
    return curr;
}

template <typename T>
void myvector<T>::incrementCurr()
{
    curr++;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const myvector<T> &obj)
{
    std::cout << obj.getSize();
    for(int i = 0; i < obj.getSize(); i++)
    {
        os << obj[i] << " ";
    }
    return os;  
}

template <typename T>
std::istream& operator>>(std::istream& in, myvector<T> &obj)
{
    T input;

    if(obj.getCurr()+1 >= obj.getSize())
    {
        obj.grow();
    }
    in >> input; 
    std::cout << input << std::endl;
    
    obj[obj.getCurr()] = input;

    obj.incrementCurr();


    return in;
}