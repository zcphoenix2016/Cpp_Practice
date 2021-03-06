#include <iostream>
#include <bitset>

int main()
{
    std::bitset<13> b1("1111110100000");

    size_t idx = 0;
    while (idx < b1.size() && !b1.test(idx)) {
      ++idx;
    }

    if (idx < b1.size()) {
        std::cout << "first set bit at index " << idx << '\n';
    } else {
        std::cout << "no set bits\n";
    }
}
