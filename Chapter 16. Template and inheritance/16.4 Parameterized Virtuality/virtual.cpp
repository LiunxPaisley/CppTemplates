#include <iostream>

class NotVirtual
{
};

class Virtual
{
public:
    virtual void foo() // 声明了foo函数为虚拟的
    {
    }
};

template <typename VBase>
class Base : private VBase
{
public:
    // foo()的虚拟性依赖于它在基类VBase（如果存在基类的话）中的声明
    void foo()
    {
        std::cout << "Base::foo()" << std::endl;
    }
};

template <typename V>
class Derived : public Base<V>
{
public:
    
    void foo()
    {
        std::cout << "Derived::foo()" << std::endl;
    }
};

int main()
{
    Base<NotVirtual> *p1 = new Derived<NotVirtual>;
    p1->foo(); // 调用Base::foo()

    Base<Virtual> *p2 = new Derived<Virtual>;
    p2->foo(); // 调用Derived::foo()
}