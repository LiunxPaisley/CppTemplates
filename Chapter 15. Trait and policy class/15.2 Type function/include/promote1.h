#ifndef _PROMOTE1_H_
#define _PROMOTE1_H_

template <typename T1, typename T2>
class promotion
{
public:
    typedef typename ifThenElse<(sizeof(T1) > sizeof(T2)),
                                T1,
                                typename ifThenElse<(sizeof(T1) < sizeof(T2)),
                                                    T2,
                                                    void>::ResultT>::ResultT ResultT;
};

#endif