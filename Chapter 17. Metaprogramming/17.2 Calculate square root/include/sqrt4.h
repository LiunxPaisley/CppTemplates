#ifndef SQRT4_H_
#define SQRT4_H_

#include "ifThenElse.h"

// 以模板参数作为result的模板
template <int N>
class Value
{
public:
    enum
    {
        result = N
    };
};

// 借助迭代计算sqrt(N)的模板
template <int N, int I = 0>
class Sqrt
{
public:
    // 以实例化下一步Sqrt<N,I+1>或者结果类型Value<I>作为两个分支
    typedef typename ifThenElse<(I * I < N), Sqrt<N, I + 1>, Value<I>>::ResultT SubT;
    // 使用分支类型的结果
    enum
    {
        result = SubT::result
    };
};

#endif // SQRT4_H_
