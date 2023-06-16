#include <iostream>
#include <limits>
#include <set>

int main()
{
    short T{}; // Count of tests
    std::cin >> T;

    for (int i{}; i < T && (T >= 1 && T <= 1000); i++)
    {
        int n{}; // Count of sunbeds
        std::cin >> n;

        std::set<int> sunbeds;
        for (int j{}; j < n && (n >= 1 && n <= 1'000'000); j++)
        {
            int x{};
            std::cin >> x;

            if (x < 0 || x > 1'000'000'000)
                return EXIT_FAILURE;

            sunbeds.insert(x);
        }

        int min{std::numeric_limits<int>::max()};
        for (auto it{sunbeds.cbegin()}; it != sunbeds.cend(); ++it)
            min = std::min(min, *it xor *(std::next(it)));
        std::cout << min << '\n';
    }

    return EXIT_SUCCESS;
}
