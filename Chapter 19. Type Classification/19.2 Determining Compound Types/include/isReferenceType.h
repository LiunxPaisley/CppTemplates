#ifndef IS_REFERENCE_TYPE_H_
#define IS_REFERENCE_TYPE_H_

#include "isCompoundType.h"

template <typename T>
class isCompoundType<T&>
{
public:
    enum{isPointerType = 0, isReferenceType = 1, isArrayType = 0, isFunctionType = 0, isPointerMemberType = 0};
    typedef T BaseT;
    typedef typename isCompoundType<T>::BottomType BottomType;
    typedef isCompoundType<void> ClassType;
};

#endif // IS_REFERENCE_TYPE_H_