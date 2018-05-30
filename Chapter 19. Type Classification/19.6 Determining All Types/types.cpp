#include <iostream>

#include "./include/typet.h"

class MyClass
{};

void myfunc()
{}

enum E{e1};

template <typename T>
void check()
{
    if(TypeT<T>::isFundaType)
    {
        std::cout << " isFundaT ";
    }
    if(TypeT<T>::isPointerType)
    {
        std::cout << " isPointerType";
    }
    if(TypeT<T>::isReferenceType)
    {
        std::cout << " isReferenceType ";
    }
    if(TypeT<T>::isArrayType)
    {
        std::cout << " isArrayType ";
    }
    if(TypeT<T>::isFunctionType)
    {
        std::cout << " isFunctionType ";
    }
    if(TypeT<T>::isPointerMemberType)
    {
        std::cout << " isPointerMemberType ";
    }
    if(TypeT<T>::isEnumType)
    {
        std::cout << " isEnumType ";
    }
    if(TypeT<T>::isClassType)
    {
        std::cout << " isClassType ";
    }
    std::cout << std::endl;
}

template <typename T>
void checkT(T)
{
    check<T>();

    // 对于指针类型，检查它们所引用的类型
    if(TypeT<T>::isPointerType || TypeT<T>::isPointerMemberType)
    {
        check<typename isCompoundType<T>::BaseType>();
    }
}

int main()
{
    std::cout << "int:" << std::endl;
    check<int>();

    std::cout << "int&:" << std::endl;
    check<int&>();

    std::cout << "char[42]:" << std::endl;
    check<char[42]>();

    std::cout << "MyClass" << std::endl;
    check<MyClass>();

    std::cout << "ptr to member" << std::endl;
    E* ptr = 0;
    checkT(ptr);

    std::cout << "42:" << std::endl;
    checkT(42);

    std::cout << "myfunc():" << std::endl;
    checkT(myfunc);

    std::cout << "member pointer to array" << std::endl;
    char (MyClass::* memptr)[] = 0;
    checkT(memptr);
}