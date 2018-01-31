#ifndef TRULE_H_
#define TRULE_H_

template <typename T>
class holder;

template <typename T>
class trule
{
private:
    T *ptr; //  trule所引用的对象
public:
    // 构造函数，确保trule只能作为返回类型，用于将holde
    // 从被调用函数传递给调用函数
    trule(Holder<T> &h)
    {
        ptr = h.get();
        h.release();
    }

    // 拷贝构造函数
    trule(const trule<T> &t)
    {
        ptr = t.ptr;
        const_cast<trule<T> &>(t).ptr = nullptr;
    }

    // 析构函数
    ~trule()
    {
        delete ptr;
    }

private:
    trule(trule<T> &);               // 禁止将trule作为左值
    trule<T> &operator=(trule<T> &); // 禁止拷贝赋值
    friend class holder<T>;
};

#endif // TRULE_H_