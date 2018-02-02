#ifndef DUO_RECURSIVE_H_
#define DUO_RECURSIVE_H_

template <typename A, typename B, typename C>
class Duo<A, Duo<B, C>>
{
public:
    typedef A T1;
    typedef Duo<B, C> T2;
    enum
    {
        N = Duo<B, C>::N + 1
    };

private:
    T1 value1; // 第1个域的值
    T2 value2; // 第2个域的值
public:
    // 构造函数
    Duo()
        : value1(), value2()
    {
    }

    Duo(const T1 &a, const T2 &b)
        : value1(a), value2(b)
    {
    }

    // 用于在构造期间，进行隐式类型转换
    template <typename U1, typename U2>
    Duo(const Duo<U1, U2> &d)
        : value1(d.v1()), value2(d.v2())
    {
    }

    // 用于在赋值期间，进行隐式类型转换
    template <typename U1, typename U2>
    Duo<T1, T2> &operator=(const Duo<U1, U2> &d)
    {
        value1 = d.v1();
        value2 = d.v2();
        return *this;
    }

    // 用于访问域的函数（域访问函数）
    T1 &v1()
    {
        return value1;
    }

    const T1 &v1() const
    {
        return value1;
    }

    T2 &v2()
    {
        return value2;
    }

    const T2 &v2() const
    {
        return value2;
    }
};

//  针对只含有一个域的Duo<>局部特化
template <typename A>
struct Duo<A, void>
{
public:
    typedef A T1;    // 第1个域的值
    typedef void T2; // 第2个域的值
    enum
    {
        N = 1
    }; // 域的个数
private:
    T1 value1; // 第2个域的值
public:
    // 构造函数
    Duo()
        : value1()
    {
    }

    Duo(const T1 &a)
        : value1(a)
    {
    }

    // 域访问函数
    T1 &v1()
    {
        return value1;
    }

    const T1 &v1() const
    {
        return value1;
    }

    void v2()
    {
    }

    void v2() const
    {
    }
};

#endif // DUO_RECURSIVE_H_