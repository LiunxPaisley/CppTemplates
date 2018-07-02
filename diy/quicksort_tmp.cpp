#include <type_traits>
#include <stdio.h>

template <typename T, T... Args>
struct TArray {
};

template <typename T, T H, T... Others>
struct TArray<T, H, Others...> {
    typedef T                    ElemType;
    static constexpr T           head = H;
    typedef TArray<T, Others...> Tail;
    static Tail                  GetTail()
    {
        return Tail();
    }

    template <T... Arr2>
    struct Link {
        typedef TArray<T, H, Others..., Arr2...> type;
    };

    template <T V>
    struct Link<V> {
        typedef TArray<T, H, Others..., V> type;
    };

    template <T... Arr2>
    static TArray<T, H, Others..., Arr2...>
    _LinkArray(const TArray<T, Arr2...>&)
    {
        return Link<Arr2...>::type();
    }

    template <typename Arr>
    struct LinkArray {
        typedef decltype(_LinkArray(Arr())) type;
    };

    template <template <T N> class Cond, typename Acc0>
    struct Filter {
        typedef typename std::conditional<
            Cond<head>::value,
            typename Tail::template Filter<
                Cond, typename Acc0::template Link<head>::type>::type,
            typename Tail::template Filter<Cond, Acc0>::type>::type type;
    };
};

template <typename T>
struct TArray<T> {
    typedef T ElemType;
    // static constexpr char head = 0;
    // typedef TArray<T> Tail;

    template <T... Arr2>
    struct Link {
        typedef TArray<T, Arr2...> type;
    };

    template <T V>
    struct Link<V> {
        typedef TArray<T, V> type;
    };

    template <T... Arr2>
    static TArray<T, Arr2...> _LinkArray(const TArray<T, Arr2...>&)
    {
        return Link<Arr2...>::type();
    }

    template <typename Arr>
    struct LinkArray {
        typedef decltype(_LinkArray(Arr())) type;
    };

    template <template <T N> class Cond, typename Acc0>
    struct Filter {
        typedef Acc0 type;
    };
};

template <typename T, T H>
struct TArray<T, H> {
    typedef T          ElemType;
    static constexpr T head = H;
    typedef TArray<T>  Tail;
    static Tail        GetTail()
    {
        return Tail();
    }

    template <T... Arr2>
    struct Link {
        typedef TArray<T, H, Arr2...> type;
    };

    template <T V>
    struct Link<V> {
        typedef TArray<T, H, V> type;
    };

    template <T... Arr2>
    static TArray<T, H, Arr2...> _LinkArray(const TArray<T, Arr2...>&)
    {
        return Link<Arr2...>::type();
    }

    template <typename Arr>
    struct LinkArray {
        typedef decltype(_LinkArray(Arr())) type;
    };

    template <template <T N> class Cond, typename Acc0>
    struct Filter {
        typedef typename std::conditional<
            Cond<head>::value,
            typename Tail::template Filter<
                Cond, typename Acc0::template Link<head>::type>::type,
            typename Tail::template Filter<Cond, Acc0>::type>::type type;
    };
};

template <typename T, T N>
struct LTCond {
    template <T N2>
    struct Comp {
        static constexpr bool value = N2 < N;
    };
};

template <typename T, T N>
struct GECond {
    template <T N2>
    struct Comp {
        static constexpr bool value = N2 >= N;
    };
};

template <typename Array>
struct QuickySort {
    typedef typename Array::ElemType                              ElemType;
    typedef LTCond<ElemType, Array::head>                         _LeftComp;
    typedef GECond<ElemType, Array::head>                         _RightComp;
    typedef typename QuickySort<typename Array::Tail::template Filter<
        _LeftComp::template Comp, TArray<ElemType>>::type>::type  _Left;
    typedef typename QuickySort<typename Array::Tail::template Filter<
        _RightComp::template Comp, TArray<ElemType>>::type>::type _Right;
    typedef typename _Left::template Link<
        Array::head>::type::template LinkArray<_Right>::type type;
};

template <>
struct QuickySort<TArray<int>> {
    typedef int         ElemType;
    typedef TArray<int> type;
};

template <typename T, T... Vals>
void test12(const TArray<T, Vals...>& vals)
{
    printf("%d\n", vals.head);
    test12(vals.GetTail());
}

template <typename T>
void test12(const TArray<T>&)
{
}

int main()
{
    typedef TArray<int, 6, 7, 4, 2, 1, 3, 2, 9> ArrayX;
    typedef typename QuickySort<ArrayX>::type   Array2;
    test12(Array2());
    return 0;
};