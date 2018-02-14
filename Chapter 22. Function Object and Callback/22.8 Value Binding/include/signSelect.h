#ifndef SIGN_HEADER_H_
#define SIGN_HEADER_H_

#include "../../../Chapter 15. Trait and policy class/15.2 Type function/include/ifThenElse.h"

template <int S, typename NegT, typename ZeroT, typename PosT>
struct SignSelectT
{
    typedef typename ifThenElse<(S < 0), NegT,
                                typename ifThenElse<(S > 0), PosT, ZeroT>::ResultT>::ResultT
        ResultT;
};

#endif // SIGN_HEADER_H_