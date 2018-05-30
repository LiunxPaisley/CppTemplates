#include <iostream>
#include <string>
#include <cstdlib>

#define USE_STACK4

#ifdef USE_STACK4
#include "stack4.hpp"
#endif

using std::cout;
using std::endl;
using std::string;

int main()
{

    try
    {
#ifdef USE_STACK4
        Stack<int, 20> int20Stack;
        Stack<int, 40> int40Stack;
        Stack<string, 40> stringStack;

        int20Stack.push(7);
        cout << int20Stack.top() << endl;
        int20Stack.pop();

        stringStack.push("hello");
        cout << stringStack.top() << endl;
        stringStack.pop();
        stringStack.pop();
#endif

    }
    catch (std::exception const &ex)
    {
        std::cerr << "Exception: " << ex.what() << endl;
        return EXIT_FAILURE;
    }
    return 0;
}