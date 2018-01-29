#ifndef SQRT2_H_
#define SQRT2_H_

#include "ifThenElse.h"

template <int N, int LO = 0, int HI = N>
class Sqrt
{
public:
    // 计算中点值
    enum
    {
        mid = (LO + HI + 1) / 2
    };
    // 使用二分法查找一个较小的值
    // 使用ifThenElse模板减少需要特化的模板
    // 在ifThenElse模板中只会特化被选择的模板
    typedef typename ifThenElse<(N < mid * mid), Sqrt<N, LO, mid - 1>, Sqrt<N, mid, HI>>::ResultT SubT;
    enum
    {
        result = SubT::result
    };
};

// 用于结束递归的局部特化
template <int N, int S>
class Sqrt<N, S, S>
{
public:
    enum
    {
        result = S
    };
};
#endif