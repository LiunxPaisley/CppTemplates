#ifndef IS_POINTER_MEMBER_TYPE_H_
#define IS_POINTER_MEMBER_TYPE_H_

#include "isCompoundType.h"

// 针对成员指针的局部特化
template <typename T, typename C>
class isCompoundType<T C::*>
{
public:
    enum
    {
        isPointerType = 0,
        isReferenceType = 0,
        isArrayType = 0,
        isFunctionType = 0,
        isPointerMemberType = 1
    };
    typedef T BaseType;
    typedef typename isCompoundType<T>::BottomType BottomType;
    typedef isCompoundType<void> ClassT;
};

#endif // IS_POINTER_MEMBER_TYPE_H_