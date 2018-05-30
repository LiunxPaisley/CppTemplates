#ifndef IS_ARRAY_TYPE_H_
#define IS_ARRAY_TYPE_H_

#include <cstddef> // 定义了各种变量类型和宏。这些定义中的大部分也出现在其它头文件中。

//#include "isCompoundType.h"
// 辨别函数类型和组合类型基本模板
#include "../../19.3 Identifying Function Types/include/isFunctionType1.h"

// 针对数组的局部特化
template <typename T, size_t N>
class isCompoundType<T[N]>
{
public:
    enum
    {
        isPointerType = 0,
        isReferenceType = 0,
        isArrayType = 1,
        isFunctionType = 0,
        isPointerMemberType = 0
    };
    typedef T BaseType;
    typedef typename isCompoundType<T>::BottomType BottomType;
    typedef isCompoundType<void> ClassT;
};

// 针对空数组的局部特化
template <typename T>
class isCompoundType<T[]>
{
public:
    enum
    {
        isPointerType = 0,
        isReferenceType = 0,
        isArrayType = 1,
        isFunctionType = 0,
        isPointerMemberType = 0
    };
    typedef T BaseType;
    typedef typename isCompoundType<T>::BottomType BottomType;
    typedef isCompoundType<void> ClassT;
};

#endif // IS_ARRAY_TYPE_H_