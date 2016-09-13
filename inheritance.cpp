#include <iostream>

class CBase
{
public:
    int m_x = 0;
};

//class CDerived : CBase
//-- private inherit by default
class CDerived : public CBase
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
    cd.m_x;

    SDerived sd;
    sd.m_x;

    return 0;
}
