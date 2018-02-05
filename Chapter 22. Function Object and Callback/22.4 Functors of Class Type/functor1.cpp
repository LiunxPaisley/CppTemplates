#include <iostream>

// 含有返回值常量的函数对象的类
class ConstantIntFunctor
{
private:
    int value; // 函数调用所返回的值
public:
    // 构造函数：初始化返回值
    ConstantIntFunctor(int c)
        : value(c)
    {
    }

    // 函数调用
    int operator()() const
    {
        return value;
    }
};

// 使用上面的函数对象的客户端函数
void client (const ConstantIntFunctor& cif)
{
    std::cout << "calling back functor yields " << cif() << std::endl;
}

int main()
{
    ConstantIntFunctor seven(7);
    ConstantIntFunctor fortytwo(42);
    client(seven);
    client(fortytwo);
}