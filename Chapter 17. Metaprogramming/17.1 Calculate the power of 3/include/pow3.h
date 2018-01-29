#ifndef POW3_H_
#define POW3_H_

template <int N>
class Pow3
{
public:
    enum
    {
        result = 3 * Pow3<N - 1>::result
    };
};

template <>
class Pow3<0>
{
public:
    enum
    {
        result = 1
    };
};

#endif // POW3_H_