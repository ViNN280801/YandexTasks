#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

int main()
{
    // Count of keys
    int N{};
    std::cin >> N;

    std::vector<int> c_i(N);
    for (int i{}; i < N; i++)
        std::cin >> c_i.at(i);

    std::vector<int> r_j(N);
    for (int j{}; j < N; j++)
        std::cin >> r_j.at(j);

    // Count of symbols in the text
    int K{};
    std::cin >> K;

    std::vector<int> s_j(K);
    for (int j{}; j < K; j++)
        std::cin >> s_j.at(j);

    // Filling hash map
    std::unordered_map<int, int> m;
    for (int i{}; i < N; i++)
        m[c_i[i]] = r_j[i];

    int rowCounter{};
    for (size_t i{0}; i < s_j.size() - 1UL; i++)
        rowCounter = (m.at(s_j.at(i)) != m.at(s_j.at(i + 1UL))) ? rowCounter + 1 : rowCounter;

    std::cout << rowCounter << std::endl;

    return EXIT_SUCCESS;
}
