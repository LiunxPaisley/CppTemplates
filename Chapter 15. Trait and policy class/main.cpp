#include <iostream>
#include <string>
#include <vector>

#define USE_POLICY

#ifndef USE_POLICY
#include "accum5.h"
#else
#include "accum6.h"
#endif

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
#ifndef USE_POLICY
    vector<int> v{1, 2, 3, 4, 5};
    cout << "the average value of the integer values is "
         << accum(&v[0], &v[5]) / 5
         << endl;

    char name[] = "templates";
    int length = sizeof(name) - 1;

    cout << "the average value of the characters in \"" << name << "\" is "
         << accum(&name[0], &name[length]) / length
         << endl;
#else
    vector<int> v1{6, 7, 8, 9, 10};
    cout << "SumPolicy: the average value of the integer values is "
         << Accum<int, SumPolicy>::accum(&v1[0], &v1[5])
         << endl;
#endif
}