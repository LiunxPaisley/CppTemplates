#ifndef _SUMPOLICY1_H_
#define _SUMPOLICY1_H_

/**
 * 类的函数模板 
 */
class SumPolicy
{
public:
    template <typename T1, typename T2>
    static void accumulate(T1 &total, const T2 &value)
    {
        total += value;
    }
};

#endif // !_SDUMPOLICY1_H_