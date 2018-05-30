#ifndef IS_COMPOUND_TYPE_H_
#define IS_COMPOUND_TYPE_H_

// 基本模板
template <typename T>
class isCompoundType
{
public:
    enum
    {
        isPointerType = 0,
        isReferenceType = 0,
        isArrayType = 0,
        isFunctionType = 0,
        isPointerMemberType = 0
    };
    typedef T BaseType;
    typedef T BottomType;
    typedef isCompoundType<void> ClassType;
};

#endif // IS_COMPOUND_TYPE_H_