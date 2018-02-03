#include <iostream>
#include <typeinfo>

void foo()
{
    std::cout << "foo() called" << std::endl;
}

typedef void FooT(); // FooT是一个函数类型，与函数foo()具有相同的类型

int main()
{
    foo(); // 直接调用

    // 输出foo和FooT的类型
    std::cout << "Types of foo: " << typeid(foo).name() << std::endl;
    std::cout << "Types of FooT: " << typeid(FooT).name() << std::endl;

    FooT* pf = foo; // 隐式转型(decay)
    pf(); // 通过指针的间接调用
    (*pf)(); // 等价于pf()

    // 打印出pf的类型
    // 继续保留了typedef的名称
    std::cout << "Types of pf: " << typeid(pf).name() << std::endl;

    FooT& rf = foo; // 没有隐式转型
    rf(); // 通过引用的间接调用

    // 输出rf的类型
    std::cout << "Types of rf: " << typeid(rf).name() << std::endl;
}
