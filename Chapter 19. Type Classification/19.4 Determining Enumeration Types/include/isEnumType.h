#ifndef IS_ENUM_TYPE_H_
#define IS_ENUM_TYPE_H_

#include "../../19.1 Determining Fundamental Types/include/isFunda.h"
//#include "../../19.2 Determining Compound Types/include/isCompoundType.h"
// 辨别函数类型和组合类型基本模板
#include "../../19.3 Identifying Function Types/include/isFunctionType1.h"

#include "../../19.2 Determining Compound Types/include/isArrayType.h"
#include "../../19.2 Determining Compound Types/include/isPointer.h"
#include "../../19.2 Determining Compound Types/include/isPointerMember.h"
#include "../../19.2 Determining Compound Types/include/isReferenceType.h"

struct sizeOverOne
{
    char c[2];
};

// 去除函数类型和数组类型的情况
template <typename T,
          bool convert_possible = !isCompoundType<T>::isFunctionType && !isCompoundType<T>::isArrayType>
class ConsumeUDC
{
public:
    operator T() const;
};

// 到函数类型和数组类型的转型是不允许的
template <typename T>
class ConsumeUDC<T, false>
{
};

// 到void类型的转型是不允许的
template <bool convert_possible>
class ConsumeUDC<void, convert_possible>
{
};

// enum_check的形参可以让enum类型转换成整型
char enum_check(bool);
char enum_check(char);
char enum_check(signed char);
char enum_check(unsigned char);
char enum_check(wchar_t);

char enum_check(signed short);
char enum_check(unsigned short);
char enum_check(signed short);
char enum_check(signed int);
char enum_check(unsigned int);
char enum_check(signed long);
char enum_check(unsigned long);

#if LONGLONG_EXISTS
char enum_check(signed long long);
char enum_check(unsigned long long);
#endif // LONGLONG_EXISTS

// 避免从float到int的意外转型
char enum_check(float);
char enum_check(double);
char enum_check(long double);

// 处理剩余情况
sizeOverOne enum_check(...);

template <typename T>
class isEnumType
{
public:
    /**
     * 关键在sizeof表达式中
     * Yes前面已经去掉了基本类型、引用类型、指针类型和成员指针类型的情况
     * 剩余的类型有：函数类型，数组类型，类类型和枚举类型
     * 函数类型和数组类型在ConsumeUDC定义中已经去除
     * 对于类类型，ConsumeUDC会先调用Consume中重载的类型转换运算符，转换成类类型
     * 此时enum_check会匹配到剩余情况中，返回值大小为2
     * 于是能够成功使Yes为1的只有枚举类型
     */
    enum
    {
        Yes = isFundaT<T>::No &&
              !isCompoundType<T>::isReferenceType &&
              !isCompoundType<T>::isPointerType &&
              !isCompoundType<T>::isPointerMemberType &&
              sizeof(enum_check(ConsumeUDC<T>())) == 1
    };
    enum
    {
        No = !Yes
    };
};

#endif // IS_ENUM_TYPE_H_