#include <iostream>

#define USE_SQRT 4

#if USE_SQRT == 1
#include "./include/sqrt1.h"
#elif USE_SQRT == 2
#include "./include/sqrt2.h"
#elif USE_SQRT == 3
#include "./include/sqrt3.h"
#elif USE_SQRT == 4
#include "./include/sqrt4.h"
#endif


using std::cout;
using std::endl;

int main()
{
    cout << "Sqrt<16>::result = " << Sqrt<16>::result << endl;
    cout << "Sqrt<25>::result = " << Sqrt<25>::result << endl;
    cout << "Sqrt<42>::result = " << Sqrt<42>::result << endl;
	cout << "Sqrt<4096>::result = " << Sqrt<4096>::result << endl;
}