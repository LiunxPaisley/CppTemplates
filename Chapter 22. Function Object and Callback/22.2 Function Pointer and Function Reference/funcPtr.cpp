#include <cxxabi.h>
#include <iostream>
#include <typeinfo>

void foo()
{
    std::cout << "foo() called" << std::endl;
}

typedef void FooT(); // FooT是一个函数类型，与函数foo()具有相同的类型

int main()
{
    int status = 0;
    char *realname = nullptr;
    foo(); // 直接调用

    // 输出foo和FooT的类型
    realname = abi::__cxa_demangle(typeid(foo).name(), 0, 0, &status);
    std::cout << "Types of foo: "
              << realname
              << std::endl;
    free(realname);

    realname = abi::__cxa_demangle(typeid(FooT).name(), 0, 0, &status);
    std::cout << "Types of FooT: "
              << realname
              << std::endl;
    free(realname);

    FooT *pf = foo; // 隐式转型(decay)
    pf();           // 通过指针的间接调用
    (*pf)();        // 等价于pf()

    // 打印出pf的类型
    // 继续保留了typedef的名称
    realname = abi::__cxa_demangle(typeid(pf).name(), 0, 0, &status);
    std::cout << "Types of pf: "
              << realname
              << std::endl;
    free(realname);

    FooT &rf = foo; // 没有隐式转型
    rf();           // 通过引用的间接调用

    // 输出rf的类型
    realname = abi::__cxa_demangle(typeid(rf).name(), 0, 0, &status);
    std::cout << "Types of rf: "
              << realname
              << std::endl;
    free(realname);
}
