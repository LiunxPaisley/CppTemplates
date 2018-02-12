#include "./include/2compose.h"
#include "./include/1math.h"
#include <iostream>

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
    std::cout << Composer<Abs, Sine>(Abs(), Sine())(0.5) << "\n"
              << std::endl;

    // 输出某些值的abs()
    print_values(Abs());
    std::cout << std::endl;

    // 输出某些值的sin()
    print_values(Sine());
    std::cout << std::endl;
    
    // 输出某些值的sin(abs())
    print_values(Composer<Abs, Sine>(Abs(), Sine()));
    std::cout << std::endl;

    // 输出某些值的abs(sin())
    print_values(Composer<Sine, Abs>(Sine(), Abs()));
    std::cout << std::endl;
}