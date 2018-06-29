#include <stdio.h>
#include <random.h>
#include <time.h>

template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    b      = a;
    a      = temp;
}

template <int i, int j, int x, typename T>
int partitionLoop(T* data)
{
    if(data[j] <= data[x])
    {
        swap(data[i], data[j]);
        return partitionLoop<i+1, j-1, x>(data);
    }
    else
    {
        return partitionLoop<i, j-1, x>(data);
    }
    
}

// j = 0的时候返回i
template <int i, int x, typename T>
int partitionLoop<i, 0, x, T>
{
    swap(data[i], data[x]);
    return i;
}

template <int a, int b, typename T>
int partition(T* data)
{
    partitionLoop<a, b-1, b>(data);
}



template <int a, int b, typename T>
void quicksort(T* data)
{
    int p = partition<a, b>(data);
    quicksort<a, p>(data);
    quicksort<p, b>(data);
}

template <int a, typename T>
void quicksort<a, a>()
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