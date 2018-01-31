#ifndef HOLDER2_H_
#define HOLDER2_H_

#include "trule.h"

template<typename T>
class holder
{
    private:
    T *ptr; // 引用它所持用的对象
public:
    // 缺省构造函数：让该holder引用该指针指向的对象
    holder()
        : ptr(nullptr)
    {
    }

    explicit holder(T *p)
        : ptr(p)
    {
    }

    // 析构函数：释放所引用的对象
    ~holder()
    {
        delete ptr;
    }

    // 针对新指针的赋值运算符
    holder<T> &operator=(T *p)
    {
        delete ptr;
        ptr = p;
        return *this;
    }

    holder(const trule<T>& t)
    {
        ptr=t.ptr;
        const_cast<trule<T>&>(t).ptr = nullptr;
    }

    holder<T>& operator=(const trule<T>& t)
    {
        delete ptr;
        ptr = t.ptr;
        const_cast<trule<T>&>(t).ptr = nullptr;
        return *this;
    }

    // 指针运算符
    T &operator*() const
    {
        return *ptr;
    }

    T *operator->() const
    {
        return ptr;
    }

    // 获取所引用的对象
    T *get() const
    {
        return ptr;
    }

    // 释放对所引用对象的所有权
    T* release()
    {
        T* ret = ptr;
        ptr = nullptr;
        return ret;
    }

    // 与另一个holder交换所有权
    void exchange_with(holder<T> &h)
    {
        swap(ptr, h.ptr);
    }

    // 与其他指针交换所有权
    void exchange_with(T *&p)
    {
        swap(ptr, p);
    }

private:
    holder(const holder<T> &);
    holder<T> &operator=(const holder<T> &);
};

#endif // HOLDER2_H_