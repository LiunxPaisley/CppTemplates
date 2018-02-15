#include <iostream>
#include <string>
#include <typeinfo>

#include "./include/functorOps.h"

bool compare(std::string debugstr, double v1, float v2)
{
    if(debugstr != "")
    {
        std::cout << debugstr << ": " << v1 << (v1 < v2 ? '<' : '>') << v2 << std::endl;
    }
    return v1 < v2;
}

void print_name_value(std::string name, double value)
{
    std::cout << name << ": " << value << std::endl;
}

double sub(double a, double b)
{
    return a - b;
}

double twice(double a)
{
    return 2 * a;
}

int main()
{
    using std::cout;

    // 组合的示例用法
    cout << "Composition result: "
         << compose(func_ptr(sub), func_ptr(twice))(3.0, 7.0)
         << std::endl;

    // 绑定的示例用法
    cout << "Binding result: "
         << bindfp<1>(compare, "main()->compare()")(1.02, 1.03)
         << std::endl;
         
    cout << "Binding output: ";
    bindfp<1>(print_name_value, "the ultimate answer to life")(42);

    // 把组合和绑定结合起来
    cout << "Mixing composition and binding (bind<1>): "
         << bind<1>(compose(func_ptr(sub), func_ptr(twice)), 7.0)(3.0)
         << std::endl;
    cout << "Mixing composition and binding (bind<2>): "
         << bind<2>(compose(func_ptr(sub), func_ptr(twice)), 7.0)(3.0)
         << std::endl;
}