#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

int main()
{
    int N{}, X{}, T{};
    std::cin >> N >> X >> T;

    std::vector<int> v(N);

    for (int i{}; i < N; i++)
        std::cin >> v.at(i);

    std::map<int, int> m;

    for (int i{}; i < N; i++)
        m[i + 1] = abs(v.at(i) - X);

    std::vector<std::pair<int, int>> m_sorted;
    for (auto it = m.begin(); it != m.end(); it++)
        m_sorted.push_back(std::make_pair(it->first, it->second));

    std::sort(m_sorted.begin(), m_sorted.end(), [](std::pair<int, int> a, std::pair<int, int> b)
              { return a.second < b.second; });

    std::vector<int> sculptures;
    for (auto it{m_sorted.begin()}; it != m_sorted.end(); ++it)
    {
        T -= it->second;
        if (T >= 0)
            sculptures.push_back(it->first);
        else
            break;
    }

    std::cout << sculptures.size() << std::endl;
    std::string s("");
    for (size_t i{}; i < sculptures.size(); i++)
        s += std::to_string(sculptures.at(i)) + " ";
    std::cout << s << std::endl;

    return EXIT_SUCCESS;
}