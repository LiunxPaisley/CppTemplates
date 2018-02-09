#ifndef FORWARD_PARAM_H_
#define FORWARD_PARAM_H_

#include "../../../Chapter 15. Trait and policy class/15.2 Type function/include/ifThenElse.h"
#include "../../../examples/tuples/typeop.hpp"
#include "../../../examples/types/typet.hpp"

// 对于class类型，ForwardParamType<T>::Type是一个常量引用
// 对于其他所有类型，ForwardParamType<T>::Type是普通类型
// 对于void类型，ForwardParamType<T>::Type是哑类型（Unused）
template <typename T>
class ForwardParamType
{
public:
    typedef typename ifThenElse<TypeT<T>::IsClassT,
                                typename TypeOp<T>::RefConstT,
                                typename TypeOp<T>::ArgT>::ResultT
        Type;
};

template <>
class ForwardParamType<void>
{
private:
    class Unused
    {
    };

public:
    typedef Unused Type;
};

#endif // FORWARD_PARAM_H_