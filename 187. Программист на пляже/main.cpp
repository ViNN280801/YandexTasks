#include <iostream>
#include <limits>
#include <algorithm>

int main()
{
    int T{}; // Count of tests
    std::cin >> T;

    // Iterating by tests
    for (int i = 0; i < T; i++)
    {
        int n{}; // Count of sunbeds
        std::cin >> n;

        // Allocating memory for array
        int *sunbeds = new int[n];

        // Filling values of sunbeds
        for (int j{}; j < n; j++)
            std::cin >> sunbeds[j];

        std::sort(sunbeds, sunbeds + n);

        // Init minimal value with maximal integer to future comparing
        int min{std::numeric_limits<int>::max()};

        // Double loop to do XOR each to each sunbed
        // (except 1st with 1st, 2nd with 2nd, ..., nth with nth) -> because "A XOR A eq 0"
        for (int j{1}; j < n; j++)
            // Check local min (XOR between neighbours sunbeds) with global min
            min = std::min(sunbeds[j] xor sunbeds[j - 1], min);

        // Outputting result
        std::cout << min << std::endl;

        // Check if pointer do not contain "nullptr" to avoid deallocating it
        if (sunbeds)
        {
            delete[] sunbeds;
            sunbeds = nullptr;
        }
    }

    return EXIT_SUCCESS;
}
