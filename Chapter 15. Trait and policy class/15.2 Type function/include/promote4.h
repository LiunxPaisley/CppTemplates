#ifndef _PROMOTE4_H_
#define _PROMOTE4_H_

#include "promote3.h"

MK_PROMOTION(bool,char,int)
MK_PROMOTION(bool, unsigned char, int)
MK_PROMOTION(bool, signed char, int)

#endif