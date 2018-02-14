#ifndef BOUND_VAL_H_
#define BOUND_VAL_H_

#include "../../../examples/traits/typeop.hpp"

template <typename T>
class BoundVal
{
private:
    T value;

public:
    typedef T ValueT;
    BoundVal(T v) : value(v)
    {
    }
    typename TypeOp<T>::RefT get()
    {
        return value;
    }
};

template <typename T, T Val>
class StaticBoundVal
{
public:
    typedef T ValueT;
    T get()
    {
        return Val;
    }
};

#endif // BOUND_VAL_H_