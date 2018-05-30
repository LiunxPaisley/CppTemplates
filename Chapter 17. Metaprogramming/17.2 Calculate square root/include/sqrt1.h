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
    // 这种形式会实例化两个Sqrt模板，最终将会产生数量庞大的实例化体，而且有一大半实例化体是不会使用的
    // 编译器会产生大量的warning
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