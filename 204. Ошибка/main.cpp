#include <iostream> // For standard input/output
#include <iomanip>  // For set precision of "double" type
#include <vector>

int main()
{
    // Count of servers (1 <= n <= 100)
    ushort n{};
    std::cin >> n;

    // Reserving space for 'n' servers
    std::vector<ushort> probabilities(n);

    // Probability that error occurs on accordingly server
    ushort totalProbability{};

    // Filling 'n' probabilities
    for (ushort i{}; i < n; i++)
    {
        // 'a' - the probability that the request will go to the i-th server in percents (0 <= a <= 100)
        // 'b' - the probability that an error will occur on the i-th server in percents (0 <= b <= 100)
        // It's guaranteed that sum of all 'a_i' = 100%
        ushort a{}, b{};
        std::cin >> a >> b;

        // Adding probability of an error to the vector of probabilities
        probabilities.at(i) = a * b;

        // Calculating total probability as sum of elements all probabilities
        totalProbability += probabilities.at(i);
    }

    // Outputting result
    for (ushort i{}; i < n; i++)
        std::cout << std::fixed << std::setprecision(12)
                  << static_cast<double>(probabilities.at(i)) / totalProbability << '\n';

    return EXIT_SUCCESS;
}
