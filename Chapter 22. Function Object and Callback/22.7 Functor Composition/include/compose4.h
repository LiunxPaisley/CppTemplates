#ifndef COMPOSE4_H_
#define COMPOSE4_H_

template <typename C, int N>
class BaseMem : public C
{
public:
    BaseMem(C &c) : C(c) {}
    BaseMem(const C &c) : C(c) {}
};

template <typename FO1, typename FO2>
class Composer : private BaseMem<FO1, 1>, private BaseMem<FO2, 2>
{
public:
    Composer(FO1 f1, FO2 f2)
        : BaseMem<FO1, 1>(f1), BaseMem<FO2, 2>(f2)
    {
    }

    double operator()(double v)
    {
        return BaseMem<FO1, 1>::operator()(BaseMem<FO2, 2>::operator()(v));
    }
};

#endif // COMPOSE4_H_