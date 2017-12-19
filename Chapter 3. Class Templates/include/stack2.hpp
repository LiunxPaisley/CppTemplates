/**
 * 模板特化的实现可以和基本类模板的实现完全不同
*/

#include <deque>
#include <string>
#include <stdexcept>

#include "stack1.hpp"

using std::string;

template <>
class Stack<string>
{
  public:
    void push(string const &);
    string pop();
    string top() const;
    bool empty() const { return elems.empty(); }

  private:
    std::deque<string> elems;
};

void Stack<string>::push(string const& elem)
{
    elems.push_back(elem);
}

string Stack<string>::pop()
{
    if(elems.empty())
    {
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }
    string elem = elems.back();
    elems.pop_back();
    return elem;
}

string Stack<string>::top() const
{
    if(elems.empty())
    {
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }
    return elems.back();
}