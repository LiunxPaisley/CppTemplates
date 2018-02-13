#ifndef COMPOSE2_H_
#define COMPOSE2_H_

template <typename FO1, typename FO2>
class Composer
{
private:
    FO1 fo1; // 要调用的第一个/内部的函数对象
    FO2 fo2; // 要调用的第二个/外部的函数对象
public:
    // 用于初始化两个函数对象的构造函数
    Composer(FO1 f1, FO2 f2)
        : fo1(f1), fo2(f2)
    {
    }

    // “函数调用”：函数对象的嵌套调用
    double operator()(double v)
    {
        return fo2(fo1(v));
    }
};

#endif // COMPOSE2_H_