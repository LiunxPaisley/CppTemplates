#ifndef SQRT_H_
#define SQRT_H_

// 用于计算Sqrt(N)的基本模板
template <int N, int LO = 0, int HI = N>
class Sqrt
{
public:
    // 计算中点
    enum
    {
        mid = (LO + HI + 1) / 2
    };
    
    // 借助二分查找找一个较小的result
    enum
    {
        result = (N < mid * mid) ? Sqrt<N, LO, mid - 1>::result : Sqrt<N, mid, HI>::result
    };
};

// 局部特化，适用于LO等于HI
template <int N, int M>
class Sqrt<N, M, M>
{
public:
    enum
    {
        result = M
    };
};

#endif // SQRT_H_