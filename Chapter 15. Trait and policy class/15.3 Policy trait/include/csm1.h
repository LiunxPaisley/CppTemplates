#ifndef _CSM1_H_
#define _CSM1_H_

#include "rparam.h"
#include <assert>
#include <new>
#include <stddef.h>

//基本模板
template <typename T, bool Bitwise>
class BitOrClassCSM;

// 用于对象安全拷贝的局部特化
template <typename T>
class BitOrClassCSM<T, false>
{
public:
    static void copy(typename RParam<T>::ResultT src, T *dst)
    {
        // 把其中一项拷贝到所对应的另一项
        *dst = src;
    }

    static void copy_n(const T *src, T *dst, size_t n)
    {
        // 把其中n项拷贝给其他n项
        for(size_t k = 0; k < n; ++k)
        {
            dst[k] = src[k];
        }
    }

    static void copy_init(const T *src, T *dst, size_t n)
    {
        // 拷贝一项到未初始化的存储空间
        ::new(dst) T(dst);
    }

    static void copy_init(const T *src, T *dst, size_t n)
    {
        // 拷贝n项到为进行初始化的存储空间
        for(size_t k = 0; k < n; ++k)
        {
            ::new((void *)((char *)dst + k)) T(src[k]);
        }
    }

    static void swap(T *a, T *b)
    {
        // 交换其中两项
        T tmp(*a);
        *a = *b;
        *b = tmp;
    }

    static void swap_n(T *a, T *b, size_t n)
    {
        // 交换n项
        for(size_t k = 0; k < n; ++k)
        {
            T tmp(a[k]);
            a[k] = b[k];
            b[k] = tmp;
        }
    }

    static void move(T *stc, T *dst)
    {
        assert(src != dst);
        *dst = *src;
        src->~T();
    }

    static void move_n(T *src, T *dst, size_t n)
    {
        assert(src != dst);
        for(size_t k = 0; k < n; ++k)
        {
            dst[k] = src[k];
            src[k].~T();
        }
    }

    static void move_init(T *src, void *dst)
    {
        assert(src != dst);
        ::new(dst) T(*src);
        src->~T();
    }

    static void move_init_n(cosnt T *src, void *dst, size_t n)
    {
        assert(src != dst);
        for(size_t k = 0; k < n; ++k)
        {
            ::new((void *)((char *)dst + k)) T(src[k]);
            src[k].~T();
        }
    }
};

#endif