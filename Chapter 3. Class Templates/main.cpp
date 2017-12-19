#include <iostream>
#include <string>
#include <cstdlib>

#include "stack1.hpp"

using std::cout;
using std::endl;
using std::string;

int main()
{
    try
    {
        Stack1<int> intStack;
        Stack1<string> stringStack;

        intStack.push(7);
        cout << intStack.top() << endl;
        
        stringStack.push("hello");
        cout << stringStack.top() << endl;
        stringStack.pop();
        stringStack.pop();
    }
    catch(std::exception const& ex)
    {
        std::cerr << "Exception: " << ex.what() << endl;
        return EXIT_FAILURE;
    }
    return 0;
}