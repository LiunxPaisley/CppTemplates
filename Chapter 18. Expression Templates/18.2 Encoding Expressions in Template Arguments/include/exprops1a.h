#ifndef EXPROPS1A_H_
#define EXPROPS1A_H_

template <typename T>
class A_Scalar;

// 基本模板
template <typename T>
class A_Traits
{
public:
    // 所引用的类型typedef成一个常量引用
    typedef const T &ExprRef; 
};

// 针对Scalar的局部特化
template <typename T>
class A_Traits<A_Scalar<T> >
{
public:
    // 所引用的类型实际是一个普通值
    typedef A_Scalar<T> ExprRef;
} ；

#endif // EXPROPS1A_H_