//Defualt Constructor
template <typename T>
myvector<T>::myvector()
{
    m_array = new T[0];
    m_size = 0;
}

//Paramatized Constructor
template <typename T>
myvector<T>::myvector(const int size)
{
    m_array = new T[size];
    m_size = size;
}

//Copy Constructir
template <typename T>
myvector<T>::myvector(const myvector &source)
{
    delete m_array;

    m_array = new T[source.m_size];

    for(int i = 0; i < source.m_size; i++)
    {
        m_array[i] = source.m_array[i];
    }
    m_size = source.m_size;

}

//Operator = 
template <typename T>
myvector<T>& myvector<T>::operator=(const myvector<T> &source)
{
    delete m_array;

    m_array = new T[source.m_size];

    for(int i = 0; i < source.m_size; i++)
    {
        m_array[i] = source.m_array[i];
    }
    
    m_size = source.m_size;
}

//Unary -
template <typename T>
myvector<T> myvector<T>::operator-()const
{

    myvector<T> temp(m_size);

    for(int i = 0; i < m_size; i++)
    {
        temp[i] = m_array[i] *-1;
    }

    return temp;
}

//Subtraction of two myvector
template <typename T>
myvector<T> myvector<T>::operator-(const myvector<T> &source)const
{
    myvector<T> temp(m_size);
    
    if(m_size == source.m_size)
    {
        for(int i = 0; i < m_size; i++)
        {
            temp[i] = m_array[i] - source[i];
        }   
    }
    else
    {
        throw std::out_of_range( "Size not equal");
    }

    return temp;
}

//Addition of two myvector
template <typename T>
myvector<T> myvector<T>::operator+(const myvector<T> &source)const
{
    myvector<T> temp(m_size);
    
    if(m_size == source.m_size)
    {
        for(int i = 0; i < m_size; i++)
        {
            temp[i] = m_array[i] + source[i];
        }
    }
    else
    {
        throw std::out_of_range( "Size not equal");
    }

    return temp;
}

//Dot Product
template <typename T>
double myvector<T>::operator*(const myvector<T> &source)const
{
    double total = 0;

    if(m_size == source.m_size)
    {
        for(int i = 0; i < m_size; i++)
        total += (m_array[i] * source[i]);
        
    }
    else
    {
        throw std::out_of_range( "Size not equal");
    }

    return total;

}

//Read elements of the vector
template <typename T>
T myvector<T>::operator[](int index)const
{
    if(m_size >= index)
    {
        return m_array[index];
    }
    else
    {
        throw std::out_of_range( "Index out of bounds");
    }

}

//Read elements of the vector
template <typename T>
T& myvector<T>::operator[](int index)
{
    if(m_size>= index)
    {
        return m_array[index];
    }
    else
    {
        throw std::out_of_range( "Index out of bounds");
    }
}

//Size getter
template <typename T>
int myvector<T>::getSize()const
{
    return m_size;
}

//Output
template <typename T>
std::ostream& operator<<(std::ostream& os, const myvector<T> &obj)
{
    for(int i = 0; i < obj.getSize(); i++)
    {
        os << obj[i] << " ";
    }
    return os;  
}

//Input
template <typename T>
std::istream& operator>>(std::istream& in, myvector<T> &obj)
{
    for(int i = 0; i < obj.getSize(); i++)
    {
        in >> obj[i];
    }

    return in;
}

//guass_Sidel
template <typename T>
void guass_Sidel(const std::vector<T>& matrix)
{
    int loop = matrix.size();
    int interation = 3;
    while(iteration > 0)
    {
        for(int i = 0; i < loop; i++)
        {

        }
    }
}