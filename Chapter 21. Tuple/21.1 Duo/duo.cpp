#include "./include/duo.h"
#include <iostream>

Duo<float, int> foo()
{
    // 到返回类型有一次隐式转换
    return make_duo(42, 42);
}

int main()
{
    // 比较时也有一次隐式转换
    if(foo() == make_duo(42, 42.0))
    {
        std::cout << "implicit transfer succeeded" << std::endl;
    }
    else
    {
        std::cout << "implicit transfer failed" << std::endl;
    }
}