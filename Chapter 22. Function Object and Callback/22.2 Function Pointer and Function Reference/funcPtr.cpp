#include <cxxabi.h>
#include <iostream>
#include <typeinfo>
/**
 * #的作用：#objectname被替换成"objectname"(加了双引号)
 */
#define TYPE_OF(objectname) \
{   \
    int status = 0; \
    char* realname = abi::__cxa_demangle(typeid(objectname).name(), 0, 0, &status); \
    std::cout << "Types of "#objectname": " << realname << std::endl; \
    delete realname; \
}

void foo()
{
    std::cout << "foo() called" << std::endl;
}

typedef void FooT(); // FooT是一个函数类型，与函数foo()具有相同的类型

int main()
{
    foo(); // 直接调用

    // 输出foo和FooT的类型
    TYPE_OF(foo);
    TYPE_OF(FooT);

    FooT *pf = foo; // 隐式转型(decay)
    pf();           // 通过指针的间接调用
    (*pf)();        // 等价于pf()

    // 打印出pf的类型
    // 继续保留了typedef的名称
    TYPE_OF(pf);
    

    FooT &rf = foo; // 没有隐式转型
    rf();           // 通过引用的间接调用

    // 输出rf的类型
    TYPE_OF(rf);
}
