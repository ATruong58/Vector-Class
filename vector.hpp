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

    for(int i = 0; i < size; i++)
    {
        m_array[i] = 0;
    }
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

//Product of a number and a myvector
template <typename T>
myvector<T> myvector<T>::operator*(const T rhs)const
 {
     myvector<T> temp(m_size);
  
    for(int i = 0; i < m_size; i++)
    {
        temp[i] = m_array[i] * rhs;
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
    std::vector<myvector<double>> diffVector;
    myvector<double> totalVector = matrix[matrix.size()-1];
    int loop = matrix.size()-1;
    bool empty = true;
    double y;
    double temp;
    double count = 0;
    double a[loop][loop+1];
    double x[loop] = { 0 };
    double accuracy = .001;
    
    //Put in matrix into correct column by transposing them
    for(int i = 0; i < loop; i++)
    {
        for(int j = 0; j <= loop; j++)
        {
            a[i][j] = matrix[j][i];
        }
    }
    //Make matrix diagonally Strong
    for (int i = 0; i < loop; i++)
    {
        for (int j = i + 1; j < loop; j++)
        {
            if (abs(a[i][i]) < abs(a[j][i]))
            { 
                for (int k = 0; k <= loop ; k++)
                {
                    double temp = a[i][k];
                    a[i][k] = a[j][k];
                    a[j][k] = temp;
                }
            }
        }
    }      
    //Start applying Guass Method
    do{
        for(int i = 0; i < loop; i++)               
        {
            y = x[i];
            x[i] = a[i][loop];
            for(int j = 0; j < loop; j++)
            {
                if (j != i)
                x[i] = x[i] - a[i][j] * x[j];
            }
            x[i] = x[i]/a[i][i];
            if (abs(x[i] - y) <= accuracy)
            {
                count++;
            }            
        }    
    }while(count < 50);

    //Subtract the augmented vector with the product of the corresponding
    //a1v1 * a2v2 ..... *anvn
    for(int i = 0; i < matrix.size()-1; i++)
    {
        totalVector = totalVector - (matrix[i] * x[i]);   
    }

    //if the totalvector is full of 0 then the matrix is linearly dependent
    for(int i = 0; i < totalVector.getSize(); i++)
    {
        if(totalVector[i] != 0)
        {
            empty = false;
        }

    }
    
    //prints out if the matrix is lin dependent or not
    if(empty)
    {
        std::cout << 1 << std::endl;

        for(int i = 0; i < loop; i++)
        {
            std::cout << x[i] << " ";
        }  

        std::cout << std::endl;

    }
    else
    {
        std::cout << 0 << std::endl;
    }

    std::cout << accuracy << std::endl;
    


    

    
}