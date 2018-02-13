#ifndef COMPOSE6_H_
#define COMPOSE6_H_

#include "../../22.6 Introspection/include/1functorParam1.h"
#include "../../22.6 Introspection/include/2functorParam2.h"
#include "../../22.6 Introspection/include/4forwardParam.h"

template <typename C, int N>
class BaseMem : public C
{
public:
    BaseMem(C &c) : C(c) {}
    BaseMem(const C &c) : C(c) {}
};

template <typename FO1, typename FO2>
class Composer : private BaseMem<FO1, 1>,
                 private BaseMem<FO2, 2>
{
public:
    enum
    {
        NumParams = FO1::NumParams
    };
    typedef typename FO2::ReturnT ReturnT;


#define ComposeParamT(N) \
    typedef typename FunctorParam<FO1, N>::Type Param##N##T
    ComposeParamT(1);
    ComposeParamT(2);
    //...
#undef ComposeParamT


    Composer(const FO1 &f1, const FO2 &f2)
        : BaseMem<FO1, 1>(f1), BaseMem<FO2, 2>(f2)
    {
    }
    Composer(const FO1 &f1, FO2 &f2)
        : BaseMem<FO1, 1>(f1), BaseMem<FO2, 2>(f2)
    {
    }
    Composer(FO1 &f1, const FO2 &f2)
        : BaseMem<FO1, 1>(f1), BaseMem<FO2, 2>(f2)
    {
    }
    Composer(FO1 &f1, FO2 &f2)
        : BaseMem<FO1, 1>(f1), BaseMem<FO2, 2>(f2)
    {
    }


    ReturnT operator()()
    {
        return BaseMem<FO2, 2>::operator()(BaseMem<FO1, 1>::operator()());
    }


    ReturnT operator()(typename ForwardParamType<Param1T>::Type v1)
    {
        return BaseMem<FO2, 2>::operator()(BaseMem<FO1, 1>::operator()(v1));
    }


    ReturnT operator()(typename ForwardParamType<Param1T>::Type v1,
                       typename ForwardParamType<Param2T>::Type v2)
    {
        return BaseMem<FO2, 2>::operator()(BaseMem<FO1, 1>::operator()(v1, v2));
    }
    // ...
};

#endif // COMPOSE6_H_