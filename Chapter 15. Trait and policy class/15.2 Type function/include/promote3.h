#ifndef _PROMOTE3_H_
#define _PROMOTE3_H_

#include "promote1.h"
#include "promote2.h"

#define MK_PROMOTION(T1, T2, Tr)   \
template<> class promotion<T1, T2> \
{                                  \
public:                            \
    typedef Tr ResultT;            \
};                                 \
                                   \
template<> class promotion<T2, T1> \
{                                  \
public:                            \
    typedef Tr ResultT;            \
};

#endif