#ifndef SIMPLE_REF_COUNT_H_
#define SIMPLE_REF_COUNT_H_

#include <cstddef>
#include "allocator.h"

class simpleRefCount
{
    private:
    size_t* counter;
    public:
    simpleRefCount()
    {
        
    }
};

#endif // SIMPLE_REF_COUNT_H_