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
template <int a, int b, typename T>
void partition(T* data)
{
    size_t i = a;
    size_t j = b;
    T x = 
    for ()
    {

    }
        partition<a, (a + b) / 2>(data);
    partition<(a + b) / 2, b>(data);
}

template <int a, typename T>
void partition<a, a>()
{
}

template <int num, typename T>
void quicksort(T* data)
{
    partition<0, num>(data);
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