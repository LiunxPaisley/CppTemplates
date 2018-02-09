#include <cxxabi.h>
#include <iostream>
#include <string>
#include <typeinfo>

#include "./include/6funcPtr.h"

#define TYPE_OF(objectname)                                                             \
    \
{                                                                                  \
        int status = 0;                                                                 \
        char *realname = abi::__cxa_demangle(typeid(objectname).name(), 0, 0, &status); \
        std::cout << "Types of " #objectname ": " << realname << std::endl;             \
        delete realname;                                                                \
    \
}

double seven()
{
    return 7.0;
}

std::string more()
{
    return std::string("more");
}

template <typename FunctorType>
void demo(FunctorType func)
{
    std::cout << "Functor returns type: " << typeid(typename FunctorType::ReturnT).name() << std::endl;
    TYPE_OF(typename FunctorType::ReturnT);
    std::cout << "Functor returns value: " << func() << std::endl;
}

int main()
{
    demo(func_ptr(seven));
    demo(func_ptr(more));
}