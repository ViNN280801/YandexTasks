#include <iostream>
#include <limits>
#include <set>

int main()
{
    short T{}; // Count of tests
    std::cin >> T;

    for (int i{}; i < T; i++)
    {
        int n{}; // Count of sunbeds
        std::cin >> n;

        std::set<int> sunbeds;
        for (int j{}; j < n; j++)
        {
            int x{};
            std::cin >> x;
            sunbeds.insert(x);
        }

        int min{std::numeric_limits<int>::max()};
        for (auto it{std::next(sunbeds.cbegin())}; it != sunbeds.cend(); ++it)
            min = std::min(min, *it xor *(std::prev(it)));
        std::cout << min << '\n';
    }

    return EXIT_SUCCESS;
}
