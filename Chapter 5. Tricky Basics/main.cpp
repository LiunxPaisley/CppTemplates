#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

#include "Stack8.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;

int main()
{
    try
    {
        Stack<int> intStack;
        Stack<float> floatStack;
        
        intStack.push(42);
        intStack.push(7);

        floatStack = intStack;

        cout << floatStack.top() << endl;
        floatStack.pop();
        cout << floatStack.top() << endl;
        floatStack.pop();
        cout << floatStack.top() << endl;
        floatStack.pop();
    }
    catch(const std::exception & ex)
    {
        cerr << "Exception: " << ex.what() << endl;
    }
    // 使用vector作为内部容器的栈
    Stack<int, vector> vStack;
    vStack.push(42);
    vStack.push(7);
    cout << vStack.top() << endl;
    vStack.pop();
}