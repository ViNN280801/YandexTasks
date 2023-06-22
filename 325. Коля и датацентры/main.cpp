#include <iostream>
#include <vector>
#include <string>
#include <ranges>
#include <algorithm>
#include <iterator>

int main()
{
    // Count of datacenters, servers and events respectively
    int n{}, m{}, q{};
    std::cin >> n >> m >> q;

    std::vector<std::vector<int>> dc(n, std::vector<int>(m, 1));
    std::vector<int> dr(m, 0);

    while (q--)
    {
        std::string event;
        std::cin >> event;

        if (event == "RESET")
        {
            // i-th datacenter
            int i{};
            std::cin >> i;

            dc.at(i - 1) = std::vector<int>(m, 1);
            dr.at(i - 1) += 1;
        }
        else if (event == "DISABLE")
        {
            // i-th datacenter, j-th server
            int i{}, j{};
            std::cin >> i >> j;

            dc.at(i - 1).at(j - 1) = 0;
        }
        else if (event == "GETMAX")
        {
            auto max_index{std::distance(dr.begin(), std::max_element(dr.begin(), dr.end()))};
            int max_val{};
            for (int i{}; i < n; i++)
            {
                auto count{std::ranges::count(dc.at(i), 1)};
                if (dr.at(i) * count > max_val)
                {
                    max_val = dr.at(i) * count;
                    max_index = i;
                }
            }
            std::cout << max_index + 1 << '\n';
        }
        else if (event == "GETMIN")
        {
            auto res{std::ranges::min_element(dr) - dr.cbegin()};
            if (std::ranges::count(dr, 1) == m)
                res++;
            std::cout << res << '\n';
        }
        else
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
