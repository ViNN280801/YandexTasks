#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

int main()
{
    // Count of offers and count of potential customers
    int offers{}, customers{};
    std::cin >> offers >> customers;

    // Prices at which sellers are willing to sell chairs
    std::vector<int> prices(offers);

    // Filling prices
    for (int i{}; i < offers; i++)
        std::cin >> prices.at(i);

    // Amounts that potential buyers are willing to give when buying a chair
    std::vector<int> amounts(customers);

    // Filling amounts
    for (int i{}; i < customers; i++)
        std::cin >> amounts.at(i);

    std::ranges::sort(prices, std::less<int>());
    std::ranges::sort(amounts, std::greater<int>());

    ulong result{};
    size_t min{std::min(prices.size(), amounts.size())};

    for (size_t i{}; i < min; i++)
    {
        int benefit{amounts.at(i) - prices.at(i)};
        if (benefit > 0)
            result += benefit;
    }

    std::cout << result << '\n';

    return EXIT_SUCCESS;
}
