#ifndef EXPRSCALAR_H_
#define EXPRSCALAR_H_

// 用于表示放大倍数的对象的所属类
template <typename T>
class A_Scalar
{
private:
    const T &s;

public:
    //构造函数， 用于初始化值
    A_Scalar(const T &v)
        : s(v)
    {
    }
    // 对于索引操作而言， 每个元素的值都等于scalar的值
    T operator[](size_t) const
    {
        return s;
    }
    // scalar的大小为0
    size_t size() const
    {
        return 0;
    }
};

#endif // EXPRSCALAR_H_