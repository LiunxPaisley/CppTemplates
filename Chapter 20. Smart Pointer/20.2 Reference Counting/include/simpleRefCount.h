#ifndef SIMPLE_REF_COUNT_H_
#define SIMPLE_REF_COUNT_H_

/**
 * 非侵入式计数器
 * 不把计数器存储在所指向对象的内部
  */

#include "allocator.h"
#include <cstddef>


class simpleRefCount
{
private:
    /**
     * counter的生命周期必须持续到最后一个智能指针被释放之后
     * 所以使用一种特殊的分配器来完成这种任务：allocator.h
     */
    size_t *counter;

public:
    simpleRefCount()
    {
        counter = nullptr;
    }

    // 缺省的拷贝构造函数和拷贝赋值运算符都是允许的
    // 因为它们只是拷贝这个共享的计数器
public:
    // 分配计数器，并把它的值初始化为1
    template <typename T>
    void init(T *)
    {
        counter = alloc_counter();
        *counter = 1;
    }

    // 释放该计数器
    template <typename T>
    void dispose(T *)
    {
        dealloc_counter(counter);
    }

    // 计数器值加1
    template <typename T>
    void increment(T *)
    {
        ++*counter;
    }

    // 计数值减1
    template <typename T>
    void decrement(T *)
    {
        --*counter;
    }

    // 检查计数值是否为0
    template <typename T>
    void is_zero(T *)
    {
        return *counter == 0;
    }
};

#endif // SIMPLE_REF_COUNT_H_