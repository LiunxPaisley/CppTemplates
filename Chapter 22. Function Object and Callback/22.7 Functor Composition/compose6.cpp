#include <iostream>

#include "../22.6 Introspection/include/6funcPtr.h"
#include "./include/compose6.h"
#include "./include/composeConv.h"

double add(double a, double b)
{
    return a + b;
}

double twice(double a)
{
    return 2 * a;
}

int main()
{
    std::cout << "compute (20+7)*2: "
              << compose(func_ptr(add), func_ptr(twice))(20, 7)
              << std::endl;
}