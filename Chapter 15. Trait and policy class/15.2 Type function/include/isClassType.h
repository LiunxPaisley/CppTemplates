#ifndef _ISCLASSTYPE_H_
#define _ISCLASSTYPE_H_

template <typename T>
class isClassType
{
private:
    typedef char One;
    typedef struct
    {
        char a[2];
    } Two;
    template <typename C>
    static One test(int C::*);
    template <typename C>
    static Two test(...);

public:
    enum
    {
        Yes = sizeof(isClassType<T>::test<T>(0)) == 1
    };
    enum
    {
        No = !Yes
    };
};

#endif