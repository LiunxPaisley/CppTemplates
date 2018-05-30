#ifndef SQRT3_H_
#define SQRT3_H_

template <int N, int I = 0>
class Sqrt
{
public:
    enum
    {
        result = (I * I < N) ? Sqrt<N, I + 1>::result : I
    };
};

template <int N>
class Sqrt<N, N>
{
public:
    enum
    {
        result = N
    };
};

#endif // SQRT3_H_