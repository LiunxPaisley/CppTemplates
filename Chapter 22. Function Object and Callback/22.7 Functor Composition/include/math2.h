#ifndef MATH2_H_
#define MATH2_H_

#include <cmath>
#include <cstdlib>

class Abs
{
public:
    enum
    {
        NumParams = 1
    };
    typedef double ReturnT;
    typedef double Param1T;
    // 函数调用：
    double operator()(double v) const
    {
        return std::abs(v);
    }
};

class Sine
{
public:
    enum
    {
        NumParams = 1
    };
    typedef double ReturnT;
    typedef double Param1T;
    // 函数调用：
    double operator()(double a) const
    {
        return std::sin(a);
    }
};

#endif // MATH2_H_