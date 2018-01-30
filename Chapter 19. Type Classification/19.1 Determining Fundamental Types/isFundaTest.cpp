#include "./include/isFunda.h.h"
#include <iostream>

template <typename T>
void test(const T &t)
{
    if(isFundaT<T>::Yes)
    {
        std::cout << "T is fundamental type" << std::endl;
    }
    else
    {
        std::cout << "T is not fundamental type" << std::endl;
    }
}

class MyType
{
};

int main()
{
    test(7);
    test(MyType());
}