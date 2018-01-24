#ifndef _PROMOTEARRAY_H_
#define _PROMOTEARRAY_H_

#include "promote1.h"
#include "promote2.h"
// #include "promote3.h"
// #include "promote4.h"

template <typename T1, typename T2>
class promotion<Array<T1>, Array<T2>>
{
public:
    typedef Array<typename promotion<T1, T2>::ResultT>::ResultT;
};

template <typename T>
class promotion<Array<T>, Array<T>>
{
public:
    typedef Array<typename promotion<T, T>::ResultT>::ResultT;
};


#endif //!_PROMOTEARRAY_H_