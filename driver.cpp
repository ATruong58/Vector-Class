#include "vector.h"
#include <vector>
#include <fstream>

int main(int argc,  char * argv[])
{
    std::vector<myvector<double>> matrix;
    int loop;
    double tolerance = 0.001;
    try
    {
        if(argc > 1)
        {
            std::ifstream fs(argv[1]);
            if (!(fs.is_open() && fs.good()))
            {
                throw std::out_of_range( "File not read correctly\n");
            }
            fs >> loop;
            myvector<double> temp(loop); 
            if(loop < 2)
            {
                throw std::out_of_range( "Too little amount of dataset\n");
            }

            for(int i = 0; i < loop; i++)
            {
                fs >> temp;
                matrix.push_back(temp);
            }
            
            std::cout << matrix[0] + matrix[1] << std::endl;
            std::cout << matrix[0] - matrix[1] << std::endl;
            std::cout << matrix[0] * matrix[1] << std::endl;
            std::cout << matrix[1][0]  << std::endl;
            guass_Sidel(matrix);
            

        }
        else
        {
            throw std::out_of_range( "No dataset is passed.\n");
        }
    }
    catch (std::string message)
    {
        std::cerr << message << std::endl;
    }

    return 0;
}