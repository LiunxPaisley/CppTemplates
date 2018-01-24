#ifndef _SUMPOLICY2_H_
#define _SUMPOLICY2_H_

/**
 * 类模板 
 */
template <typename T1, typename T2>
class SumPolicy
{
    public:
    static void accumulate(T1& total, const T2& value)
    {
        total += value;
    }
};

#endif // !_SUMPOLICY2_H_