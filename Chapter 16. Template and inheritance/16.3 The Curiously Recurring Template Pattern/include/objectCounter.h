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
    
    // 拷贝构造函数
    ObjectCounter(const ObjectCounter<CountedType>&)
    {
        ++ObjectedCounter<CountedType>::count;
    }

    // 析构函数
    ~ObjectCounter()
    {
        --ObjectCounter<CountedType>::count;
    }
    public:
    static size_t live()
    {
        return ObjectCounter<CountedType>::count;
    }
};

template<typename CountedType>
size_t ObjectCounter<CountedType>::count = 0;

#endif // OBJECT_COUNTER_H_