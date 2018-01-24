#include <iostream>

#include "./include/isClassType.h"

class MyClass
{
};

struct MyStruct
{
};

union MyUnion{};

void myFunc()
{

}

enum E{e1} e;

// 以模板实参的方式传递类型，并对该类型进行检查
template <typename T>
void check()
{
    if(isClassType<T>::Yes)
    {
        std::cout << "\tis Class Type " << std::endl;
    }
    else
    {
        std::cout << "\tis not Class Type " << std::endl;
    }
}

// 以函数调用的方式传递类型，并对该类型进行检查
template<typename T>
void checkType(T)
{
    check<T>();
}

int main()
{
    std::cout << "int: ";
    check<int>();

    std::cout<<"MyClass: ";
    check<MyClass>();

    std::cout << "MyStruct: ";
    MyStruct s;
    checkType(s);

    std::cout << "MyUnion: ";
    check<MyUnion>();

    std::cout << "enum: ";
    checkType(e);

    std::cout << "myfunc(): ";
    checkType(myFunc);
}

