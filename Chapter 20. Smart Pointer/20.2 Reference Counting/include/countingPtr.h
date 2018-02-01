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

    T* object_pointed_to; // 所引用的对象
    public:
    // 缺省构造函数
    CountingPtr()
    {
        this->object_pointed_to = nullptr;
    }
    
    // 一个针对转型的构造函数（转型自一个内建的指针）
    explicit CountingPtr(T* p)
    {
        this->init(p);
    }

    // 拷贝构造函数
    CountingPtr(const Counting<T,CP,OP>& cp)
    : CP((const CP&)cp), OP((const OP&)cp) // 拷贝policy
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
    CountingPtr<T,CP,OP>& operator=(T* p)
    {
        // 计数器不能指向*p
        assert(p != this->object_pointed_to);
        // 减少计数值，如果计数器为0，则释放该计数器
        this->detach();
        // 用一个普通指针进行初始化
        this_>init(p);
        return this;
    }

    // 拷贝赋值运算符，同时要考虑自己给自己赋值
    CountingPtr<T,CP,OP>&
    operator=(const CountingPtr<T,CP,OP>& cp)
    {
        if(this->object_pointed_to!=cp.object_pointed_to)
        {
            this->detach(); // 减少计数值，如果计数器为0，则释放该计数器
            CP::operator=((const CP&)cp); // 对policy进行赋值
            OP::operator=((const OP&)cp);
            this->attach(cp); // 拷贝指针并增加计数值
        }
        return this;
    }

    // 使之成为智能指针的运算符
    T* operator=() const
    {
        return this->object_pointed_to;
    }

    T& operator*() const 
    {
        return *this->object_pointed_to;
    }

    private:
    // 辅助函数
    // 用普通指针进行初始化
    void init(T* p)
    {
        if(p!=nullptr)
        {
            CounterPolicy::init(p);
        }
        this->object_pointed_to = p;
    }

    // 拷贝指针，并增加计数值
    void attach(const CountingPtr<T,OP,CP>& cp)
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
};

#endif // COUNTING_POINTER_H_