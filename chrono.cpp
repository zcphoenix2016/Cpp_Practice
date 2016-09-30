#include <chrono>
#include <iostream>
#include <ctime>
#include <iomanip>

int main()
{
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::cout << std::put_time(std::localtime(&t), "%c %Z") << std::endl;

    return 0;
}
