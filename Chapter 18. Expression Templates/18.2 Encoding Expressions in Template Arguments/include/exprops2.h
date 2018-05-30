#ifndef EXPROPS2_H_
#define EXPROPS2_H_

// 两个数组相加
template <typename T, typename R1, typename R2>
Array<T, A_Add<T, R1, R2>>
operator+(const Array<T, R1> &a, const Array<T, R2> &b)
{
    return Array<T, A_Add<T, R1, R2>>(A_Add<T, R1, R2>(a.rep(), b.rep()));
}

// 两个数组相乘
template <typename T, typename R1, typename R2>
Array<T, A_Mult<T, R1, R2>>
operator*(const Array<T, R1> &a, const Array<T, R2> &b)
{
    return Array<T, A_Mult<T, R1, R2>>(A_Mult<T, R1, R2>(a.rep(), b.rep()));
}

// scalar和数组相乘
template <typename T, template R2>
Array<T, A_Mult<T, A_Scalar<T>, R2>>
operator*(const T &s, const Array<T, R2> &b)
{
    return Array<T, A_Mult<T, A_Scalar<T>, R2>>(A_Mult<T, A_Scalar<T>, R2>(A_Scalar<T>(s), b.rep()));
}

#endif // EXPROPS2_H_