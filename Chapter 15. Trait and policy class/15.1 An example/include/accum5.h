#ifndef _ACCUM5_H_
#define _ACCUM5_H_

#include "accumtraits4.h"

template <typename T,
          typename AT = AccumulationTraits<T>>
class Accum
{
public:
    static typename AT::AccT accum(const T *beg, const T *end)
    {
        typename AT::AccT total = AT::zero();
        while(beg != end)
        {
            total += *beg;
            ++beg;
        }
        return total;
    }
};

template <typename T>
inline typename AccumulationTraits<T>::AccT accum(const T* beg, const T* end)
{
    return Accum<T>::accum(beg, end);
}

template <typename Traits, typename T>
inline typename Traits::AccT accum (const T* beg, const T* end)
{
    return Accum<T, Traits>::accum(beg, end);
}

#endif // !_ACCUM5_H_