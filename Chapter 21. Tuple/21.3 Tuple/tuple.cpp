#include <iostream>

#include "./include/tuple.h"

int main()
{
    // 创建和使用只具有1个域的tuple
    Tuple<int> t1;
    val<1>(t1) += 42;
    std::cout << "Singletons: "<< t1.v1() << std::endl;

    // 创建和使用duo
    Tuple<bool, int> t2;
    std::cout << "Duo: " << val<1>(t2) << ", " << t2.v1() << std::endl;

    // 创建和使用triple
    Tuple<bool, int, double> t3;

    val<1>(t3) = true;
    val<2>(t3) = 42;
    val<3>(t3) = 0.2;

    std::cout << "Triple: " 
                << val<1>(t3) << ", "
              << val<2>(t3) << ", "
              << val<3>(t3) << std::endl;
    
    t3 = make_tuple(false, 23, 13.13);

    std::cout << "Triple: "
                << val<1>(t3) << ", "
              << val<2>(t3) << ", "
              << val<3>(t3) << std::endl;

    // 创建和使用quadruple
    Tuple<bool,int,float,double> t4(true,42,13,1.95583);
    std::cout << "Quadruple: " << val<4>(t4) << std::endl;
    std::cout << "Quadruple: " << t4.v2().v2().v2() << std::endl;
}