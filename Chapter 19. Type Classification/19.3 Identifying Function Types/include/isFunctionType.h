#ifndef IS_FUNCTION_TYPE_H_
#define IS_FUNCTION_TYPE_H_

#include "../../19.2 Determining Compound Types/include/isCompoundType.h"

template <typename R>
class isCompoundType<R()>
{
public:
    enum
    {
        isPointerType = 0,
        isReferenceType = 0,
        isArrayType = 0,
        isFunctionType = 1,
        isPointerMemberType = 0
    };
    typedef R BaseT;
    typedef R BottomT;
    typedef isCompoundType<void> ClassType;
};

template <typename R, typename P1>
class isCompoundType<R(P1)>
{
public:
    enum
    {
        isPointerType = 0,
        isReferenceType = 0,
        isArrayType = 0,
        isFunctionType = 1,
        isPointerMemberType = 0
    };
    typedef R BaseType(P1);
    typedef R BottomType(P1);
    typedef isCompoundType<void> ClassType;
};

template <typename R, typename P1>
class isCompoundType<R(P1, ...)>
{
public:
    enum
    {
        isPointerType = 0,
        isReferenceType = 0,
        isArrayType = 0,
        isFunctionType = 1,
        isPointerMemberType = 0
    };
    typedef R BaseType(P1);
    typedef R BottomType(P1);
    typedef isCompoundType<void> ClassType;
};

#endif // IS_FUNCTION_TYPE_H_