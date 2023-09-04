#include <iostream>
#include <cinttypes>
#include <vector>
#include <algorithm>
#include <iterator>
#include <span>
#include <concepts>
#include <ranges>

/**
 * @brief Searches for closest element to specified in a sequence
 * @tparam range sequence in which search
 * @tparam value value to find closest for it
 * @return Closest element to specified value
 */
template <std::integral T>
constexpr T findClosest(std::span<T const> range, T value)
{
    // Make a copy of elements
    std::vector<T> sorted;
    std::ranges::copy(range, std::back_inserter(sorted));

    // Sorting elements in ascending order
    std::ranges::sort(sorted);

    // Finds the iterator pointing to the first element in the 'range'
    // that is greater than or equal to 'value'
    auto const it{std::lower_bound(std::cbegin(sorted), std::cend(sorted), value)};

    // If iterator points to the beginning of the range - return first element
    if (it == std::cbegin(sorted))
        return sorted.front();

    // If iterator points beyond the end of the range - return last element
    if (it == std::cend(sorted))
        return sorted.back();

    // Otherwise return the closest element
    return (*it - value < value - *(std::prev(it))) ? *it : *(std::prev(it));
}

int main()
{
    // Count of elements in array
    uint16_t N{};
    std::cin >> N;

    // Signed number array
    std::vector<int16_t> v(N);
    for (uint16_t i{}; i < N; i++)
        std::cin >> v.at(i);

    // Signed value
    int16_t x{};
    std::cin >> x;

    std::cout << findClosest<int16_t>(v, x) << '\n';

    return EXIT_SUCCESS;
}
