#include <iostream>
#include <string>
#include <limits>
#include <vector>

using ll = long long;
using ld = long double;
using intvector = std::vector<int>;
using llvector = std::vector<ll>;
using llmatrix = std::vector<llvector>;

static constexpr int maxsizeN{100 * 1000 + 227};
static constexpr int maxsizeK{105};

void solution(intvector &vec, llmatrix &vecl, llmatrix &vecr)
{
    int n{}, k{};
    std::cin >> n >> k;

    ll result{-std::numeric_limits<ll>::max()};
    for (int i{}; i < n; i++)
    {
        std::cin >> vec[i];
        result = std::max(result, (ll)vec[i]);
    }

    if (result <= 0)
    {
        std::cout << result << '\n';
        return;
    }

    for (int i{}; i <= k; i++)
    {
        vecl[n + 1][i] = 0;
        vecr[n + 1][i] = 0;
    }

    for (int i{1}; i <= n; i++)
    {
        for (int j{}; j <= k; j++)
        {
            vecl[i][j] = std::max(0ll, vecl[i - 1][j] + vec[i - 1]);
            if (j != 0)
                vecl[i][j] = std::max(vecl[i][j], vecl[i - 1][j - 1]);
            result = std::max(result, vecl[i][j]);
        }
    }

    for (int i{1}; i <= n; i++)
    {
        for (int j{}; j <= k; j++)
        {
            vecl[i][j] = vecl[i - 1][j] + vec[i - 1];
            if (j != 0)
                vecl[i][j] = std::max(vecl[i][j], vecl[i - 1][j - 1]);
        }
    }

    for (int i{n}; i >= 1; i--)
    {
        for (int j{}; j <= k; j++)
        {
            vecr[i][j] = vecr[i + 1][j] + vec[i - 1];
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
            result = std::max(result, vecl[i][j] + vecr[i + 1][k - j]);

    std::cout << result << '\n';
}

int main()
{
    int t{};
    std::cin >> t;

    intvector vec(maxsizeN);
    llmatrix vecl(maxsizeN, llvector(maxsizeK, 0));
    llmatrix vecr(maxsizeN, llvector(maxsizeK, 0));

    while (t--)
        solution(vec, vecl, vecr);

    return EXIT_SUCCESS;
}
