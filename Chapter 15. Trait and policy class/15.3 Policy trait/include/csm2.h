#ifndef _CSM2_H_
#define _CSM2_H_

#include "csm1.h"
#include <cassert>
#include <cstring>
#include <stddef.h>


template <typename T>
class BitOrClassCSM<T, true> : public BitOrClassCSM<T, false>
{
public:
    static void copy_n(const T *src, T *dst, size_t n)
    {
        // 拷贝n项到其他对象
        std::memcpy((void *)dst, (void *)src, n);
    }

    static void copy_init_n(const T *src, void *dst, size_t n)
    {
        // 拷贝n项到未初始化的存储空间
        std::memcpy(dst, (void *)src, n);
    }

    static void move_n(T *src, T *dst, size_t n)
    {
        // 移动n项到其他对象的n项
        assert(src != dst);
        std::memcpy((void *)dst, (void *)src, n);
    }

    static void move_init_n(const T *src, void *dst, size_t n)
    {
        assert(src != dst);
        std::memcpy(dst, (void *)src, n);
    }
};

#endif // !_CSM2_H_