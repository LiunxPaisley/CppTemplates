#ifndef BINDER5_H_
#define BINDER5_H_

#include "../../../Chapter 15. Trait and policy class/15.2 Type function/include/ifThenElse.h"
#include "../../22.6 Introspection/include/1functorParam1.h"
#include "../../22.6 Introspection/include/2functorParam2.h"
#include "../../22.6 Introspection/include/4forwardParam.h"
#include "binderParams.h"
#include "boundVal.h"
#include "signSelect.h"

template <typename FO, int P, typename V>
class Binder : private FO, private V
{
public:
    // 参数数目减少一个， 因为有一个参数已经被绑定了
    enum
    {
        NumParams = FO::NumParams - 1
    };
    // 返回类型是直接委托过来的
    typedef typename FO::ResultT ResultT;

    // 参数的类型
    typedef BinderParams<FO, P> Params;
#define ComposeParamT(N)                                               \
    typedef typename ForwardParamT<typename Params::Param##N##T>::Type \
        Param##N##T
    ComposeParamT(1);
    ComposeParamT(2);
    ComposeParamT(3);
// ...
#undef ComposeParamT

    // 构造函数
    Binder(FO &f) : FO(f) {}
    Binder(FO &f, V &v) : FO(f), V(v) {}
    Binder(FO &f, const V &v) : FO(f), V(v) {}
    Binder(const FO &f) : FO(f) {}
    Binder(const FO &f, V &v) : FO(f), V(v) {}
    Binder(const FO &f, const V &v) : FO(f), V(v) {}
    template <class T>
    Binder(FO &f, T &v) : FO(f), V(BoundVal<T>(v)) {}
    template <class T>
    Binder(FO &f, const T &v) : FO(f), V(BoundVal<const T>(v)) {}
    // ...

    // 函数调用
    ReturnT operator()()
    {
        return FO::operator()(V::get());
    }
    ReturnT operator()(Param1T v1)
    {
        return FO::operator()(ArgSelect<1>::from(v1, v1, V::get()),
                              ArgSelect<2>::from(v1, v1, V::get()));
    }
    ReturnT operator()(Param1T v1, Param2T v2)
    {
        return FO::operator()(ArgSelect<1>::from(v1, v1, V::get()),
                              ArgSelect<2>::from(v1, v2, V::get()),
                              ArgSelect<3>::from(v2, v2, V::get()));
    }
    ReturnT operator()(Param1T v1, Param2T v2, Param3T v3)
    {
        return FO::operator()(ArgSelect<1>::from(v1, v1, V::get()),
                              ArgSelect<2>::from(v1, v2, V::get()),
                              ArgSelect<3>::from(v2, v3, V::get()),
                              ArgSelect<4>::from(v3, v3, V::get()));
    }
    // ...
private:
    template <int A>
    class ArgSelect
    {
    public:
        // 位于绑定值前面的类型
        typedef typename TypeOp<
            typename ifThenElse<(A <= Params::NumParams),
                                FunctorParam<Params, A>,
                                FunctorParam<Params, A - 1>>::ResultT::Type>::RefT
            NoSkipT;
        // 位于绑定值后面的类型
        typedef typename TypeOp<
            typename ifThenElse<(A > 1),
                                FunctorParam<Params, A - 1>,
                                FunctorParam<Params, A>>::ResultT::Type>::RefT
            SkipT;
        // 绑定实参的类型
        typedef typename TypeOp<typename V::ValueT>::RefT BindT;

        // 借助不同的类，来实现3种选择情况：
        class NoSkip
        {
        public:
            static NoSkipT select(SkipT prev_arg, NoSkipT arg, BindT bound_val)
            {
                return arg;
            }
        };
        class Skip
        {
        public:
            static SkipT select(SkipT prev_arg, NoSkipT arg, BindT bound_val)
            {
                return prev_arg;
            }
        };
        class Bind
        {
        public:
            static BindT select(SkipT prev_arg, NoSkipT arg, BindT bound_val)
            {
                return bound_val;
            }
        };

        // 外部实际调用的函数
        typedef typename SignSelectT<A - P, NoSkipT,
                                     BindT, SkipT>::ResultT
            ReturnT;
        typedef typename SignSelectT<A - P, NoSkip,
                                     Bind, Skip>::ResultT
            SelectedT;
        static ReturnT from(SkipT prev_arg, NoSkipT arg, BindT bound_val)
        {
            return SelectedT::select(prev_arg, arg, bound_val);
        }
    };
};

#endif // BINDER5_H_