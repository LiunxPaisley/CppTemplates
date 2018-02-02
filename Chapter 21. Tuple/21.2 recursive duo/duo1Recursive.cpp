#include <iostream>

#include "../21.1 Duo/include/duo.h"
#include "./include/duo1Recursive.h"
#include "./include/duo3Type.h"
#include "./include/duo4Value.h"
#include "./include/duo5Val.h"



int main()
{
    // 创建和使用一个简单的duo
    Duo<bool, int> d;
    std::cout << d.v1() << std::endl;
    std::cout << val<1>(d) << std::endl;

    // 创建和使用triple
    Duo<bool, Duo<int, float>> t;
    val<1>(t) = true;
    val<2>(t) = 42;
    val<3>(t) = 0.2;

    std::cout << val<1>(t) << std::endl;
    std::cout << val<2>(t) << std::endl;
    std::cout << val<3>(t) << std::endl;
}