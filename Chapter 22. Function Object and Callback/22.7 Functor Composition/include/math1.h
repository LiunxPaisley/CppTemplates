#ifndef MATH1_H_
#define MATH1_H_

#include <cmath>
#include <cstdlib>

class Abs
{
public:
    // 函数调用：
    double operator()(double v) const
    {
        return std::abs(v);
    }
};

class Sine
{
public:
    // 函数调用：
    double operator()(double a) const
    {
        return std::sin(a);
    }
};

#endif // MATH1_H_
