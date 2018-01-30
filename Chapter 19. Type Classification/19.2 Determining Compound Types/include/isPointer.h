#ifndef IS_POINTER_H_
#define IS_POINTER_H_

#include "isCompoundType.h"

template <typename T>
class isCompoundType<T *>
{
public:
    enum
    {
        isPointerType = 1,
        isReferenceType = 0,
        isArrayType = 0,
        isFunctionType = 0,
        isPointerMemberType = 0
    };
    typedef T BaseType;
    typedef typename isCompoundType<T>::BottomType BottomType;
    typedef isCompoundType<void> ClassType;
};

#endif // IS_POINTER_H_