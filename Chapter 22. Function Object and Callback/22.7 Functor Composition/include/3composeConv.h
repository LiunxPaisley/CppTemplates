#ifndef COMPOSE_CONV3_H_
#define COMPOSE_CONV3_H_

#include "2compose.h"

template <typename FO1, typename FO2>
inline Composer<FO1, FO2> compose(FO1 f1, FO2 f2)
{
    return Composer<FO1, FO2>(f1, f2);
}

#endif // COMPOSE_CONV3_H_