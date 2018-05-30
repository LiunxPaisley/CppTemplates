template <int p, int i>
class is_prime
{
public:
    enum
    {
        // prim的值为0或者1，用于判断p是否是素数，
        // 这里使用递归判断p是否为素数
        // p等于2或者比p小的数都不能整除p时（递归得到的prim等于1），当前的prim则等于1
        prim = (p == 2) || ((p % i) && (is_prime<(i > 2 ? p : 0), i - 1>::prim))
    };
};

template <>
class is_prime<0, 0>
{
public:
    enum
    {
        prim = 1
    };
};

template <>
class is_prime<0, 1>
{
public:
    enum
    {
        prim = 1
    };
};

template <int i>
class D
{
public:
    D(void *);
};

// 用于循环输出素数的基本模板
template <int i>
class Prime_print
{
public:
    Prime_print<i - 1> a;
    enum
    {
        prim = is_prime<i, i - 1>::prim
    };
    void f()
    {
        D<i> d = prim ? 1 : 0;
        a.f();
    }
};

// 用于结束循环的全局特化
template <>
class Prime_print<1>
{
public:
    enum
    {
        prim = 0
    };
    void f()
    {
        D<1> d = prim ? 1 : 0;
    }
};

#ifndef LAST
#define LAST 18
#endif

int main()
{
    Prime_print<LAST> a;
    a.f();
}
