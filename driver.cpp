#include "vector.h"
#include <vector>
#include <fstream>

int main(int argc,  char * argv[])
{
    std::vector<myvector<double>> matrix;
    myvector<double> temp;
    int loop;
    try
    {
        if(argc > 1)
        {
            std::ifstream fs(argv[1]);
            if (!(fs.is_open() && fs.good()))
            {
                throw "File not read correctly\n";
            }
            fs >> loop;
            if(loop < 2)
            {
                throw "Too little amount of dataset\n";
            }
            for(int i = 0; i < loop; i++)
            {
                for(int j = 0; j < loop; j++)
                {
                    std::cout << "Hello\n";
                    fs >> temp;
                    matrix.push_back(temp);
                }
            }
        }
        else
        {
            throw "No arguments.\n";
        }    
    }
    catch (std::string message)
    {
        std::cerr << message << std::endl;
    }

  
    
    // std::cout << matrix[0] + matrix[1] << std::endl;
    // std::cout << matrix[0] - matrix[1] << std::endl;
    // std::cout << matrix[0] * matrix[1] << std::endl;
    
    return 0;
}