#include <iostream>
#include <numeric>

constexpr std::string solution(long x, long y)
{
    if (y % x)
        return "0";

    y /= x;

    long count{};
    for (long i{1}; i * i <= y; i++)
        if (y % i == 0 and std::gcd(i, y / i) == 1)
            count += 1 + (i * i != y);

    return std::to_string(count);
}

int main()
{
    long x{}, y{};
    std::cin >> x >> y;
    std::cout << solution(x, y) << std::endl;
    return EXIT_SUCCESS;
}
