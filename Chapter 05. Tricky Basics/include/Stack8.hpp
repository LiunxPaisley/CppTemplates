#ifndef _STACK8_H_
#define _STACK8_H_

#include <deque>
#include <memory>
#include <stdexcept>
#include <type_traits>

// 模板的模板参数
// 用一个包含相同模板参数（ELEM, ALLOC）的模板参数（CONT）来表示这个模板（std::deque）
template <typename T,
          template <typename ELEM, typename ALLOC = std::allocator<ELEM>> class CONT = std::deque>
class Stack
{
public:
    void push(const T &);
    T pop();
    T top() const;
    bool empty() const { return elems.empty(); }
    // ALLOC2用不上，省略不写
    template <typename T2,
              template <typename ELEM2, typename = std::allocator<ELEM2>> class CONT2>
    Stack<T, CONT> &operator=(const Stack<T2, CONT2> &);

private:
    CONT<T> elems;
};

template <typename T, template <typename, typename> class CONT>
void Stack<T, CONT>::push(const T &elem)
{
    elems.push_back(elem);
}

template <typename T, template <typename, typename> class CONT>
T Stack<T, CONT>::pop()
{
    if(elems.empty())
    {
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }
    T elem = elems.back();
    elems.pop_back();
    return elem;
}

template <typename T, template <typename, typename> class CONT>
T Stack<T, CONT>::top() const
{
    if(elems.empty())
    {
        throw std::out_of_range("Stack<>::top(): empty stack");
    }
    return elems.back();
}

template <typename T, template <typename, typename> class CONT>
template <typename T2, template <typename, typename> class CONT2>
Stack<T, CONT> &Stack<T, CONT>::operator=(const Stack<T2, CONT2> &rhs)
{
    if(static_cast<void*>(this) == const_cast<void*>(static_cast<const void*>(&rhs)))
    {
        return *this;
    }
    Stack<T2, CONT2> tmp(rhs);
    elems.clear();
    while(!tmp.empty())
    {
        elems.push_front(tmp.top());
        tmp.pop();
    }
    return *this;
}

#endif // !_STACK8_H_
