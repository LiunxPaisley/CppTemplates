#ifndef BINDER_PARAMS_H_
#define BINDER_PARAMS_H_

#include "../../../Chapter 15. Trait and policy class/15.2 Type function/include/ifThenElse.h"
#include "../../22.6 Introspection/include/1functorParam1.h"
#include "../../22.6 Introspection/include/2functorParam2.h"


template <typename F, int P>
class BinderParams
{
public:
    enum
    {
        NumParams = F::NumParams - 1
    };
#define ComposeParamT(N)                                               \
    typedef typename ifThenElse<(N < P), FunctorParam<F, N>,           \
                                FunctorParam<F, N + 1>>::ResultT::Type \
        Param##N##T
    ComposeParamT(1);
    ComposeParamT(2);
    ComposeParamT(3);
// ...
#undef ComposeParamT
};

#endif // BINDER_PARAMS_H_
