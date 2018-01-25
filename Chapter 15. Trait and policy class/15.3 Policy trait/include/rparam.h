#ifndef _RPARAM_H_
#define _RPARAM_H_

#include "../../15.2 Type function/include/ifThenElse.h"
#include "../../15.2 Type function/include/isClassType.h"

template <typename T>
class RParam
{
public:
    typedef typename ifThenElse<isClassType<T>::No,
                                T,
                                const T &>::ResultT Type;
};

#endif // !_RPARAM_H_