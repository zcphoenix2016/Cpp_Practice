#include <string>
#include <algorithm>
#include <iostream>

int main()
{
    std::string str{"12223455556"};

    auto sameChar = [](char l, char r){return l == r;};
    str.erase(std::unique(str.begin(), str.end(), sameChar), str.end());

    std::cout << str << std::endl;

    return 0;
}
