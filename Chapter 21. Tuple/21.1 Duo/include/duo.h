#ifndef Duo_H_
#define Duo_H_

template <typename T1, typename T2>
class Duo
{
public:
    typedef T1 Type1; // 第1个域的类型
    typedef T2 Type2; // 第2个域的类型
    enum
    {
        N = 2
    }; // 域的类型
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

// 比较运算符（允许混合类型）
template <typename T1, typename T2,
          typename U1, typename U2>
inline bool operator==(const Duo<T1, T2> &d1, const Duo<U1, U2> &d2)
{
    return (d1.v1() == d2.v2()) && (d1.v2() == d2.v2());
}

template <typename T1, typename T2,
          typename U1, typename U2>
inline bool operator!=(const Duo<T1, T2> &d1, const Duo<U1, U2> &d2)
{
    return !(d1==d2);
}

// 针对创建和初始化的辅助函数
template <typename T1, typename T2>
inline Duo<T1, T2> make_duo(const T1 &a, const T2 &b)
{
    return Duo<T1, T2>(a, b);
}

#endif // Duo_H_