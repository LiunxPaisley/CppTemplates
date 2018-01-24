#ifndef _ACCUM6_H_
#define _ACCUM6_H_

#include "accumtraits4.h"
#include "sumpolicy1.h"

template <typename T,
          typename Policy = SumPolicy,
          typename Traits = AccumulationTraits<T>>
class Accum
{
public:
    typedef typename Traits::AccT AccT;
    static AccT accum(const T* beg, const T* end)
    {
        AccT total = Traits::zero();
        while(beg != end)
        {
            Policy::accumulate(total, *beg);
            ++beg;
        }
        return total;
    }
};

#endif // !_ACCUM6_H_