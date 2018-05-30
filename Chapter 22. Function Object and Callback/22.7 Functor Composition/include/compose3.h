#ifndef COMPOSE3_H_
#define COMPOSE3_H_

template <typename FO1, typename FO2>
class Composer : private FO1, private FO2
{
public:
    Composer(FO1 f1, FO2 f2)
        : FO1(f1), FO2(f2)
    {
    }

    double operator()(double v)
    {
        return FO2::operator()(FO1::operator()(v));
    }
};

#endif // COMPOSE3_H_