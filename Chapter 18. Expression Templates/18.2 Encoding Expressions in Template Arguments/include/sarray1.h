#ifndef SARRAY1_H_
#define SARRAY1_H_

#include <cassert>
#include <cstddef>

template <typename T>
class SArray
{
private:
    T *storage;
    size_t storage_size;

public:
    // 创建一个具有初始值大小的数据
    explicit SArray(size_t s)
        : storage(new T[s]), storage_size(s)
    {
    }
    // 拷贝构造函数
    SArray(const SArray<T> &orig)
        : storage(new T[orig.size()]), storage_size(orig.size())
    {
        copy(orig);
    }

    // 析构函数
    ~SArray()
    {
        delete[] storage;
    }

    // 赋值运算符
    SArray<T> &operator=(const SArray<T> &orig)
    {
        if(&orig != this)
        {
            copy(orig);
        }
        return *this;
    }

    // 返回数组大小
    size_t size() const
    {
        return storage_size;
    }

    // 针对常数和变量的下标运算符
    T operator[](size_t idx) const
    {
        return storage[idx];
    }

    T &operator[](size_t idx)
    {
        return storage[idx];
    }

protected:
    // 运用缺省构造函数来初始化值
    void init()
    {
        for(size_t idx = 0; idx < size(); ++idx)
        {
            storage[idx] = T();
        }
    }

    void copy(const SArray<T> &orig)
    {
        assert(size() == orig.size());
        for(size_t idx = 0; idx < size(); ++idx)
        {
            storage[idx] = orig.storage[idx];
        }
    }
}; // class SArray

#endif // SARRAY1_H_