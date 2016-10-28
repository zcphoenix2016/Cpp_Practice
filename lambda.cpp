#include <iostream>
#include <functional>

void plus_f(int& i, int &j)
{
    i ++;
    j ++;
}

class Plus_c
{
public:
    Plus_c(int &i) : m_i(i)
    {
    }

    void operator()(int &j)
    {
        m_i ++;
        j ++;
    }

private:
    int& m_i;
};

int main()
{

    int a = 0;
    int b = 0;

    std::cout << "a = " << a << ", b = " << b << std::endl;
    plus_f(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;

    //auto plus_l = [&a](int &b){a ++;b ++;};
    std::function<void(int&)> plus_l = [&a](int &b){a ++;b ++;};
    plus_l(b);
    std::cout << "a = " << a << ", b = " << b <<  std::endl;

    Plus_c plus_c(a);
    plus_c(b);
    std::cout << "a = " << a << ", b = " << b <<  std::endl;

    return 0;
}
