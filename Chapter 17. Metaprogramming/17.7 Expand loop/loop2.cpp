#include <iostream>

#include "./include/loop2.h"

int main()
{
    int a[3] = {1, 2, 3};
    int b[3] = {5, 6, 7};
    std::cout << "dot_product<3>(a,b) = " << dot_product<3>(a, b) << std::endl;
    std::cout << "dot_product<3>(a,a) = " << dot_product<3>(a, a) << std::endl;
}