#ifndef MEMBER_REF_COUNT_H_
#define MEMBER_REF_COUNT_H_

/**
 * 侵入式计数器
 * 将计数器放入被管理的对象本身的类型中
 */

template <typename ObjectType, 
    typename CountType, 
    CountType ObjectType::*CountP>
class menberReferenceCount
{
public:
    //缺省构造函数和析构函数都是允许的
    
    // 让计数器的值初始化为1
    void init(Object* object)
    {
        object->*CountP = 1;
    }

    // 对于计数器的释放，并不需要显示执行任何操作
    void dispose(ObjectType*){}

    // 计数值加1
    void increment(ObjectType* object)
    {
        ++object->*CountP;
    }

    // 计数值减1
    void decrement(ObjectType* object)
    {
        --object->*CountP;
    }

    // 检查计数值是否为0
    template<typename T> bool is_zero(ObjectType* object)
    {
        return object->*CountP == 0;
    }
};

#endif // MEMBER_REF_COUNT_H_