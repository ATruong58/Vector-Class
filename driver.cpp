#include "vector.h"
#include <vector>
#include <fstream>

int main(int argc,  char * argv[])
{
    myvector<double> p(5);
    double i = 7;

    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;

    std::cout << p << std::endl;

    myvector<double> q(5);

    q = p;

    p[1] = 55;

    p = -p;

    std::cout << p << std::endl;

    std::cout << q << std::endl;




    //std::cout << p;
    
    return 0;
}