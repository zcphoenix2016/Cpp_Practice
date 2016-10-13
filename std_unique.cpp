#include <string>
#include <algorithm>
#include <iostream>

int main()
{
    std::string str{"12223455556"};

    auto end = std::unique(str.begin(), str.end(), [](char l, char r){return l == r;});

    std::cout << std::string(str.begin(), end) << std::endl;

    return 0;
}
