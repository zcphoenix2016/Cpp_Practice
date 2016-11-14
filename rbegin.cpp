#include <vector>
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <list>

int main()
{
    std::vector<int> vec{1, 2, 3, 4, 5};
    auto iter = vec.rbegin();

    while(iter not_eq vec.rend())
    {
        std::cout << *iter << std::endl;
        iter ++;
    }

    std::list<int> list{1, 2, 3};
    std::for_each(list.rbegin(), list.rend(), [](const int& num){std::cout << num << std::endl;});
    //list.insert(static_cast<std::list<int>::iterator>(list.rbegin()), 0);

    std::cout << "------------------std::list-----------------------" << std::endl;
    std::list<int> l{1, 2, 3, 4, 5};
    auto liter = l.begin();
    std::cout << "Original begin: " << *liter << std::endl;
    l.push_front(10);
    std::cout << "Original begin after push_front: " << *liter << std::endl;
    std::cout << "New begin after push_front: " << *(l.begin()) << std::endl;
    l.insert(liter, 2);
    l.erase(++ liter);

    std::for_each(l.begin(), l.end(), [](int i){std::cout << i << std::endl;});
    return 0;
}
