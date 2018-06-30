#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * 把快速排序的partition内的循环展开：
 * 1. 抽出循环内的部分
 * 2. 用递归代替循环
 * 3. 用?:运算符判断递归结束，结束则传入0
 */

template <int i, int j, int b>
int quickSortSwap(T* data)
{
    if(data[j] < data[b])
    {
        T temp = data[i];
        data[i] = data[j];
        data[j] = temp;
        return i+1;
    }
    if(j == b)
    {
        T temp = data[i+1];
        data[i+1] = data[b];
        data[b] = temp;
        return i+1;
    }
    return i;
}

// 函数模板不能偏特化，在传入模板的非类型参数时，只选择能“推导的有限的”参数
template <int i, int j, int a, int b, typename T>
int partitionLoop(T* data)
{
    // 从后往前遍历，比data[x]大的数字放后面
    int k = quickSortSwap<i, j, b>(data);
    partitionLoop<j<b?k:0, j<b?j+1:0, j<b?a:0, j<b?b:0>(data);
}

// j = 0的时候返回i
template <>
int partitionLoop<0, 0, 0, 0>(T* data)
{
    // swap(data[i], data[x]);
    // return i;
}

template <int a, int b, typename T>
int partition(T* data)
{
    int i = partitionLoop<a, a, a, b>(data);

}


template <int a, int b, typename T>
void quicksort(T* data)
{
    int p = partition<a, b>(data);
    quicksort<a, p>(data);
    quicksort<p, b>(data);
}

template <int a, typename T>
void quicksort<a, a>(T* data)
{
}

int main()
{
    const int num = 10;
    const int a   = -50;
    const int b   = 50;
    float     data[num];

    printf("Before sort, data = ");
    srand(static_cast<unsigned int>(time(NULL)));
    for (size_t i = 0; i < num; i++)
    {
        data[i] = rand() * ((b - a) / RAND_MAX) + a;
        printf("lf% ", data[i]);
    }
    printf("\n");

    quicksort<num>(data);

    printf("After sort, data = ");
    for (size_t j = 0; j < num; j++)
    {
        printf("lf% ", data[j]);
    }
    printf("\n");
}