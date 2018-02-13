#ifndef FUNCTOR_PARAM1_H_
#define FUNCTOR_PARAM1_H_

#include "../../../Chapter 15. Trait and policy class/15.2 Type function/include/ifThenElse.h"

template <typename F, int N>
class UsedFunctorParam;

template <typename F, int N>
class FunctorParam
{
private:
    class Unused
    {
    private:
        class Private
        {
        };

    public:
        typedef Private Type;
    };

public:
    typedef typename ifThenElse<F::NumParams >= N,
                                UsedFunctorParam<F, N>,
                                Unused>::ResultT::Type
        Type;
};

template <typename F>
class UsedFunctorParam<F, 1>
{
public:
    typedef typename F::Param1T Type;
};

#endif // FUNCTOR_PARAM1_H_