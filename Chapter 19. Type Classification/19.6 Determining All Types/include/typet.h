#ifndef TYPET_H_
#define TYPET_H_

// 辨别基本类型
#include "../../19.1 Determining Fundamental Types/include/isFunda.h"

// 辨别函数类型和组合类型基本模板
#include "../../19.3 Identifying Function Types/include/isFunctionType1.h"

// 辨别组合类型
//#include "../../19.2 Determining Compound Types/include/isCompoundType.h"

// 辨别指针类型
#include "../../19.2 Determining Compound Types/include/isPointer.h"

// 辨别数组类型
#include "../../19.2 Determining Compound Types/include/isArrayType.h"

// 辨别成员指针类型
#include "../../19.2 Determining Compound Types/include/isPointerMember.h"

// 辨别引用类型
#include "../../19.2 Determining Compound Types/include/isReferenceType.h"

// 辨别枚举类型
#include "../../19.4 Determining Enumeration Types/include/isEnumType.h"

// 辨别类类型
#include "../../19.5 Determining Class Types/include/isClassType.h"

template <typename T>
class TypeT
{
public:
    enum
    {
        isFundaType = isFundaT<T>::Yes,
        isPointerType = isCompoundType<T>::isPointerType,
        isReferenceType = isCompoundType<T>::isReferenceType,
        isArrayType = isCompoundType<T>::isArrayType,
        isFunctionType = isCompoundType<T>::isFunctionType,
        isPointerMemberType = isCompoundType<T>::isPointerMemberType,
        isEnumType = isEnumType<T>::Yes,
        isClassType = isClassType<T>::Yes
    };
};

#endif // TYPET_H_