#include <iostream>

class Empty
{
    typedef int Int;
};

class EmptyToo : public Empty
{
};

/**
 * 这里有明显的编译错误
 */
class NonEmpty : public Empty, public EmptyToo
{
};

int main()
{
    std::cout << "sizeof(Empty): " << sizeof(Empty) << std::endl;
    std::cout << "sizeof(EmptyToo): " << sizeof(EmptyToo) << std::endl;
    std::cout << "sizeof(NonEmplty): " << sizeof(NonEmpty) << std::endl;
}