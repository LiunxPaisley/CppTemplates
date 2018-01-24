#include <iostream>
#include <list>
#include <stack>
#include <typeinfo>
#include <vector>

template <typename T>
class ElementT; // 基本模板

template <typename T>
class ElementT<std::vector<T>> // 局部特化
{
public:
    typedef T Type;
};

template <typename T>
class ElementT<std::list<T>> // 局部特化
{
public:
    typedef T Type;
};

template <typename T>
class ElementT<std::stack<T>> // 局部特化
{
public:
    typedef T Type;
};

template <typename T>
void print_element_type(const T &c)
{
    std::cout << "Container of "
              << typeid(typename ElementT<T>::Type).name()
              << " elements."
              << std::endl;
}

int main()
{
    std::stack<bool> s;
    print_element_type(s);
}