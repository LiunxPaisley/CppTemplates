#ifndef EXPROPS1_H_
#define EXPROPS1_H_

#include <cassert>
#include <cstddef>

/**
 * 包含一个辅助class trait template , 从而可以根据不同情况，
 * 判断究竟是以“传值”的方式还是以“传引用”方式来引用对应的“表达式模板节点”
 */
#include "exprops1a.h"

/**
 * 表示两个操作数之和的对象的所属类
*/
template <typename T, typename OP1, typename OP2>
class A_Add
{
private:
    typename A_Traits<OP1>::ExprRef op1;
    typename A_Traits<OP2>::ExprRef op2;

public:
    // 构造函数，用于初始化指向对象操作数的引用
    A_Add(const OP1 &a, const OP2 &b)
        : op1(a), op2(b)
    {
    }
    // 在求值的时候计算和
    T operator[](size_t idx) const
    {
        return op1[idx] + op2[idx];
    }
    // size表示最大的容量
    size_t size() const
    {
        assert(op1.size() == 0 || op2.size() == 0 || op1.size() == op2.size());
        return op1.size() != 0 ? op1.size() : op2.size();
    }
}; // A_Add

/**
 * 表示两个对象之积的对象所属类
*/
template <typename T, typename OP1, typename OP2>
class A_Mult
{
private:
    typename A_Traits<OP1>::ExprRef op1;
    typename A_Traits<OP2>::ExprRef op2;

public:
    // 构造函数，用于初始化指向对象操作数的引用
    A_Mult(const OP1 &a, const OP2 &b)
        : op1(a), op2(b)
    {
    }
    // 在求值的时候计算乘积
    T operator[](size_t idx)
    {
        return op1[idx] * op2[idx];
    }

    // size表示最大的容量
    size_t size() const
    {
        assert(op1.size() == 0 || op2.size() == 0 || op1.size() == op1.size());
        return op1.size() != 0 ? op1.size() : op2.size();
    }
}; // A_Mult

#endif // EXPROPS1_H_