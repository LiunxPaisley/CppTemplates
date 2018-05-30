#ifndef BIND_FP2_H_
#define BIND_FP2_H_

#include "boundVal.h"
#include "../../22.6 Introspection/include/1functorParam1.h"
#include "../../22.6 Introspection/include/2functorParam2.h"
#include "../../22.6 Introspection/include/3functionPtrType.h"
#include "../../22.6 Introspection/include/4forwardParam.h"
#include "../../22.6 Introspection/include/5functionPtr.h"
#include "../../22.6 Introspection/include/6funcPtr.h"

// 一个便利（辅助）函数，用于绑定一个具有2个参数的函数指针
template <int PNum, typename RT, typename P1, typename P2>
inline Binder<FunctionPtr<RT, P1, P2>,
              PNum,
              BoundVal<typename FunctorParam<FunctionPtr<RT, P1, P2>, PNum>::Type>>
bindfp(RT (*fp)(P1, P2),
       typename ForwardParamT<typename FunctorParam<FunctionPtr<RT, P1, P2>,
                                                    PNum
                                                    >::Type>::Type val)
{
    return Binder<FunctionPtr<RT, P1, P2>,
                  PNum,
                  BoundVal<typename FunctorParam<FunctionPtr<RT, P1, P2>,
                                                 PNum>::Type>>(func_ptr(fp),
                                                               BoundVal<typename FunctorParam<FunctionPtr<RT, P1, P2>, PNum>::Type>(val));
}

#endif // BIND_FP2_H_