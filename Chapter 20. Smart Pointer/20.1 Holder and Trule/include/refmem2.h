#ifndef REFMEM2_H_
#define REFMEN2_H_

#include "holder.h"

template <typename MemType>
class refMembers
{
private:
    holder<MemType> ptr1;
    holder<MemType> ptr2;

public:
    // 缺省构造函数
    // 不可能有内存泄漏
    // 如果第二个new抛出异常，第一个new产生的对象仍然可以调用析构函数 
    refMembers()
        : ptr1(new MemType), ptr2(new MemType)
    {
    }

    // 拷贝构造函数
    // 不可能有内存泄漏
    refMembers(const refMembers &x)
        : ptr1(new MemType(*x.ptr1)), ptr2(new MemType(*x.ptr2))
    {
    }

    // 赋值运算符
    const refMembers &operator=(const refMembers &x)
    {
        *ptr1 = *x.ptr1;
        *ptr2 = *x.ptr2;
        return *this;
    }

    // 不需要析构函数
    // 缺省的析构函数将会让ptr1和ptr2删除他们所引用的对象
};

#endif // REFMEM2_H_