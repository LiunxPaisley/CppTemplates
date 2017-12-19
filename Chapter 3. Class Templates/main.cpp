#include <iostream>
#include <string>
#include <cstdlib>

#define USE_STACK1
//#define USE_STACK3

#ifdef USE_STACK1
#include "stack1.hpp"
#else
#ifdef USE_STACK3
#include "stack3.hpp"
#endif
#endif

using std::cout;
using std::endl;
using std::string;

int main()
{

    try
    {
#ifdef USE_STACK1
        Stack<int> intStack;
        Stack<string> stringStack;

        intStack.push(7);
        cout << intStack.top() << endl;

        stringStack.push("hello");
        cout << stringStack.top() << endl;
        stringStack.pop();
        stringStack.pop();
#endif
#ifdef USE_STACK3
        Stack<int> intStack;
        Stack<double, std::deque<double>> dblStack;

        intStack.push(7);
        cout << intStack.top() << endl;

        dblStack.push(42.42);
        cout << dblStack.top() << endl;
        dblStack.pop();
        dblStack.pop();
#endif
    }
    catch (std::exception const &ex)
    {
        std::cerr << "Exception: " << ex.what() << endl;
        return EXIT_FAILURE;
    }
    return 0;
}