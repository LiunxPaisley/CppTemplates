//
// Created by liupai on 18-7-4.
//

#include "type_name.h"

#include <iostream>
#include <type_traits>

template <typename T>
struct type_desriptor
{
    type_desriptor()
    {
        realname = abi::__cxa_demangle(typeid(T).name(), 0, 0, &status);
    }
    ~type_desriptor()
    {
        delete realname;
    }
    char* realname;
    int status;
};

template <typename T>
std::ostream& operator<<(std::ostream& o, const type_desriptor<T>& td)
{
    o << td.realname << "\n";
    return o;
}


int main()
{
    std::cout << type_desriptor<int>() << type_desriptor<float[100]>() << type_desriptor<int&>();
    std::cout << type_desriptor<char*>();
    std::cout << type_desriptor<long const*&>();
}