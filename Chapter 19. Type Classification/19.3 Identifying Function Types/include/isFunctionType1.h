#ifndef IS_FUNCTION_TYPE1_H_
#define IS_FUNCTION_TYPE1_H_

//#include "../../19.2 Determining Compound Types/include/isCompoundType.h"

template <typename T>
class isFunctionType
{
private:
    typedef char one;
    typedef struct
    {
        char a[2];
    } Two;

    template <typename U>
    static One test(...);

    template <typename U>
    statci Two test(U (*)[1]);

public:
    enum
    {
        Yes = sizeof(isFunctionType<T>::test<T>(0)) == 1
    };
    enum
    {
        No = !Yes
    };
};

template <typename T>
class isFunctionType<T &>
{
public:
    enum
    {
        Yes = 0
    };
    enum
    {
        No = !Yes
    };
};

template <>
class isFunctionType<void>
{
public:
    enum
    {
        Yes = 0
    };
    enum
    {
        No = !Yes
    };
};

template <>
class isFunctionType<const void>
{
public:
    enum
    {
        Yes = 0
    };
    enum
    {
        No = !Yes
    };
};

template <>
class isFunctionType<void volatile>
{
public:
    enum
    {
        Yes = 0
    };
    enum
    {
        No = !Yes
    };
};

template <>
class isFunctionType<const void volatile>
{
public:
    enum
    {
        Yes = 0
    };
    enum
    {
        No = !Yes
    };
};

template <typename T>
class isCompoundType
{
public:
    enum
    {
        isPointerType = 0,
        isReferenceType = 0,
        isArrayType = 0,
        isFunctionType = isFunctionType<T>::Yes,
        isPointerMemberType = 0
    };
    typedef T BaseType;
    typedef T BottomType;
    typedef isCompoundType<void> ClassType;
};

#endif // IS_FUNCTION_TYPE1_H_