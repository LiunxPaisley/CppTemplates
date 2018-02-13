#include <iostream>

#include "./include/compose5.h"
#include "./include/composeConv.h"
#include "./include/math3.h"

template <typename FO>
void print_values(FO fo)
{
    for(int i = -2; i < 3; ++i)
    {
        std::cout << "f(" << i * 0.1 << ") = " << fo(i * 0.1) << std::endl;
    }
}

int main()
{
    // 输出sin(abs(0.5))
    std::cout << compose(Abs<double>(), Sine<double>())(0.5) << "\n"
              << std::endl;

    // 输出某些值的abs()
    print_values(Abs<double>());
    std::cout << std::endl;

    // 输出某些值的sin()
    print_values(Sine<double>());
    std::cout << std::endl;

    // 输出某些值的sin(abs())
    print_values(compose(Abs<double>(), Sine<double>()));
    std::cout << std::endl;

    // 输出某些值的abs(sin())
    print_values(compose(Sine<double>(), Abs<double>()));
    std::cout << std::endl;
}