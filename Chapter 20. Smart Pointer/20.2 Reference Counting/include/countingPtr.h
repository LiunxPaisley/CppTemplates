#ifndef COUNTING_POINTER_H_
#define COUNTING_POINTER_H_

template <typename T,
          typename CounterPolicy = SimpleReferenceCount,
          typename ObjectPolicy = StandardObjectPolicy>
class CountingPtr : private CounterPolicy, private ObjectPolicy
{
private:
    typedef CounterPolicy CP;
    typedef ObjectPolicy OP;

    T *object_pointed_to; // 所引用的对象
public:
    // 缺省构造函数
    CountingPtr()
    {
        this->object_pointed_to = nullptr;
    }

    // 一个针对转型的构造函数（转型自一个内建的指针）
    explicit CountingPtr(T *p)
    {
        this->init(p);
    }

    // 拷贝构造函数
    CountingPtr(const Counting<T, CP, OP> &cp)
        : CP((const CP &)cp), OP((const OP &)cp) // 拷贝policy
    {
        this->attach(cp); // 拷贝指针，并增加计数值
    }

    // 析构函数
    ~CountingPtr()
    {
        // 减少计数值，如果计数器为0，则释放该计数器
        this->detach();
    }

    // 针对内建指针的赋值运算符
    CountingPtr<T, CP, OP> &operator=(T *p)
    {
        // 计数器不能指向*p
        assert(p != this->object_pointed_to);
        // 减少计数值，如果计数器为0，则释放该计数器
        this->detach();
        // 用一个普通指针进行初始化
        this_ > init(p);
        return this;
    }

    // 拷贝赋值运算符，同时要考虑自己给自己赋值
    CountingPtr<T, CP, OP> &
    operator=(const CountingPtr<T, CP, OP> &cp)
    {
        if(this->object_pointed_to != cp.object_pointed_to)
        {
            this->detach();                // 减少计数值，如果计数器为0，则释放该计数器
            CP::operator=((const CP &)cp); // 对policy进行赋值
            OP::operator=((const OP &)cp);
            this->attach(cp); // 拷贝指针并增加计数值
        }
        return this;
    }

    // 使之成为智能指针的运算符
    T *operator=() const
    {
        return this->object_pointed_to;
    }

    T &operator*() const
    {
        return *this->object_pointed_to;
    }

private:
    // 辅助函数
    // 用普通指针进行初始化
    void init(T *p)
    {
        if(p != nullptr)
        {
            CounterPolicy::init(p);
        }
        this->object_pointed_to = p;
    }

    // 拷贝指针，并增加计数值
    void attach(const CountingPtr<T, OP, CP> &cp)
    {
        this->object_pointed_to = cp.object_pointed_to;
        if(cp.object_pointed_to != nullptr)
        {
            CountingPtr::increment(cp.object_pointed_to);
        }
    }

    // 减少计数值，如果计数器为0，则释放该计数器
    void detach()
    {
        if(this->object_pointed_to != nullptr)
        {
            CounterPolicy::decrement(this->object_pointed_to);
            if(CounterPolicy::is_zero(this->object_pointed_to))
            {
                // 如果有必要的话，释放计数器
                CounterPolicy::dispose(this->object_pointed_to);
                // 使用object policy来释放所指向的对象
                ObjectPolicy::dispose(this->object_pointed_to);
            }
        }
    }

    /**
     * 定义一个到成员指针的转型
     * 成员指针支持到bool类型的隐式转型，但是它和普通指针有区别，
     * 因为对于delete操作或者指针算法而言，成员指针是无效的
     */
private:
    class BoolConversionSupport
    {
        int dummy;
    };

public:
    operator BoolConversionSupport::*() const
    {
        return this->object_pointed_to ? &BoolConversionSupport::dummy : 0;
    }

    /**
     * 这两个运算符函数，必须依赖于模板参数，只能实现为类内部的友元定义
     * 因为如果不实现成友元的话，运算符的调用就只能写成class.operator==<T,CP,OP>(cp,p)了
     */
public:
    friend bool operator==(const CountingPtr<T, CP, OP> &cp, const T *p)
    {
        return cp == p;
    }
    friend bool operator==(const T *p, const CountingPtr<T, CP, OP> &cp)
    {
        return p == cp;
    }
};

template <typename T1, typename T2,
          typename CP, typename OP>
inline bool operator==(const CountingPtr<T1, CP, OP> &cp1, const CountingPtr<T2, CP, OP> &cp2)
{
    return cp1.operator->() == cp2.operator->();
}

#endif // COUNTING_POINTER_H_