#include <iostream>

#include "./include/sqrt1.h"

using std::cout;
using std::endl;

int main()
{
    cout << "Sqrt<16>::result = " << Sqrt<16>::result << endl;
    cout << "Sqrt<25>::result = " << Sqrt<25>::result << endl;
    cout << "Sqrt<42>::result = " << Sqrt<42>::result << endl;
	cout << "Sqrt<1>::result = " << Sqrt<1>::result << endl;
}