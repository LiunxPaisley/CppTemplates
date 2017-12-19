#include <vector>
#include <stdexcept>

using std::vector;

template <typename T, typename CONT = vector<T> >
class Stack
{
  public:
    void push(T const &);
    T pop();
    T top() const;
    bool empty() const { return elems.empty(); }

  private:
    CONT elems;
};

template <typename T, typename CONT = vector<T> >
void Stack<T, CONT>::push(T const &_elem)
{
    elems.push_back(_elem);
}

template <typename T, typename CONT = vector<T> >
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

template <typename T, typename CONT = vector<T> >
T Stack<T, CONT>::top() const
{
    if (elems.empty())
    {
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }
    return elems.back();
}