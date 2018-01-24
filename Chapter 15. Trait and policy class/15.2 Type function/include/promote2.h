#ifndef _PROMOTE2_H_
#define _PROMOTE2_H_

template <typename T>
class promotion<T, T>
{
public:
    typedef T ResultT;
};

#endif