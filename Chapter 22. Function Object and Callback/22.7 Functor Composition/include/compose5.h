#ifndef COMPOSE5_H_
#define COMPOSE5_H_

#include "../../22.6 Introspection/include/4forwardParam.h"

template <typename C, int N>
class BaseMem : public C
{
public:
    BaseMem(C &c) : C(c) {}
    BaseMem(const C &c) : C(c) {}
};

template <typename FO1, typename FO2>
class Composer : private BaseMem<FO1, 1>, private BaseMem<FO2, 2>
{
public:
    // 使之适合我们的框架
    enum
    {
        NumParams = FO1::NumParams
    };
    typedef typename FO2::ReturnT ReturnT;
    typedef typename FO1::Param1T Param1T;

    Composer(FO1 f1, FO2 f2)
        : BaseMem<FO1, 1>(f1), BaseMem<FO2, 2>(f2)
    {
    }

    double operator()(typename ForwardParamT<Param1T>::Type v)
    {
        return BaseMem<FO1, 1>::operator()(BaseMem<FO2, 2>::operator()(v));
    }
};

#endif // COMPOSE5_H_