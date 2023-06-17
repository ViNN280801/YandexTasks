#include <iostream>
#include <unordered_map>

template <typename T>
constexpr T mostFreqElem(std::unordered_map<T, int> range)
{
    int max_idx{};
    T max_elem{};

    for (auto it{range.cbegin()}; it != range.cend(); ++it)
    {
        if (max_idx < it->second)
        {
            max_idx = it->second;
            max_elem = it->first;
        }
        if (max_idx == it->second)
            if (max_elem < it->first)
                max_elem = it->first;
    }

    return max_elem;
}

int main()
{
    int n{};
    std::cin >> n;

    std::unordered_map<long, int> m;
    for (int i{}; i < n; i++)
    {
        long num{};
        std::cin >> num;
        m[num] = m.count(num) ? m[num] + 1 : 1;
    }

    std::cout << mostFreqElem(m) << '\n';

    return EXIT_SUCCESS;
}
