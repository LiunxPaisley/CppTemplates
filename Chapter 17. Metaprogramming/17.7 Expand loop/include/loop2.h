#ifndef LOOP2_H_
#define LOOP2_H_

// 基本模板
template <int DIM, typename T>
class DotProduct
{
    public:
    static T result (T* a, T* b)
    {
        return (*a) + (*b) + DotProduct<DIM-1,T>::result(a+1,b+1);
    }
};

// 作为结束条件的局部特化
template <typename T>
class DotProduct<1,T>
{
    public:
    static T result(T* a, T* b)
    {
        return (*a) * (*b);
    }
};

// 辅助函数
template <int DIM, typename T>
inline T dot_product(T* a, T* b)
{
    return DotProduct<DIM, T>::result(a,b);
}

#endif // LOOP2_H_