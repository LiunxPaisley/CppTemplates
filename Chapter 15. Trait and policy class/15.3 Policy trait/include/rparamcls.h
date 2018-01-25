#ifndef _RPARAMCLS_H_
#define _RPARAMCLS_H_

#include "rparam.h"
#include <iostream>

class MyClass1
{
public:
    MyClass1() {}
    explicit MyClass1(const MyClass1 &) noexcept
    {
        std::cout << "MyClass1 copy constructor called" << std::endl;
    }
};

class MyClass2
{
public:
    MyClass2() {}
    explicit MyClass2(const MyClass2 &) noexcept
    {
        std::cout << "MyClass2 copy constructor called" << std::endl;
    }
};

template <>
class RParam<MyClass2>
{
public:
    typedef MyClass2 Type;
};

#endif // !_RPARAMCLS_H_