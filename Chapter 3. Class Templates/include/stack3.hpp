#include <vector>
#include <deque>
#include <stdexcept>

using std::vector;

template <typename T, typename CONT = vector<T> >
class Stack
{
  public:
    void push(const T&);
    T pop();
    T top() const;
    bool empty() const { return elems.empty(); }

  private:
    CONT elems;
};

/**
 * 这里不能加CONT的默认参数
*/
template <typename T, typename CONT>
void Stack<T, CONT>::push(const T& _elem)
{
    elems.push_back(_elem);
}

template <typename T, typename CONT>
T Stack<T, CONT>::pop()
{
    if (elems.empty())
    {
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }
    T elem = elems.back();
    elems.pop_back();
    return elem;
}

template <typename T, typename CONT>
T Stack<T, CONT>::top() const
{
    if (elems.empty())
    {
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }
    return elems.back();
}