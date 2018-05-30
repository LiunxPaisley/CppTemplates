#ifndef CLAMP_H_
#define CLAMP_H_

template <typename T, T max_result>
class Clamp : private Min<T>
{
public:
    typedef T ReturnT;
    typedef T Param1T;
    enum
    {
        NumParams = 1
    };
    ReturnT operator()(Param1T a)
    {
        return Min<T>::operator()(a, max_result);
    }
};

#endif // CLAMP_H_