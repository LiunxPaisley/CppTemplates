#ifndef _STACK4_H_
#define _STACK4_H_

#include <vector>
#include <stdexcept>

template <typename T, int MAXSIZE>
class Stack
{
  public:
    Stack();
    void push(T const &);
    T pop();
    T top() const;
    bool empty() const { return numElems == 0; }
    bool full() const { return numElems == MAXSIZE; }

  private:
    T elems[MAXSIZE];
    int numElems;
};

template <typename T, int MAXSIZE>
Stack<T, MAXSIZE>::Stack()
    : numElems(0)
{
}

template <typename T, int MAXSIZE>
void Stack<T, MAXSIZE>::push(T const &_elem)
{
    if (numElems == MAXSIZE)
    {
        throw std::out_of_range("Stack<>::push(): stack  is full");
    }
    elems[numElems] = _elem;
    ++numElems;
}

template <typename T, int MAXSIZE>
T Stack<T, MAXSIZE>::pop()
{
    if (numElems <= 0)
    {
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }
    T elem = elems[numElems - 1];
    --numElems;
    return elem;
}

template <typename T, int MAXSIZE>
T Stack<T, MAXSIZE>::top() const
{
    if (numElems <= 0)
    {
        throw std::out_of_range("Stack<>::top(): empty stack");
    }
    return elems[numElems - 1];
}

#endif // stack4.h