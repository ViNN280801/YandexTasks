#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

int solution()
{
    int n{}, k{};
    std::cin >> n >> k;

    std::vector<int> arr(n);

    for (int i{}; i < n; i++)
        std::cin >> arr.at(i);

    int ans{*std::ranges::max_element(arr)};

    if (ans <= 0)
        return ans;

    std::vector<std::vector<int>> vecl(n + 2ul, std::vector<int>(k + 2ul, 0));
    std::vector<std::vector<int>> vecr(n + 2ul, std::vector<int>(k + 2ul, 0));

    for (int i{1}; i <= n; i++)
    {
        for (int j{}; j <= k; j++)
        {
            vecl[i][j] = std::max(0, vecl[i - 1][j] + arr.at(i - 1));
            if (j != 0)
                vecl[i][j] = std::max(vecl[i][j], vecl[i - 1][j - 1]);
            ans = std::max(ans, vecl[i][j]);
        }
    }

    for (int i{1}; i <= n; i++)
    {
        for (int j{}; j <= k; j++)
        {
            vecl[i][j] = vecl[i - 1][j] + arr.at(i - 1);
            if (j != 0)
                vecl[i][j] = std::max(vecl[i][j], vecl[i - 1][j - 1]);
        }
    }

    for (int i{n}; i >= 1; i--)
    {
        for (int j{}; j <= k; j++)
        {
            vecr[i][j] = vecr[i + 1][j] + arr.at(i - 1);
            if (j != 0)
                vecr[i][j] = std::max(vecr[i][j], vecr[i + 1][j - 1]);
        }
    }

    for (int i{1}; i <= n; i++)
    {
        for (int j{}; j <= k; j++)
        {
            if (i != 1)
                vecl[i][j] = std::max(vecl[i][j], vecl[i - 1][j]);
            if (j != 0)
                vecl[i][j] = std::max(vecl[i][j], vecl[i][j - 1]);
        }
    }

    for (int i{n}; i >= 1; i--)
    {
        for (int j{}; j <= k; j++)
        {
            if (i != n)
                vecr[i][j] = std::max(vecr[i][j], vecr[i + 1][j]);
            if (j != 0)
                vecr[i][j] = std::max(vecr[i][j], vecr[i][j - 1]);
        }
    }

    for (int i{1}; i < n; i++)
        for (int j{}; j <= k; j++)
            ans = std::max(ans, vecl[i][j] + vecr[i + 1][k - j]);

    return ans;
}

int main()
{
    int t{};
    std::cin >> t;

    std::vector<int> ans;
    for (int i{}; i < t; i++)
        ans.emplace_back(solution());

    for (auto const &a : ans)
        std::cout << a << '\n';

    return EXIT_SUCCESS;
}
