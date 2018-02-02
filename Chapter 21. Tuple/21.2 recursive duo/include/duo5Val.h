#ifndef DUO5_VAL_H_
#define DUO5_VAL_H_

#include "../../21.1 Duo/include/duo.h"
#include "../../../examples/tuples/typeop.hpp"
#include "duo3Type.h"
#include "duo4Value.h"

// 返回变量duo的第N个值
template <int N, typename A, typename B>
inline typename TypeOp<typename DuoType<N, Duo<A, B> >::ResultT>::RefT
val(Duo<A, B> &d)
{
    return DuoValue<N, Duo<A, B>>::get(d);
}

// 返回常量duo的第N个值
template <int N, typename A, typename B>
inline typename TypeOp<typename DuoType<N, Duo<A, B> >::ResultT>::RefConstT
val(const Duo<A, B> &d)
{
    return DuoValue<N, Duo<A, B>>::get(d);
}

#endif // DUO5_VAL_H_