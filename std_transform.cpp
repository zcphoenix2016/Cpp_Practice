#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

class Lower
{
public:
    unsigned char operator()(unsigned char c)
    {
        return std::tolower(c);
    }
};

class Upper
{
public:
    unsigned char operator()(unsigned char c)
    {
        return std::toupper(c);
    }
};

int main()
{
    std::string str{"Hello WOrld!!!"};
    std::string lower_l(str.size(), ' ');
    std::string lower_c(str.size(), ' ');
    std::string upper_l(str.size(), ' ');
    std::string upper_c(str.size(), ' ');

    std::transform(str.begin(), str.end(), lower_l.begin(), [](unsigned char c){return std::tolower(c);});
    std::transform(str.begin(), str.end(), lower_c.begin(), Lower());
    std::transform(str.begin(), str.end(), upper_l.begin(), [=](unsigned char c){return std::toupper(c);});
    std::transform(str.begin(), str.end(), upper_c.begin(), Upper());

    std::cout << "original string   : "   << str 
              << "\nlower with lambda : " << lower_l 
              << "\nlower with functor: " << lower_c 
              << "\nupper with lambda : " << upper_l 
              << "\nupper with functor: " << upper_c 
              << std::endl;

    return 0;
}
