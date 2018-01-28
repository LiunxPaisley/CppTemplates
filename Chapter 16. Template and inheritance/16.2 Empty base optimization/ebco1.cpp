#include <iostream>

class Empty
{
    typedef int Int; // typedef成员并没有使一个类变成非空
};

class EmptyToo : public Empty
{
};

class EmptyThree : public EmptyToo
{
};

int main()
{
    /**
     * 值均为1，也就是说子类中并没有为空父类分配空间
     */ 
    std::cout << "sizeof(Empty): " << sizeof(Empty) << std::endl;
    std::cout << "sizeof(EmptyToo): " << sizeof(EmptyToo) << std::endl;
    std::cout << "sizeof(EmpltyThree): " << sizeof(EmptyThree) << std::endl;
}