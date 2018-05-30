#include <cstdlib>
#include <iostream>
#include <vector>

// 用于把函数指针封装成函数对象的封装类
template <int (*FP)()>
class FunctionReturningIntWrapper
{
public:
    int operator()()
    {
        return FP();
    }
};

// 要进行封装的函数实例
int random_int()
{
    return std::rand(); // 调用标准的c函数
}

// 客户端，它使用由模板参数传递进来的函数对象类型
template <typename FO>
void initialize(std::vector<int> &coll)
{
    FO fo; // 创建函数对象
    for(std::vector<int>::size_type i = 0; i < coll.size(); ++i)
    {
        coll[i] = fo(); // 调用由函数对象表示的函数
    }
}

int main()
{
    // 创建含有10个元素的vector
    std::vector<int> v(10);
    for(std::vector<int>::size_type i = 0; i < v.size(); ++i)
    {
        std::cout << "coll[" << i << "]: " << v[i] << std::endl;
    }
    // 用封装函数来重新初始化vector的值
    initialize<FunctionReturningIntWrapper<random_int>>(v);
    std::cout << "\nAfter initialize:" << std::endl;
    // 输出vector中的值
    for(std::vector<int>::size_type i = 0; i < v.size(); ++i)
    {
        std::cout << "coll[" << i << "]: " << v[i] << std::endl;
    }
}