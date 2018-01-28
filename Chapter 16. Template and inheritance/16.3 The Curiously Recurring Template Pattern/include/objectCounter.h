#ifndef OBJECT_COUNTER_H_
#define OBJECT_COUNTER_H_

#include <cstddef>

template <typename CountedType>
class ObjectCounter
{
private:
    static size_t count;

protected:
    ObjectCounter()
    {
        ++ObjectCounter<CountedType>::count;
    }
};

#endif // OBJECT_COUNTER_H_