#include <iostream>
#include <string>
#include <iterator>
#include <ranges>
#include <algorithm>
#include <concepts>
s
/**
 * @brief Checks bounds of the number
 * @param num number to check
 * @param lower lower bound
 * @param upper upper bound
 */
constexpr bool isInBounds(std::unsigned_integral auto num__,
                          std::unsigned_integral auto lower__,
                          std::unsigned_integral auto upper__) { return num__ > lower__ && num__ <= upper__; }

int main()
{
    /**
     * @var n - Count of digits (1 < n <= 1000)
     * @var d - Number system (1 < d <= 10)
     * @var k - Count of digits to remove (1 <= k < n)
     */
    unsigned short n{}, d{}, k{};
    std::cin >> n >> d >> k;

    if (!isInBounds(n, 1U, 1000U) && !isInBounds(d, 1U, 10U) && !(k >= 1 && k < n))
        exit(EXIT_FAILURE);

    if (k > n)
        exit(EXIT_FAILURE);

    // Accepting string with simple 'cin'
    std::string number("");
    std::cin >> number;

    for (short i{}; i < k; i++)
    {
        auto it{std::ranges::min_element(number)};
        if (it != std::cend(number))
            number.erase(it);
    }

    std::cout << number << std::endl;

    return EXIT_SUCCESS;
}
