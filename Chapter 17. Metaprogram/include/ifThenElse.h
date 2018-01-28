#ifndef _IFTHENELSE_H_
#define _IFTHENELSE_H_

// 基本模板
template <bool C, typename Ta, typename Tb>
class ifThenElse;

// 局部特化
template <typename Ta, typename Tb>
class ifThenElse<true, Ta, Tb>
{
public:
    typedef Ta ResultT;
};

template <typename Ta, typename Tb>
class ifThenElse<false, Ta, Tb>
{
public:
    typedef Tb ResultT;
};

#endif // !_IFTHENELSE_H_