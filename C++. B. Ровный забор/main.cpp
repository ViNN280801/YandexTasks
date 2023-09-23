#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

int main()
{
    unsigned n{}, k{};
    std::cin >> n >> k;

    std::vector<unsigned> l(n);
    for (unsigned i{}; i < n; i++)
        std::cin >> l.at(i);

    std::ranges::sort(l);

    unsigned minIrregularity{l.at(n - 1) - l.at(0)};
    for (unsigned i{}; i <= k; i++)
        minIrregularity = std::min(minIrregularity, l.at(i + n - 1 - k) - l.at(i));

    std::cout << minIrregularity << '\n';

    return EXIT_SUCCESS;
}
