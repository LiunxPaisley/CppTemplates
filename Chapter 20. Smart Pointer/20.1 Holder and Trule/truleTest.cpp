#include "./include/trule.h"
#include "./include/holder2.h"

class something
{
};

void read_something(something *s)
{
}

trule<something> load_something()
{
    holder<something> result(new something);
    read_something(result.get());
    return result;
}

int main()
{
    holder<something> ptr(load_something());
}