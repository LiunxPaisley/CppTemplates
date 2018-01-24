#ifndef _ACCUMTRAITS4_H_
#define _ACCUMTRAITS4_H_

/**
 * 用于告知编译器所需要模板参数的信息
 */ 

template <typename T>
class AccumulationTraits;

template <>
class AccumulationTraits<char>
{
public:
    typedef int AccT;
    static AccT zero()
    {
        return 0;
    }
};

template <>
class AccumulationTraits<short>
{
public:
    typedef int AccT;
    static AccT zero()
    {
        return 0;
    }
};

template <>
class AccumulationTraits<int>
{
public:
    typedef long AccT;
    static AccT zero()
    {
        return 0;
    }
};

template <>
class AccumulationTraits<unsigned int>
{
public:
    typedef unsigned long AccT;
    static AccT zero()
    {
        return 0;
    }
};

template <>
class AccumulationTraits<float>
{
public:
    typedef double AccT;
    static AccT zero()
    {
        return 0;
    }
};


#endif // !_ACCUMTRAITS4_H_