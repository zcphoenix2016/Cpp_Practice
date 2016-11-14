#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <map>

int main()
{
    std::string typedef string;

    std::vector<string> vec{"N", "N", "N", "N", "B"};
    std::copy(vec.rbegin(), vec.rend(), std::ostream_iterator<string>(std::cout, "X"));
    std::cout << "\n----------------------" << std::endl;

    std::map<int, string> m;
    m.insert(std::make_pair(1, "a"));
    m.insert(std::make_pair(1, "b"));
    auto iter = m.begin();
    while(iter != m.end())
    {
        std::cout << "(" << iter->first << ", " << iter->second << ")" << std::endl;
        iter ++;
    }

    return 0;
}
