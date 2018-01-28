template <typename PolicySetter1 = DefaultPolicyArgs,
          typename PolicySetter2 = DefaultPolicyArgs,
          typename PolicySetter3 = DefaultPolicyArgs,
          typename PolicySetter4 = DefaultPolicyArgs>
class BreadSlicer
{
    typedef PolicySelector<PolicySetter1, PolicySetter2, PolicySetter3, PolicySetter4> Policies;
};

/**
 * PolicySelector<A,B,C,D> 生成A,B,C,D作为基类
 * Discrimnator<>使Policy Selector可以多次继承同一个基类
 */ 

template <typename Base, int D>
class Discrimnator : public Base
{
};

template <typename Setter1, typename Setter2, typename Setter3, typename Setter4>
class PolicySelector : pulibc Discrimnator<Setter1, 1>,
                       public Discrimnator<Setter2, 2>,
                       public Discrimnator<Setter3, 3>,
                       public Discrimnator<Setter4, 4>
{
};
/**
 * 分别命名缺省policies 为P1,P2,P3,P4
 */ 
class DefaultPolicy1{};
class DefaultPolicy2{};
class DefaultPolicy3{};
class DefaultPolicy4{};

class DefaultPolicies
{
public:
    typedef DefaultPolicy1 P1;
    typedef DefaultPolicy2 P2;
    typedef DefaultPolicy3 P3;
    typedef DefaultPolicy4 P4;
};

/**
 * 一个为了使用缺省policy值的类
 * 如果我们多次派生自DefaultPolicies, 下面的虚拟继承就避免了二义性
 */ 
class DefaultPolicyArgs : virtual public DefaultPolicies
{
};

template <typename Policy>
class Policy1_is : virtual public DefaultPolicies
{
public:
    typedef Policy P1;
};

template <typename Policy>
class Policy2_is : virtual public DefaultPolicies
{
public:
    typedef Policy P2;
};

template <typename Policy>
class Policy3_is : virtual public DefaultPolicies
{
public:
    typedef Policy P3;
};

template <typename Policy>
class Policy4_is : virtual public DefaultPolicies
{
public:
    typedef Policy P4;
};

int main()
{
    BreadSlicer<Policy3_is<CustomPolicy> > bc;
}