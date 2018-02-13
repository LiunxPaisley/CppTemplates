#ifndef MATH3_H_
#define MATH3_H_

#include <cmath>
#include <cstdlib>

template <typename T>
class Abs
{
public:
    enum
    {
        NumParams = 1
    };
    typedef T ReturnT;
    typedef T Param1T;
    // 函数调用：
    T operator()(T v) const
    {
        return std::abs(v);
    }
};

template <typename T>
class Sine
{
public:
    enum
    {
        NumParams = 1
    };
    typedef T ReturnT;
    typedef T Param1T;
    // 函数调用：
    T operator()(T a) const
    {
        return std::sin(a);
    }
};

#endif // MATH3_H_