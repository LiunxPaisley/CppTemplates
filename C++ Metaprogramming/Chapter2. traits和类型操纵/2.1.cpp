//
// Created by liupai on 18-7-2.
//

#include <iostream>
#include <type_traits>

#include "type_name.h"

using namespace std;

template <typename c, typename x, typename y, bool cond>
struct replace_type_or_not;

template <typename c, typename x, typename y>
struct replace_type {
    static const bool b = is_same<c, x>::value;
    typedef typename replace_type_or_not<c, x, y, b>::type type;
};

// void
template <typename c, typename x, typename y>
struct replace_type_or_not<c(), x, y, false> {
    static const bool b = is_same<c, x>::value;
    typedef typename replace_type_or_not<c, x, y, b>::type type();
};

// array
template <typename c, typename x, typename y>
struct replace_type_or_not<c[], x, y, false> {
    static const bool b = is_same<c, x>::value;
    typedef typename replace_type_or_not<c, x, y, b>::type type[];
};

template <typename c, typename x, typename y, int N>
struct replace_type_or_not<c[N], x, y, false> {
    static const bool b = is_same<c, x>::value;
    typedef typename replace_type_or_not<c, x, y, b>::type type[N];
};

// template <typename c, typename x, typename y>
// struct replace_type_or_not<const c[], x, y, false>
//{
//    static const bool b = is_same<c, x>::value;
//    typedef typename const replace_type_or_not<c, x, y, b>::type type[];
//};

// template <typename c, typename x, typename y>
// struct replace_type_or_not<const c*[], x, y, false>
//{
//    static const bool b = is_same<c, x>::value;
//    typedef typename const replace_type_or_not<c, x, y, b>::type* type[];
//};

// pointer
template <typename c, typename x, typename y>
struct replace_type_or_not<c*, x, y, false> {
    static const bool b = is_same<c, x>::value;
    typedef typename replace_type_or_not<c, x, y, b>::type* type;
};
//
// template <typename c, typename x, typename y>
// struct replace_type_or_not<const c*, x, y, false>
//{
//    static const bool b = is_same<c, x>::value;
//    typedef typename const replace_type_or_not<c, x, y, b>::type* type;
//};

// reference
template <typename c, typename x, typename y>
struct replace_type_or_not<c&, x, y, false> {
    static const bool b = is_same<c, x>::value;
    typedef typename replace_type_or_not<c, x, y, b>::type& type;
};

// template <typename c, typename x, typename y>
// struct replace_type_or_not<const c&, x, y, false>
//{
//    static const bool b = is_same<c, x>::value;
//    typedef typename const replace_type_or_not<c, x, y, b>::type& type;
//};

// constant
template <typename c, typename x, typename y>
struct replace_type_or_not<const c, x, y, false> {
    static const bool b = is_same<c, x>::value;
    typedef const typename replace_type_or_not<c, x, y, b>::type type;
};

// function
template <typename c, typename x, typename y, typename arg1>
struct replace_type_or_not<c(arg1), x, y, false> {
    static const bool b1 = is_same<c, x>::value;
    static const bool b2 = is_same<arg1, x>::value;
    typedef typename replace_type_or_not<c, x, y, b1>::type
        type(typename replace_type_or_not<arg1, x, y, b2>::type);
};

template <typename c, typename x, typename y, typename arg1, typename arg2>
struct replace_type_or_not<c(arg1, arg2), x, y, false> {
    static const bool b1 = is_same<c, x>::value;
    static const bool b2 = is_same<arg1, x>::value;
    static const bool b3 = is_same<arg2, x>::value;
    typedef typename replace_type_or_not<c, x, y, b1>::type
        type(typename replace_type_or_not<arg1, x, y, b2>::type,
             typename replace_type_or_not<arg2, x, y, b3>::type);
};

template <typename c, typename x, typename y>
struct replace_type_or_not<c, x, y, true> {
    typedef y type;
};

int main()
{
    typedef replace_type<void*, void, int>::type t1;
    cout << (is_same<t1, int*>::value ? "same" : "false") << "\n";

    typedef replace_type<int const * [10], int const, long>::type t2;
    cout << (is_same<t2, long * [10]>::value ? "same" : "false") << "\n";

    typedef replace_type<int const * [10], int, long>::type t2_2;
    cout << (is_same<t2_2, long const * [10]>::value ? "same" : "false")
         << "\n";

    typedef replace_type<char& (*)(char&), char&, long&>::type t3;
    cout << (is_same<t3, long& (*)(long&)>::value ? "same" : "false") << "\n";

    typedef char& (*Fun1Point[10])(char&);
    typedef int& (*Fun2Point[10])(int&);
    typedef replace_type<Fun1Point, char, int>::type t4;
    cout << (is_same<t4, Fun2Point>::value ? "same" : "false") << "\n";
    TYPE_NAME(t4);
    //    cout << typeid(t4).name() << "\n";
    //    cout << typeid(IntPoint).name() << "\n";
    typedef int* (*Int1Point[10])(int*);
    typedef long* (*Int2Point[10])(long*);
    typedef replace_type<Int1Point, int, long>::type t5;
    cout << (is_same<t5, Int2Point>::value ? "same" : "false") << "\n";
    TYPE_NAME(Int1Point);

    typedef char& Rchar;
    typedef replace_type<Rchar, char, int>::type t6;
    cout << (is_same<t6, int&>::value ? "same" : "false") << "\n";
}