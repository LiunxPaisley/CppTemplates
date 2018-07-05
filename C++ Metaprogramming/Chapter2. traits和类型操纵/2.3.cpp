//
// Created by liupai on 18-7-4.
//

//#include "type_name.h"

#include <iostream>
#include <type_traits>

template <typename T>
struct type_desriptor
{
    // type_desriptor()
    // {
    //     realname = abi::__cxa_demangle(typeid(T).name(), 0, 0, &status);
    // }
    // ~type_desriptor()
    // {
    //     delete realname;
    // }
    // char* realname;
    // int status;
    
};

template <typename T>
std::ostream& operator<<(std::ostream& o, type_desriptor<T>)
{
    o << "unknown type: " << typeid(T).name() << "\n";
    return o;
}

template <typename T>
std::ostream& operator<<(std::ostream& o, type_desriptor<T*>)
{
    o << type_desriptor<T>() << "* ";
    return o;
}

template <typename T>
std::ostream& operator<<(std::ostream& o, type_desriptor<T&>)
{
    o << type_desriptor<T>() << "& ";
    return o;
}

template <typename T>
std::ostream& operator<<(std::ostream& o, type_desriptor<const T>)
{
    o << type_desriptor<T>() << "const ";
    return o;
}

template <>
std::ostream& operator<<(std::ostream& o, type_desriptor<char>)
{
    o << "char ";
    return o;
}

template <>
std::ostream& operator<<(std::ostream& o, type_desriptor<short>)
{
    o << "short ";
    return o;
}

template <>
std::ostream& operator<<(std::ostream& o, type_desriptor<int>)
{
    o << "int ";
    return o;
}

template <>
std::ostream& operator<<(std::ostream& o, type_desriptor<long>)
{
    o << "long ";
    return o;
}

int main()
{
    std::cout << type_desriptor<int>() << "\n" /*<< type_desriptor<float[100]>() */
            << type_desriptor<int&>() << "\n";
    std::cout << type_desriptor<char*>() << "\n";
    std::cout << type_desriptor<long const*&>() << "\n";
}