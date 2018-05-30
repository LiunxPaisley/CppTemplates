#ifndef FUNCTION_PTR_H_
#define FUNCTION_PTR_H_

#include "3functionPtrType.h"
#include "4forwardParam.h"

template <typename RT, typename P1 = void,
          typename P2 = void,
          typename P3 = void>
class FunctionPtr
{
private:
    typedef typename FunctionPtrType<RT, P1, P2, P3>::Type FuncPtr;
    // 封装的指针
    FuncPtr fptr;

public:
    // 使之适合我们的框架
    enum
    {
        NumParams = FunctionPtrType<RT, P1, P2, P3>::NumParams
    };
    typedef RT ReturnT;
    typedef P1 Param1T;
    typedef P2 Param2T;
    typedef P3 Param3T;

    // 构造函数
    FunctionPtr(FuncPtr ptr)
        : fptr(ptr)
    {
    }

    // 函数调用
    RT operator()()
    {
        return fptr();
    }
    RT operator()(typename ForwardParamT<P1>::Type a1)
    {
        return fptr(a1);
    }
    RT operator()(typename ForwardParamT<P1>::Type a1,
                  typename ForwardParamT<P2>::Type a2)
    {
        return fptr(a1, a2);
    }
    RT operator()(typename ForwardParamT<P1>::Type a1,
                  typename ForwardParamT<P2>::Type a2,
                  typename ForwardParamT<P3>::Type a3)
    {
        return fptr(a1, a2, a3);
    }
};

#endif // FUNCTION_PTR_H_