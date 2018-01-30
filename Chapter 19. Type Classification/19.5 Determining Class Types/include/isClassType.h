#ifndef IS_CLASS_TYPE_H_
#define IS_CLASS_TYPE_H_

#include "../../19.1 Determining Fundamental Types/include/isFunda.h"
//#include "../../19.2 Determining Compound Types/include/isCompoundType.h"
// 辨别函数类型和组合类型基本模板
#include "../../19.3 Identifying Function Types/include/isFunctionType1.h"

#include "../../19.2 Determining Compound Types/include/isArrayType.h"
#include "../../19.2 Determining Compound Types/include/isPointer.h"
#include "../../19.2 Determining Compound Types/include/isPointerMember.h"
#include "../../19.2 Determining Compound Types/include/isReferenceType.h"
#include "../../19.4 Determining Enumeration Types/include/isEnumType.h"

template <typename T>
class isClassType
{
public:
    enum
    {
        Yes = isFundaT<T>::No &&
              isEnumType<T>::No &&
              !isCompoundType<T>::isPointerType &&
              !isCompoundType<T>::isReferenceType &&
              !isCompoundType<T>::isArrayType &&
              !isCompoundType<T>::isPointerMemberType &&
              !isCompoundType<T>::isFunctionType
    };

    enum
    {
        No = !Yes
    };
};

#endif // IS_CLASS_TYPE_H_