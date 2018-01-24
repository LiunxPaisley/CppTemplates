#ifndef _ACCUM8_H_
#define _ACCUM8_H_

#include "accumtraits4.h"
#include "sumpolicy2.h"

/**
 * policy采用模板的模板参数
 */ 

template <typename T,
          template<typename, typename> class Policy = SumPolicy,
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
            Policy<AccT, T>::accumulate(total, *beg);
            ++beg;
        }
        return total;
    }
};

#endif // !_ACCUM8_H_