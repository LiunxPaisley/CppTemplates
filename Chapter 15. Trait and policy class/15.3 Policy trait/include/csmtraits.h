#ifndef _CSMTRAITS_H_
#define _CSMTRAITS_H_

#include "../../15.2 Type function/include/isClassType.h"

template <typename T>
class CSMtraits : public BitOrClassCSM<T, isClassType<T>::No>
{
};

#endif