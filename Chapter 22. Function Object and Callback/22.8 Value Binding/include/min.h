#ifndef MIN_H_
#define MIN_H_

template <typename T>
class Min
{
public:
    typedef T ReturnT;
    typedef T Param1T;
    typedef T Param2T;
    enum
    {
        NumParams = 2
    };
    ReturnT operator()(Param1T a, Param2T b)
    {
        return a < b ? a : b;
    }
};

#endif // MIN_H_