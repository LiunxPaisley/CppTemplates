#include <iostream>
#include <string>
#include <vector>

#include "accum5.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<int> v{1, 2, 3, 4, 5};
    cout << "the average value of the integer values is "
         << accum(&v[0], &v[5]) / 5
         << endl;

    char name[] = "templates";
    int length = sizeof(name) - 1;

    cout << "the average value of the characters in \"" << name << "\" is "
         << accum(&name[0], &name[length]) / length
         << endl;
}