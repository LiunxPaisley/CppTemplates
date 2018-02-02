#ifndef DUO_VALUE_H_
#define DUO_VALUE_H_

#include "duoType.h"

template<int N, typename A, typename B>
inline typename TypeOp<typename DuoType<N, Duo<A,B>>::ResultT>::RefT

#endif // DUO_VALUE_H_