//
// Created by liupai on 18-7-4.
//

#include "type_name.h"
#include <type_traits>

#include <assert.h>

using namespace std;

template <class Target, class Source>
inline Target polymorphic_downcast(Source* x)
{
    assert(dynamic_cast<Target>(x) == x);
    return static_cast<Target>(x);
}

template <class Target, class Source>
inline Target polymorphic_downcast(Source& x)
{
    assert(dynamic_cast<typename remove_reference<Target>::type*>(&x) == &x);
    return static_cast<Target>(x);
};

struct A { virtual ~A(){} };

struct B : A {};


int main()
{
    B b;
    A a;
    A* a_ptr = &b;
    B* b_ptr = polymorphic_downcast<B*>(a_ptr);

    A& a_ref = b;
    B& b_ref = polymorphic_downcast<B&>(a_ref);
    TYPE_NAME(a_ptr);
    TYPE_NAME(b_ptr);
    TYPE_NAME(a_ref);
    TYPE_NAME(b_ref);

}