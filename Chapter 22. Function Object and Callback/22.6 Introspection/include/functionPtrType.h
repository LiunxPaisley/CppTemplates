#ifndef FUNCTION_PTR_TYPE_H_
#define FUNCTION_PTR_TYPE_H_

// 基本模板，用于处理参数个数最大的情况
template <typename RT, typename P1 = void,
          typename P2 = void,
          typename P3 = void>
class FunctionPtrType
{
public:
    enum
    {
        NumParams = 3
    };
    typedef RT (*Type)(P1, P2, P3);
};

// 用于处理两个参数的局部特化
template <typename RT, typename P1,
          typename P2>
class FunctionPtrType<RT, P1, P2, void>
{
public:
    enum
    {
        NumParams = 2
    };
    typedef RT (*Type)(P1, P2);
};

// 用于处理一个参数的局部特化
template <typename RT, typename P1>
class FunctionPtrType<RT, P1, void, void>
{
    enum
    {
        NumParams = 1
    };
    typedef RT (*Type)(P1);
};

// 用于处理一个参数的局部特化
template <typename RT>
class FunctionPtrType<RT, void, void, void>
{
    enum
    {
        NumParams = 0
    };
    typedef RT (*Type)();
};

#endif // FUNCTION_PTR_TYPE_H_