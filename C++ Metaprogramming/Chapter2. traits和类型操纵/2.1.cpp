//
// Created by liupai on 18-7-2.
//

#include <iostream>
#include <type_traits>

using namespace std;

template <typename c, typename x, typename y, bool cond>
struct replace_type_or_not;

template <typename c, typename x, typename y>
struct replace_type
{
    bool b = is_same<c, x>::value;
    typedef replace_type_or_not<c, x, y, b>::type type;
};

// void
template <typename c, typename x, typename y>
struct replace_type_or_not<c(), x, y, false>
{
    bool b = is_same<c, x>::value;
    typedef replace_type_or_not<c, x, y, b>::type type;
};

// array
template <typename c, typename x, typename y>
struct replace_type_or_not<c[], x, y, false>
{
    bool b = is_same<c, x>::value;
    typedef replace_type_or_not<c, x, y, b>::type type;
};

// pointer
template <typename c, typename x, typename y>
struct replace_type_or_not<c*, x, y, false>
{
    bool b = is_same<c, x>::value;
    typedef replace_type_or_not<c, x, y, b>::type type;
};

// reference
template <typename c, typename x, typename y>
struct replace_type_or_not<c&, x, y, false>
{
    bool b = is_same<c, x>::value;
    typedef replace_type_or_not<c, x, y, b>::type type;
};

// constant
template <typename c, typename x, typename y>
struct replace_type_or_not<const c, x, y, false>
{
    bool b = is_same<c, x>::value;
    typedef replace_type_or_not<c, x, y, b>::type type;
};