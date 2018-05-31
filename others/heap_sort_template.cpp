// 作者：雨城居
// 链接：https://zhuanlan.zhihu.com/p/32299097
// 来源：知乎
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

struct null
{
};
template <class left, class right>
struct cons
{
};
template <class left>
struct cons<left, null>
{
};

template <class left, class right>
struct cons
{
    using car = left;
    using cdr = right;
    static int const length = cdr::length + 1;
};
template <class left>
struct cons<left, null>
{
    using car = left;
    using cdr = null;
    static int const length = 1;
};

template <class head, class... tail>
struct list_item
{
    using type = cons<head, typename list_item<tail...>::type>;
};
template <class head>
struct list_item<head>
{
    using type = cons<head, null>;
};
template <>
struct list_item<null>
{
    using type = null;
};
//为了list和cons巴拉巴拉的真正统一
template <class T, class... tail>
using list = typename list_item<T, tail...>::type;

template <int a, int b, class _list>
struct swap
{
    using temp = typename change_list<a, find_list<b, _list>::result::value, _list>::result;
    using result = typename change_list<b, find_list<a, _list>::result::value, temp>::result;
};

template <int n, class _list>
struct find_list
{
    using result = typename find_list<n - 1, typename _list::cdr>::result;
};
template <class head>
struct find_list<0, list_item<head>>
{
    using result = typename list_item<head>::car;
};
template <class _list>
struct find_list<0, _list>
{
    using result = typename _list::car;
};

template <int start, int end, class _list>
struct copy_list
{
    using result = cons<typename find_list<start, _list>::result,
                        typename copy_list<start, end - 1, typename _list::cdr>::result>;
};

template <class cons1, class cons2>
struct append
{
    using result = cons<typename cons1::car,
                        typename append<typename cons1::cdr, cons2>::result>;
};
template <class cons2>
struct append<null, cons2>
{
    using result = cons<typename cons2::car,
                        typename append<null, typename cons2::cdr>::result>;
};
template <>
struct append<null, null>
{
    using result = null;
};

template <int index, int val, class _list>
struct change_list
{
    template <bool cond, int index, int length, class _list>
    struct if_need_null
    {
    };
    template <int index, int length, class _list>
    struct if_need_null<true, index, length, _list>
    {
        using type = null;
    };
    template <int index, int length, class _list>
    struct if_need_null<false, index, length, _list>
    {
        using type = typename copy_list<index + 1, length - 1, _list>::result;
    };
    using result = typename append<typename copy_list<0, index - 1, _list>::result,
                                   cons<num<val>,
                                        typename if_need_null<index == _list::length - 1,
                                                              index,
                                                              _list::length,
                                                              _list>::type>>::result;
};
template <int val, class _list>
struct change_list<0, val, _list>
{
    using result = typename append<null,
                                   cons<num<val>, typename copy_list<1, _list::length - 1, _list>::result>>::result;
};

template <int start, class _list>
struct copy_list<start, start, _list>
{
    using result = cons<typename find_list<start, _list>::result, null>;
};

template <class _list, int heapSize>
struct build
{
    template <int i, class _list>
    struct loop
    {
        using result = typename loop<i - 1, typename maxHeapify<_list, i, heapSize>::result>::result;
    };
    template <class _list>
    struct loop<0, _list>
    {
        using result = typename maxHeapify<_list, 0, heapSize>::result;
    };
    using result = typename loop<(heapSize / 2), _list>::result;
};

template <class _list, int heapSize>
struct sort
{
    using temp = typename build<_list, heapSize>::result;
    template <int i, class _list>
    struct loop
    {
        using temp = Swap<_list, 0, i>;
        using temp2 = typename maxHeapify<temp, 0, i>::result;
        using result = typename loop<i - 1, temp2>::result;
    };
    template <class _list>
    struct loop<1, _list>
    {
        using temp = Swap<_list, 0, 1>;
        using result = typename maxHeapify<temp, 0, 1>::result;
    };
    using result = typename loop<(heapSize - 1), _list>::result;
};

template <class _list, int index, int heapSize>
struct maxHeapify
{
    static const int left = 2 * index + 1;
    static const int right = left + 1;
    template <bool cond, int index, int num1>
    struct if_temp
    {
        static const int max = index;
    };
    template <int index, int num1>
    struct if_temp<true, index, num1>
    {
        template <bool cond, int index, int num1>
        struct if_temp2
        {
            static const int max = index;
        };
        template <int index, int num1>
        struct if_temp2<true, index, num1>
        {
            static const int max = num1;
        };
        static const int max = if_temp2<((find_list<index, _list>::result::value) < (find_list<num1, _list>::result::value)), index, num1>::max;
    };
    static const int temp_max = if_temp<(left < heapSize), index, left>::max;
    static const int maxIndex = if_temp<(right < heapSize), temp_max, right>::max;

    template <bool cond1, int maxIndex, int index, int heapSize>
    struct if_temp3
    {
    };
    template <int maxIndex, int index, int heapSize>
    struct if_temp3<false, maxIndex, index, heapSize>
    {
        using result = _list;
    };
    template <int maxIndex, int index, int heapSize>
    struct if_temp3<true, maxIndex, index, heapSize>
    {
        using temp_list = Swap<_list, maxIndex, index>;
        using result = typename maxHeapify<temp_list, maxIndex, heapSize>::result;
    };
    using result = typename if_temp3<(maxIndex != index), maxIndex, index, heapSize>::result;
};