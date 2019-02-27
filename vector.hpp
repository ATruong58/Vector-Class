template <typename T>
myvector<T>::myvector()
{
    m_array = new T[100];
    m_size = 100;
    m_curr = 0;

}

template <typename T>
myvector<T>::myvector(const int size)
{
    m_array = new T[size];
    m_size = size;
    m_curr = 0;
}

template <typename T>
myvector<T>::myvector(const myvector &source)
{
    for(int i = 0; i < source.m_size; i++)
    {
        m_array[i] = source.m_array[i];
    }

}
template <typename T>
myvector<T>& myvector<T>::operator=(const myvector<T> &source)const
{

    for(int i = 0; i < source.m_size; i++)
    {
        m_array[i] = source.m_array[i];
    }
}

template <typename T>
myvector<T> myvector<T>::operator-()const
{
    for(int i = 0; i < m_size; i++)
    {
        m_array[i] *= -1;
    }
}

template <typename T>
myvector<T> myvector<T>::operator-(const myvector<T> &source)const
{
    T *temp = new T[m_size];

    if(m_size == source.m_size)
    {
        for(int i = 0; i < m_size; i++)
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
    T *temp = new T[m_size];

    if(m_size == source.m_size)
    {
        for(int i = 0; i < m_size; i++)
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
    T *temp = new T[m_size];
    double total = 0;

    if(m_size == source.m_size)
    {
        for(int i = 0; i < m_size; i++)
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
    if(m_size >= index)
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
    if(m_size>= index)
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
    m_array[m_curr] = value;
    m_curr++;
}

template <typename T>
int myvector<T>::getSize()const
{
    return m_size;
}

template <typename T>
int myvector<T>::getCurr()const
{
    return m_curr;
}

template <typename T>
void myvector<T>::incrementCurr()
{
    m_curr++;
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

    in >> input; 
    std::cout << input << std::endl;
    
    obj[obj.getCurr()] = input;

    obj.incrementCurr();


    return in;
}