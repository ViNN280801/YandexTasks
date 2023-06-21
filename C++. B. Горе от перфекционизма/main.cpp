#include <iostream>
#include <map>
#include <vector>
#include <ranges>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>

int main()
{
    short N{};
    int X{};
    long T{};
    std::cin >> N >> X >> T;

    std::vector<int> v(N);

    for (short i{}; i < N; i++)
        std::cin >> v.at(i);

    std::map<int, int> m;
    for (short i{1}; i <= N; i++)
        m[i] = abs(v.at(i - 1) - X);

    std::vector<std::pair<int, int>> m_sorted(m.cbegin(), m.cend());
    std::ranges::sort(m_sorted, [](std::pair<int, int> a, std::pair<int, int> b)
                      { return a.second < b.second; });

    std::vector<int> sculptures;
    for (auto const &entry : m_sorted)
    {
        T -= entry.second;
        if (T >= 0)
            sculptures.push_back(entry.first);
        else
            break;
    }

    std::cout << sculptures.size() << std::endl;
    std::stringstream ss;
    for (int const &i : sculptures)
        ss << i << ' ';
    std::cout << ss.str() << std::endl;

    return EXIT_SUCCESS;
}