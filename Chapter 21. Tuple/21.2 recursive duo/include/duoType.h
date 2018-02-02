#ifndef Duo_H_
#define Duo_H_

#include "../../21.1 Duo/include/duo.h"

template <int N, typename T>
class DuoType
{
public:
    typedef void ResultT;
};

// 针对普通duo第1个域的特化
template <typename A, typename B>
class DuoType<1, Duo<A, B>>
{
public:
    typedef A ResultT;
};

// 针对普通duo第2个域的特化
template <typename A, typename B>
class DuoType<2, Duo<A, B>>
{
public:
    typedef B ResultT;
};

// 针对可递归Duo第N个域的类型的特化
template <int N, typename A, typename B, typename C>
class DuoType<N, Duo<A, Duo<B, C>>>
{
public:
    typedef typename DuoType<N - 1, Duo<B, C>>::ResultT ResultT;
};

// 针对可递归Duo第1个域的类型的特化
template <typename A, typename B, typename C>
class DuoType<1, Duo<A, Duo<B, C>>>
{
public:
    typedef A ResultT;
};

// 针对可递归Duo第1个域的类型的特化
template <typename A, typename B, typename C>
class DuoType<2, Duo<A, Duo<B, C>>>
{
public:
    typedef B ResultT;
};


#endif // Duo_H_