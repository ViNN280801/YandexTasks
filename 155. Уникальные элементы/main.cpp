#include <iostream>
#include <unordered_map>
#include <ranges>
#include <algorithm>

int main()
{
    int n{};
    std::cin >> n;

    std::unordered_map<int, int> m;
    for (int i{}; i < n; i++)
    {
        int num;
        std::cin >> num;
        m[num]++;
    }

    std::cout << std::ranges::count_if(m, [](auto const &mp)
                                       { return mp.second == 1; })
              << std::endl;

    return EXIT_SUCCESS;
}
