#ifndef DUO4_VALUE_H_
#define DUO4_VALUE_H_

#include "../../../examples/tuples/typeop.hpp"
#include "../../21.1 Duo/include/duo.h"

#include "duo3Type.h"

// 基本模板。针对(duo)T的第N个值
template <int N, typename T>
class DuoValue
{
public:
    static void get(T &)
    {
    }

    static void get(const T &)
    {
    }
};

// 针对普通duo的第1个域的特化
template <typename A, typename B>
class DuoValue<1, Duo<A, B>>
{
public:
    static A &get(Duo<A, B> &d)
    {
        return d.v1();
    }
    static const A &get(const Duo<A, B> &d)
    {
        return d.v1();
    }
};

// 针对普通duo的第2个域的特化
template <typename A, typename B>
class DuoValue<2, Duo<A, B>>
{
public:
    static B &get(Duo<A, B> &d)
    {
        return d.v2();
    }
    static const B &get(const Duo<A, B> &d)
    {
        return d.v2();
    }
};

// 针对可递归duo的第N个值的特化
template <int N, typename A, typename B, typename C>
struct DuoValue<N, Duo<A, Duo<B, C>>>
{
    static typename TypeOp<typename DuoType<N - 1, Duo<B, C> >::ResultT>::RefT
    get(Duo<A, Duo<B, C> > &d)
    {
        return DuoValue<N - 1, Duo<B, C> >::get(d.v2());
    }
    static typename TypeOp<typename DuoType<N - 1, Duo<B, C> >::ResultT>::RefConstT
    get(const Duo<A, Duo<B, C> > &d)
    {
        return DuoValue<N - 1, Duo<B, C> >::get(d.v2());
    }
};

// 针对可递归duo的第1个值的特化
template <typename A, typename B, typename C>
struct DuoValue<1, Duo<A, Duo<B, C>>>
{
    static A &get(Duo<A, Duo<B, C> > &d)
    {
        return d.v1();
    }
    static const A &get(const Duo<A, Duo<B, C> > &d)
    {
        return d.v1();
    }
};

// 针对可递归duo的第1个值的特化
template <typename A, typename B, typename C>
struct DuoValue<2, Duo<A, Duo<B, C>>>
{
    static B &get(Duo<A, Duo<B, C>> &d)
    {
        return d.v2().v1();
    }
    static const B &get(const Duo<A, Duo<B, C> > &d)
    {
        return d.v2().v1();
    }
};
#endif // DUO4_VALUE_H_