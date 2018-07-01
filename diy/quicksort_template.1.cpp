#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * 把快速排序的partition内的循环展开：
 * 1. 抽出循环内的部分
 * 2. 用递归代替循环
 * 3. 用?:运算符判断递归结束，结束则传入0
 */
template <bool b>
struct compare{

};

template <>
struct compare<true>
{
    enum {value = 1};
};

template <>
struct compare<false>
{
    enum {value = 0};
};

template <bool b, int i, int j>
struct swap
{
//    void operator()(float* data)
//    {
//        if(data[j] < data[x])
//        {
//            T temp = data[j];
//            data[j] = data[i];
//            data[i] = temp;
//        }
//    }
};
template <int i, int j>
struct swap<true, i, j>
{
    //enum {value = i+1};
    static int ret(float* data)
    {
        float temp = data[j];
        data[j] = data[i];
        data[i] = temp;
        return i+1;
    }
};

template <int i, int j>
struct swap<false, i, j>
{
//    enum {value = i};
    static int ret(float* data)
    {
        return i;
    }
};

template <bool b, int i, int j, int x>
struct partitionLoop
{
};

template <int i, int j, int x>
struct partitionLoop<true, i, j, x>
{
//    enum {value = };
    static int ret(float* data)
    {
        int i_swap = swap<data[j]<data[x], i, j>::ret(data);
//        int i_swap = swap<data[j]<data[x], i, j>::value;
        return partitionLoop<j+1<x, i_swap, j+1, x>::ret(data);
    }
};

template <int i, int j, int x>
struct partitionLoop<false, i, j, x>
{
    static int ret(float* data) {
        return swap<data[j]<data[x], i, j>::ret(data);
    }
};

template <int a, int b>
struct partition
{
    //enum {i = a - 1, j = 0};
    static int ret(float* data)
    {
        return partitionLoop<true, a, a, b>::ret(data);
    }
};

template <int a, int b>
struct quickSort
{
    //enum { i = a - 1, j = 0};
    static void func(float* data)
    {
        const int p = partition<a, b>::ret(data);
        quickSort<a, p>::func(data);
        quickSort<p, b>::func(data);
    }
};

int main()
{
    const int num = 10;
    const int a   = -50;
    const int b   = 50;
    float     data[num] = {7.4, 9.6, 8.3, 4.2, 5.1, 3.3, 1.9, 2.7, 3.7, 5.0};

    printf("Before sort, data = ");
//    srand(static_cast<unsigned int>(time(NULL)));
    for (size_t i = 0; i < num; i++)
    {
//        data[i] = rand() * ((b - a) / RAND_MAX) + a;
        printf("%lf ", data[i]);
    }
    printf("\n");

    quickSort<0, num - 1>::func(data);

    printf("After sort, data = ");
    for (size_t j = 0; j < num; j++)
    {
        printf("%lf ", data[j]);
    }
    printf("\n");
}