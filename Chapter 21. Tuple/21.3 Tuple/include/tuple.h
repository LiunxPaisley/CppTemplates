#ifndef TUPLE_H_
#define TUPLE_H_

#include "../../../examples/tuples/typeop.hpp"
#include "../../21.1 Duo/include/duo.h"
#include "../../21.2 recursive duo/include/duo1Recursive.h"
#include "../../21.2 recursive duo/include/duo3Type.h"
#include "../../21.2 recursive duo/include/duo4Value.h"
#include "../../21.2 recursive duo/include/duo5Val.h"

class NullType
{
};

// 一般情况下，Tuple<>都创建自“至少含有一个NullType的另一个Tuple<>”
template <typename P1,
          typename P2 = NullType,
          typename P3 = NullType,
          typename P4 = NullType,
          typename P5 = NullType>
class Tuple : public Duo<P1, typename Tuple<P2, P3, P4, P5, NullType>::BaseType>
{
public:
    typedef Duo<P1, typename Tuple<P2, P3, P4, P5, NullType>::BaseType> BaseType;

    // 构造函数
    Tuple() {}
    Tuple(typename TypeOp<P1>::RefConstT a1,
          typename TypeOp<P2>::RefConstT a2,
          typename TypeOp<P3>::RefConstT a3 = NullType(),
          typename TypeOp<P4>::RefConstT a4 = NullType(),
          typename TypeOp<P5>::RefConstT a5 = NullType())
        : BaseType(a1, Tuple<P2, P3, P4, P5, NullType>(a2, a3, a4, a5))
    {
    }
};

// 用于终止递归的特化
template <typename P1, typename P2>
class Tuple<P1, P2, NullType, NullType, NullType> : public Duo<P1, P2>
{
public:
    typedef Duo<P1, P2> BaseType;
    Tuple() {}
    Tuple(typename TypeOp<P1>::RefConstT a1,
          typename TypeOp<P2>::RefConstT a2,
          typename TypeOp<NullType>::RefConstT a3 = NullType(),
          typename TypeOp<NullType>::RefConstT a4 = NullType(),
          typename TypeOp<NullType>::RefConstT a5 = NullType())
        : BaseType(a1, a2)
    {
    }
};

// 针对singletons(只具有一个域)的特化
template <typename P1>
class Tuple<P1, NullType, NullType, NullType, NullType> : public Duo<P1, void>
{
public:
    typedef Duo<P1, void> BaseType;
    Tuple() {}
    Tuple(typename TypeOp<P1>::RefConstT a1,
          typename TypeOp<NullType>::RefConstT a2,
          typename TypeOp<NullType>::RefConstT a3 = NullType(),
          typename TypeOp<NullType>::RefConstT a4 = NullType(),
          typename TypeOp<NullType>::RefConstT a5 = NullType())
        : BaseType(a1)
    {
    }
};

// 针对一个实参的辅助函数
template <typename T1>
inline Tuple<T1> make_tuple(const T1 &a1)
{
    return Tuple<T1>(a1);
}

// 针对两个实参的辅助函数
template <typename T1, typename T2>
inline Tuple<T1, T2> make_tuple(const T1 &a1, const T2 &a2)
{
    return Tuple<T1, T2>(a1, a2);
}

// 针对3个实参的辅助函数
template <typename T1, typename T2, typename T3>
inline Tuple<T1, T2, T3> make_tuple(const T1 &a1, const T2 &a2, const T3 &a3)
{
    return Tuple<T1, T2, T3>(a1, a2, a3);
}

// 针对4个实参的辅助函数
template <typename T1, typename T2, typename T3, typename T4>
inline Tuple<T1, T2, T3, T4> make_tuple(const T1 &a1, const T2 &a2, const T3 &a3, const T4 &a4)
{
    return Tuple<T1, T2, T3, T4>(a1, a2, a3, a4);
}

// 针对5个实参的辅助函数
template <typename T1, typename T2, typename T3, typename T4, typename T5>
inline Tuple<T1, T2, T3, T4> make_tuple(const T1 &a1, const T2 &a2, const T3 &a3, const T4 &a4, const T5 &a5)
{
    return Tuple<T1, T2, T3, T4, T5>(a1, a2, a3, a4, a5);
}

#endif // TUPLE_H_