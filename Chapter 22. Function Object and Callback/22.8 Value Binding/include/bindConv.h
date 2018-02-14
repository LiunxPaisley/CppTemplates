#ifndef BIND_CONV_H_
#define BIND_CONV_H_

#include "../../22.6 Introspection/include/1functorParam1.h"
#include "../../22.6 Introspection/include/2functorParam2.h"
#include "../../22.6 Introspection/include/4forwardParam.h"

// P: 绑定参数的位置，首个模板参数
// FO: 绑定参数所在的仿函数
template <int P, typename FO>
inline Binder<FO, P, BoundVal<typename FunctorParam<FO, P>::Type> >
bind(const FO &fo, typename FowrwardParamT<typename FunctorParam<FO, P>::Type>::Type val)
{
    return Binder<FO,
                  P,
                  BoundVal<typename FunctorParam<FO, P>::Type> >(fo,
                                                                BoundVal<typename FunctorParam<FO, P>::Type>(val));
}

#endif // BIND_CONV_H_