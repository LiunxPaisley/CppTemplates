#ifndef IF_THEN_ELSE_H_
#define IF_THEN_ELSE_H_

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

#endif // IF_THEN_ELSE_H_