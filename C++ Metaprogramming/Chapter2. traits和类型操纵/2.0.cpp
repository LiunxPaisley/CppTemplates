#include <iostream>
#include <type_traits>

using namespace std;

template <typename T>
struct add_const_ref {
    typedef const T& type;
};

template <typename T>
struct add_const_ref<T&> {
    typedef T& type;
};

int main()
{
    cout << is_same<add_const_ref<int&>::type, int&>::value << "\n";
    cout << is_same<add_const_ref<int>::type, int&>::value << "\n";
    cout << is_same<add_const_ref<int>::type, const int&>::value << "\n";
}