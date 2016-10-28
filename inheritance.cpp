#include <iostream>

class CBase
{
public:
    void print()
    {
        std::cout << "CBase::print()" << std::endl;
    }
    int m_x = 0;
};

//class CDerived : CBase
//-- private inherit by default
class CDerived : public CBase
{
public:
    void print()
    {
        std::cout << "CDerived::print()" << std::endl;
    }
};

class CcDerived : public CDerived
{
};

//struct SDerived : private CBase
//-- public inherit by default
struct SDerived : CBase
{
};

int main()
{
    CDerived cd;
    std::cout << "CDerived::m_x: " << cd.m_x << std::endl;

    SDerived sd;
    std::cout << "SDerived::m_x: " << sd.m_x << std::endl;

    CcDerived cc;
    cc.print();//CDerived::print() will be invoked here.

    return 0;
}
